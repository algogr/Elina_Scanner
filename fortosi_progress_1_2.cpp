/*
    Elina Scanner Inventory Management
    Copyright (C) 2012 Dimitris Paraschou

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */
#include "fortosi_progress_1_2.h"
#include "fortosi_progress_1.h"
#include "stdio.h"
#include <iostream>
using namespace std;

fortosi_progress_1_2::fortosi_progress_1_2(QWidget *parent, QString fid) :
	QDialog(parent) {

	ui.setupUi(this);
	QHostAddress addr((QString) SVR_HOST);
	disable_controls();
    client = new AlgoTcpSocket(addr, 8889);
    client->connectToHost();
	QString ipath = (QString) APATH + "/img/app.png";
	QIcon *icon = new QIcon(ipath);
	in.setDevice(client);
	in.setVersion(QDataStream::Qt_4_1);
	this->setWindowIcon(*icon);
	fortosi_id = fid;

	nextblocksize = 0;
	r = 0;

	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setColumnCount(1);
	ui.tableWidget->setColumnWidth(0, 200);
	ui.pushDelete->setEnabled(FALSE);

	ui.pushCancel->setFocusPolicy(Qt::NoFocus);
	ui.finalPush->setFocusPolicy(Qt::NoFocus);
	ui.pushDelete->setFocusPolicy(Qt::NoFocus);
	ui.tempPush->setFocusPolicy(Qt::NoFocus);
	ui.pushCheck->setFocusPolicy(Qt::NoFocus);


	connect(ui.lineScan, SIGNAL(returnPressed()), this, SLOT(scan()));
	connect(ui.finalPush, SIGNAL(clicked()), this, SLOT(finalize()));
	connect(ui.tempPush, SIGNAL(clicked()), this, SLOT(temporary()));
	connect(ui.pushCancel, SIGNAL(clicked()), this, SLOT(back()));
	//connect(ui.tableWidget, SIGNAL(cellClicked(int row,int column)), this, SLOT(cellclicked()));
	connect(ui.pushDelete, SIGNAL(clicked()), this, SLOT(delrow()));
	connect(ui.tableWidget, SIGNAL(pressed(const QModelIndex &)), this,
			SLOT(cellclicked()));

	connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
	connect(ui.pushCheck, SIGNAL(clicked()), this, SLOT(check()));


	requestFortosi();

}

fortosi_progress_1_2::~fortosi_progress_1_2() {
	client->disconnectFromHost();

}

void fortosi_progress_1_2::startread() {

	qDebug() << "MPIKA";

	forever {
		ff: if (nextblocksize == 0) {

			if (client->bytesAvailable() < sizeof(quint16))
				break;
			in >> nextblocksize;

		}

		if (nextblocksize == 0xFFFF) {
			nextblocksize = 0;
			if (readmode == 2) {
				readmode = 0;
				QMessageBox m;
				QString mtext;
				if (reply.isEmpty() == FALSE) {
					mtext = reply.join("\n");
					m.setText(mtext);
					m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
				} else {
					m.setText(trUtf8("Η προφόρτωση ταυτίζεται με την φόρτωση"));

				}
				m.setStandardButtons(QMessageBox::Ok);
				m.move(0, 0);
				//QFont serifFont("Times", 18, QFont::Bold);
				//m.setFont(serifFont);
				m.exec();
				reply.clear();
				goto ff;
			} else if (readmode == 1) {
				readmode = 0;
				goto ff;
			} else
			{
				return;

			}


			//client->close();

		}

		if (client->bytesAvailable() < nextblocksize)
			break;
		QString type;
		in >> type;
		qDebug() << "MPIKA KAI EDO:" << type;

		if (type == "RS") {
			QString cname = "";
			QString code_t, sweight, type,packet;
            in >> cname >> code_t >> sweight >> packet;
            qDebug()<<cname<< code_t << sweight<<packet;
			ui.labelCustomer->setText(cname);
			customer = cname;
			ui.labelWeight->setText(sweight);
			weight = sweight.toInt();
			QTableWidgetItem *a = new QTableWidgetItem;
            a->setFlags(a->flags() ^ Qt::ItemIsEditable);

			a->setText(code_t);

            //a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

			ui.tableWidget->setRowCount(r + 1);
			ui.tableWidget->setItem(r, 0, a);
			QVariant pc = ui.tableWidget->rowCount();
			ui.labelPieces->setText(pc.toString());
			r++;
			enable_controls();
			//qDebug() << req_type;
			nextblocksize = 0;
		}

		if (type == "CHKC") {

			QString code_t, problem;
			in >> code_t >> problem;
			readmode = 1;
			if (code_t == "99999") {
				enable_controls();
				QMessageBox m;
				QString mtext;
				m.setText(trUtf8("Ο έλεγχος ολοκληρωθηκε!"));
				m.setStandardButtons(QMessageBox::Ok);
				m.move(100, 100);
				m.exec();

			}
			qDebug() << "MIKA KAI EDO:" << ui.tableWidget->rowCount();
			for (int i = 0; i < ui.tableWidget->rowCount(); ++i) {
				qDebug() << "CODE_T:" << code_t << " TABLE:"
						<< ui.tableWidget->item(i, 0)->text();
				if (ui.tableWidget->item(i, 0)->text() == code_t) {
					qDebug() << "PRBLEM:" << problem;
					if (problem == "0")
						ui.tableWidget->item(i, 0)->setBackgroundColor(Qt::red);
					if (problem == "1")
						ui.tableWidget->item(i, 0)->setBackgroundColor(Qt::gray);
					//break;
				}

			}
			nextblocksize = 0;
		}


		if (type =="IFI")
		{
            //client->disconnectFromHost();

            //client->deleteLater();
            //fortosi_progress_1 *w=(fortosi_progress_1 *)parent();

            //w->requestFortoseis();

            //delete(w);
            delete(this);

		}
		nextblocksize = 0;
	}

}

void fortosi_progress_1_2::requestFortosi() {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "RS";
	out << quint16(0) << req_type << QString(fortosi_id);
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
}

void fortosi_progress_1_2::back() {
	delete (this);
}

void fortosi_progress_1_2::scan() {
    ui.pushDelete->setEnabled(FALSE);
	QString scanned = ui.lineScan->text();
	QRegExp kt("\\d{12,12}[X-Z]\\d{2,2}");
	for (int i = 0; i < ui.tableWidget->rowCount(); ++i) {
			if (ui.tableWidget->item(i, 0)->text() == scanned) {
				QMessageBox m;
				QSound::play("bell.wav");
				m.setText(trUtf8("O K/T έχει ήδη διαβαστεί"));
				m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
				m.setStandardButtons(QMessageBox::Ok);
				m.move(0, 100);
				QFont serifFont("Times", 18, QFont::Bold);
				m.setFont(serifFont);

				m.exec();
				ui.lineScan->setText("");
				ui.lineScan->setFocus();

				return;
			}
		}

	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;

		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineScan->setText("");
		ui.lineScan->setFocus();
		return;

	}

	if (scanned.mid(12, 1) == "Z") {
		QMessageBox m;
		QSound::play("bell.wav");
		m.setText(trUtf8("O K/T δεν έχει προδιαγραφή 3Α"));
		m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        QPushButton *acc = m.addButton(trUtf8("Aποδοχή"),
				QMessageBox::ActionRole);
        QPushButton *rej = m.addButton(trUtf8("Aπόρριψη"),
				QMessageBox::ActionRole);

		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
        acc->setFocusPolicy(Qt::NoFocus);
        rej->setFocusPolicy(Qt::NoFocus);
		m.exec();
		if (m.clickedButton() == rej) {
			ui.lineScan->setText("");
			ui.lineScan->setFocus();
			return;
		} else
			goto norm;
	}
	norm: weight += scanned.left(3).toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->setRowCount(r + 1);
	QVariant pc = ui.tableWidget->rowCount();
	ui.labelPieces->setText(pc.toString());
	QTableWidgetItem *code = new QTableWidgetItem;
    code->setFlags(code->flags() ^ Qt::ItemIsEditable);
	if (r > 0)
		code->setText(ui.tableWidget->item(r - 1, 0)->text());
	ui.tableWidget->setItem(r, 0, code);

	for (int i = r - 1; i > 0; --i) {

		ui.tableWidget->item(i, 0)->setText(
				ui.tableWidget->item(i - 1, 0)->text());
		//ui.tableWidget->item(i,0)->setBackgroundColor(ui.tableWidget->item(i-1,0)->backgroundColor());

	}
	ui.tableWidget->item(0, 0)->setText(scanned);

	//ui.tableWidget->setItem(0,0,code);
	ui.lineScan->setText("");
	ui.lineScan->setFocus();
	++r;
}

void fortosi_progress_1_2::finalize() {
    if(client->networkstatus)
    {

	QHostAddress addr((QString) SVR_HOST);
    QFile file3("fortosi_3.txt");
    QFile file2("fortosi_2.txt");
    file3.remove();
    file2.copy("fortosi_3.txt");
    file2.remove();
	qDebug() << "R=" << r;
    QFile file ("fortosi.txt");
    file.copy("fortosi_2.txt");

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream fout(&file);
    fout<<"2\n";
    QString req_type = "SF";
    QTextCodec *codec = QTextCodec::codecForName("Windows-1253");
    QByteArray fcustomer;
    fcustomer = codec->fromUnicode(grtoen(customer.toUtf8()));
    for (int j=0;j<r;++j)
    {
        fout << req_type+"\n"<< fcustomer+"\n"<< ui.tableWidget->item(j, 0)->text()+"\n"
             << ui.labelWeight->text()+"\n"<< fortosi_id+"\n\n";


    }

    fout <<"EOF";
    file.close();

	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "SF";
		out << quint16(0) << req_type << customer
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< fortosi_id;
		out.device()->seek(0);
		out << quint16(block.size() - sizeof(quint16));
		client->write(block);
	}
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	out << quint16(0xFFFF);
	client->write(block);
	//delete (this);
	disable_controls();
    }
    else
    {
        networkFailure();
    }


}

void fortosi_progress_1_2::temporary() {
    if(client->networkstatus)
    {
	QHostAddress addr((QString) SVR_HOST);
    QFile file ("fortosi.txt");
    QFile file3("fortosi_3.txt");
    QFile file2("fortosi_2.txt");
    file3.remove();
    file2.copy("fortosi_3.txt");
    file2.remove();
    file.copy("fortosi_2.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream fout(&file);
    fout<<"2\n";
    QString req_type = "ST";
    QTextCodec *codec = QTextCodec::codecForName("Windows-1253");
    QByteArray fcustomer;
    fcustomer = codec->fromUnicode(grtoen(customer.toUtf8()));

    for (int j=0;j<r;++j)
    {
        fout << req_type+"\n"<< fcustomer+"\n"<< ui.tableWidget->item(j, 0)->text()+"\n"
             << ui.labelWeight->text()+"\n"<< fortosi_id+"\n\n";

    }

    fout <<"EOF";
    file.close();

	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);

		out << quint16(0) << req_type << customer
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< fortosi_id;
		out.device()->seek(0);
		out << quint16(block.size() - sizeof(quint16));
		client->write(block);
	}
	QByteArray block1;
	QDataStream out1(&block1, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
	//
	//delete (this);
	disable_controls();
    }
    else{
        networkFailure();

    }

}

void fortosi_progress_1_2::cellclicked() {
	ui.pushDelete->setEnabled(TRUE);
    ui.lineScan->setFocus();
}

void fortosi_progress_1_2::delrow() {
	int r1 = ui.tableWidget->currentRow();
	weight -= ui.tableWidget->item(r1, 0)->text().left(3).toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->removeRow(r1);
	QVariant pc = ui.tableWidget->rowCount();
	ui.labelPieces->setText(pc.toString());
	r -= 1;
	ui.pushDelete->setEnabled(FALSE);
	ui.lineScan->setFocus();
}

void fortosi_progress_1_2::check() {
	disable_controls();
	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "CHKC";
		out << quint16(0) << req_type << ui.tableWidget->item(i, 0)->text();
		ui.tableWidget->item(i, 0)->setBackgroundColor(Qt::white);
		out.device()->seek(0);
		out << quint16(block.size() - sizeof(quint16));
		client->write(block);
	}
	QByteArray block1;
	QDataStream out1(&block1, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);

}


void fortosi_progress_1_2::disable_controls(){
	ui.finalPush->setEnabled(FALSE);
	ui.lineScan->setEnabled(FALSE);
	ui.pushCancel->setEnabled(FALSE);
	ui.pushCheck->setEnabled(FALSE);
	ui.pushDelete->setEnabled(FALSE);
    ui.tableWidget->setEnabled(FALSE);
	ui.tempPush->setEnabled(FALSE);

}

void fortosi_progress_1_2::enable_controls(){
	ui.finalPush->setEnabled(TRUE);
	ui.lineScan->setEnabled(TRUE);
	ui.pushCancel->setEnabled(TRUE);
	ui.pushCheck->setEnabled(TRUE);
    ui.tableWidget->setEnabled(TRUE);
	ui.tempPush->setEnabled(TRUE);
	ui.lineScan->setFocus();

}

void fortosi_progress_1_2::networkFailure()
{
    QMessageBox m;
    m.setText(trUtf8("Πρόβλημα επικοινωνίας με τον server!"));
    QSound::play("bell.wav");
    m.setStandardButtons(QMessageBox::Ok);
    m.setInformativeText(trUtf8("Η αποστολή δεν έγινε!"));
    m.move(30,120);
    m.exec();
}

QString fortosi_progress_1_2::grtoen(QString str)
{
    str.replace(QString("Α"),trUtf8("A"));
    str.replace(QString("Β"),trUtf8("B"));
    str.replace(QString("Ε"),trUtf8("E"));
    str.replace(QString("Ζ"),trUtf8("Z"));
    str.replace(QString("Η"),trUtf8("H"));
    str.replace(QString("Ι"),trUtf8("I"));
    str.replace(QString("Κ"),trUtf8("K"));
    str.replace(QString("Μ"),trUtf8("M"));
    str.replace(QString("Ν"),trUtf8("N"));
    str.replace(QString("Ο"),trUtf8("O"));
    str.replace(QString("Τ"),trUtf8("T"));
    str.replace(QString("Υ"),trUtf8("Y"));
    str.replace(QString("Χ"),trUtf8("X"));
    str.replace(QString("Ψ"),trUtf8("C"));
    str.replace(QString("Δ"),trUtf8("D"));
    str.replace(QString("Φ"),trUtf8("F"));
    str.replace(QString("Γ"),trUtf8("G"));
    str.replace(QString("Ξ"),trUtf8("J"));
    str.replace(QString("Λ"),trUtf8("L"));
    str.replace(QString("Π"),trUtf8("P"));
    str.replace(QString("Ρ"),trUtf8("R"));
    str.replace(QString("Σ"),trUtf8("S"));
    str.replace(QString("Θ"),trUtf8("U"));
    str.replace(QString("Ω"),trUtf8("V"));
    return str;

}
