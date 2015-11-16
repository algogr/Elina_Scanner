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
#include "fortosi_new_1_1.h"
#include "stdio.h"
#include <iostream>
#include <QHostAddress>
using namespace std;

fortosi_new_1_1::fortosi_new_1_1(QWidget *parent, QString ccode,
		QString customer, QString car1, QString car2, QString prfid) :
	QDialog(parent) {
	//client = pclient;
    QHostAddress addr((QString) SVR_HOST);
    client = new QTcpSocket;
    client->connectToHost(addr, 8889);
	nextblocksize = 0;
	//client->setReadBufferSize((qint64)120000);
	this->ccode = ccode;
	this->customer = customer;
	this->car1 = car1;
	this->car2 = car2;
	this->prfid = prfid;

	//qDebug() << "ccode:" << ccode << "customer:" << customer << "car1:" << car1
	//<< "car2:" << car2 << "prfid:" << prfid;
	ui.setupUi(this);
	QString ipath = (QString) APATH + "/img/app.png";
	QIcon *icon = new QIcon(ipath);
	if (prfid == "0")
		ui.pushProf->setVisible(FALSE);
	this->setWindowIcon(*icon);
	r = 0;
	weight = 0;
	ui.finalPush->setFocusPolicy(Qt::NoFocus);
	ui.devPush->setFocusPolicy(Qt::NoFocus);
	ui.back->setFocusPolicy(Qt::NoFocus);
	ui.labelWeight->setText("0");
	ui.tableWidget->setColumnCount(1);
	ui.tableWidget->setRowCount(0);
	ui.lineEdit->setFocus();
	ui.tableWidget->setColumnWidth(0, 200);
	connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(scan()));
	connect(ui.finalPush, SIGNAL(clicked()), this, SLOT(finalize()));
	connect(ui.devPush, SIGNAL(clicked()), this, SLOT(temporary()));
	connect(ui.back, SIGNAL(clicked()), this, SLOT(back()));
	//connect(ui.tableWidget, SIGNAL(cellClicked(int row,int column)), this, SLOT(cellclicked()));
	connect(ui.pushdelrow, SIGNAL(clicked()), this, SLOT(delrow()));
	connect(ui.tableWidget, SIGNAL(pressed(const QModelIndex &)), this,
			SLOT(cellclicked(const QModelIndex &)));
	connect(ui.pushCheck, SIGNAL(clicked()), this, SLOT(check()));
	connect(ui.pushProf, SIGNAL(clicked()), this, SLOT(compare()));
    connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
    //connect(ui.lineEdit,SIGNAL(clicked()),this,SLOT(lineeditclicked()));
    delete icon;
}

fortosi_new_1_1::~fortosi_new_1_1() {
    client->disconnectFromHost();
    client->waitForDisconnected(1000);
    //delete client;
}

void fortosi_new_1_1::scan() {
	QString scanned = ui.lineEdit->text();
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
			ui.lineEdit->setText("");
			ui.lineEdit->setFocus();

			return;
		}
	}

	QRegExp kt("\\d{12,12}[X-Z]\\d{2,2}");
	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;
		QSound::play("bell.wav");
		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineEdit->setText("");
		ui.lineEdit->setFocus();
		return;

	}

	if (scanned.mid(12, 1) == "Z") {
		QMessageBox m;
		QSound::play("bell.wav");
		m.setText(trUtf8("O K/T έχει προδιαγραφή 3Α"));
		m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		QAbstractButton *acc = m.addButton(trUtf8("Aποδοχή"),
				QMessageBox::ActionRole);
		QAbstractButton *rej = m.addButton(trUtf8("Aπόρριψη"),
				QMessageBox::ActionRole);

        m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
        acc->setFocusPolicy(Qt::NoFocus);
        rej->setFocusPolicy(Qt::NoFocus);

		m.exec();
		if (m.clickedButton() == rej) {
			ui.lineEdit->setText("");
			ui.lineEdit->setFocus();
			return;
		}
        goto norm;
	}
	norm: weight += scanned.left(3).toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->setRowCount(r + 1);
	QVariant rc = ui.tableWidget->rowCount();
	ui.labelPieces->setText(rc.toString());
	QTableWidgetItem *code = new QTableWidgetItem;
	if (r > 0)
		code->setText(ui.tableWidget->item(r - 1, 0)->text());
	ui.tableWidget->setItem(r, 0, code);

	for (int i = r - 1; i > 0; --i) {

		ui.tableWidget->item(i, 0)->setText(
				ui.tableWidget->item(i - 1, 0)->text());

	}
	ui.tableWidget->item(0, 0)->setText(scanned);

	//ui.tableWidget->setItem(0,0,code);
	ui.lineEdit->setText("");
	ui.lineEdit->setFocus();
	r++;
}

void fortosi_new_1_1::back() {
	delete (this);
}

void fortosi_new_1_1::finalize() {

    QFile file ("fortosi.txt");
    QFile file3("fortosi_3.txt");
    QFile file2("fortosi_2.txt");
    file3.remove();
    file2.copy("fortosi_3.txt");
    file2.remove();
    file.copy("fortosi_2.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream fout(&file);
    fout<<"1\n";
    QString req_type = "FP";
    for (int j=0;j<r;++j)
    {
        fout << req_type+"\n"<< ccode +"\n"<< customer +"\n"<< car1+"\n" << car2+"\n"
                << ui.tableWidget->item(j, 0)->text() +"\n"<< ui.labelWeight->text()+"\n"
                << prfid+"\n\n";

    }

    fout <<"EOF";
    file.close();

	for (int i = 0; i < r; ++i) {
		QByteArray block;

		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);


		out << quint16(0) << req_type << ccode << customer << car1 << car2
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< prfid;
        qDebug() << quint16(0) << req_type << ccode << customer << car1 << car2
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< prfid;

		out.device()->seek(0);
        out << quint16(block.size() - sizeof(quint16));
        qDebug() << "BYTES:" << client->bytesToWrite();
		client->write(block);


	}

	QByteArray block1;

	QDataStream out1(&block1, QIODevice::WriteOnly);

	out1.setVersion(QDataStream::Qt_4_1);

	out1 << quint16(0xFFFF);

	client->write(block1);

	//}
	//client->disconnectFromHost();
	//delete (client);
	//delete (this);
    disable_controls();

}

void fortosi_new_1_1::temporary() {
    QFile file ("fortosi.txt");
    QFile file3("fortosi_3.txt");
    QFile file2("fortosi_2.txt");
    file3.remove();
    file2.copy("fortosi_3.txt");
    file2.remove();
    file.copy("fortosi_2.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream fout(&file);
    fout<<"1\n";
    QString req_type = "FT";

    for (int j=0;j<r;++j)
    {
        fout << req_type+"\n"<< ccode +"\n"<< customer +"\n"<< car1+"\n" << car2+"\n"
                << ui.tableWidget->item(j, 0)->text() +"\n"<< ui.labelWeight->text()+"\n"
                << prfid+"\n\n";

    }

    fout <<"EOF";
    file.close();


	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "FT";
		out << quint16(0) << req_type << ccode << customer << car1 << car2
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< prfid;
		out.device()->seek(0);
		out << quint16(block.size() - sizeof(quint16));
		client->write(block);
	}
	QByteArray block1;
	QDataStream out1(&block1, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);

	//delete (this);
	disable_controls();

}

void fortosi_new_1_1::cellclicked(const QModelIndex &) {
	ui.pushdelrow->setEnabled(TRUE);
}

void fortosi_new_1_1::lineeditclicked()
{
    qDebug("EDIT:::!!!");
}

void fortosi_new_1_1::delrow() {
	int r1 = ui.tableWidget->currentRow();
	weight -= ui.tableWidget->item(r1, 0)->text().left(3).toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());

	ui.tableWidget->removeRow(r1);
	QVariant pc = ui.tableWidget->rowCount() + 1;
	ui.labelPieces->setText(pc.toString());
	r -= 1;
	ui.pushdelrow->setEnabled(FALSE);
	ui.lineEdit->setFocus();
}

void fortosi_new_1_1::check() {
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
	disable_controls();
}

void fortosi_new_1_1::compare() {
	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "COMP";
		out << quint16(0) << req_type << ui.tableWidget->item(i, 0)->text()
				<< prfid;
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

void fortosi_new_1_1::startread() {
	QDataStream in(client);
	//qDebug() << "MIKA";

	in.setVersion(QDataStream::Qt_4_1);
	forever {

		ff: if (nextblocksize == 0) {

			if (client->bytesAvailable() < sizeof(quint16))
				break;
			//	qDebug()<<"MPIKA1";
			in >> nextblocksize;
			qDebug() << "nextblocksize" << nextblocksize;

		}

		if (nextblocksize == 0xFFFF) {
			nextblocksize = 0;
			if (readmode == 2) {
				QMessageBox m;
				QString mtext;
				if (reply.isEmpty() == FALSE) {
					mtext = reply.join("\n");
					m.setText(mtext);
					m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
					QSound::play("bell.wav");
				} else {
					m.setText(trUtf8("Η προφόρτωση ταυτίζεται με την φόρτωση"));
					QSound::play("bell.wav");

				}
				m.setStandardButtons(QMessageBox::Ok);
				m.move(0, 0);
				//QFont serifFont("Times", 18, QFont::Bold);
				//m.setFont(serifFont);
				m.exec();
				reply.clear();

			}

			goto ff;

		}

		if (client->bytesAvailable() < nextblocksize)
			break;
		QString type, code_t, problem;
		in >> type;
		qDebug() << "TYPE:" << type;

		in >> code_t >> problem;

		if (type == "CHKC") {

			qDebug() << "CODE:" << code_t;
			readmode = 1;
			if (code_t == "99999") {
				enable_controls();
				QMessageBox m;
				QString mtext;
				m.setText(trUtf8("Ο έλεγχος ολοκληρωθηκε!"));
				m.setStandardButtons(QMessageBox::Ok);
				QSound::play("bell.wav");
				m.move(100, 100);
				m.exec();

			}
			//qDebug() << "MIKA KAI EDO:" << ui.tableWidget->rowCount();
			for (int i = 0; i < ui.tableWidget->rowCount(); ++i) {
				//qDebug() << "CODE_T:" << code_t << " TABLE:"
				//<< ui.tableWidget->item(i, 0)->text();
				if (ui.tableWidget->item(i, 0)->text() == code_t) {
					//qDebug() << "PRBLEM:" << problem;
					if (problem == "0")
						ui.tableWidget->item(i, 0)->setBackgroundColor(Qt::red);
					if (problem == "1")
						ui.tableWidget->item(i, 0)->setBackgroundColor(Qt::gray);
					//break;
				}
			}
			nextblocksize = 0;

		}
		//qDebug() << type;
		if (type == "COMP") {
			//qDebug() << "LL:" << code_t << problem;
			readmode = 2;
			if (problem == "0") {
				reply << trUtf8("O Κ/Τ ") + code_t + trUtf8(
						" δεν υπάρχει στην προφόρτωση");

			}

			if (problem == "1") {
				reply << trUtf8("O Κ/Τ ") + code_t + trUtf8(" δεν διαβάστηκε");

			}

		}

		if (type == "IFI") {
            qDebug() << "PIRA IFI";
            delete (this);
        }

		//qDebug() << req_type;
		nextblocksize = 0;

	}
	nextblocksize = 0;

}

void fortosi_new_1_1::disable_controls() {
	ui.back->setEnabled(FALSE);
	ui.devPush->setEnabled(FALSE);
	ui.finalPush->setEnabled(FALSE);
	ui.lineEdit->setEnabled(FALSE);
	ui.pushCheck->setEnabled(FALSE);
	ui.pushProf->setEnabled(FALSE);
	ui.pushdelrow->setEnabled(FALSE);
	ui.tableWidget->setEnabled(FALSE);
	return;

}

void fortosi_new_1_1::enable_controls() {
	ui.back->setEnabled(TRUE);
	ui.devPush->setEnabled(TRUE);
	ui.finalPush->setEnabled(TRUE);
	ui.lineEdit->setEnabled(TRUE);
	ui.pushCheck->setEnabled(TRUE);
	ui.pushProf->setEnabled(TRUE);
	ui.tableWidget->setEnabled(TRUE);
	ui.lineEdit->setFocus();
	return;

}
