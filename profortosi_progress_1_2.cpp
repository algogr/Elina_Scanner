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
#include "profortosi_progress_1_2.h"
#include "stdio.h"
#include <iostream>
using namespace std;

profortosi_progress_1_2::profortosi_progress_1_2(QWidget *parent, QString fid) :
	QDialog(parent) {

	ui.setupUi(this);
	QHostAddress addr((QString) SVR_HOST);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);

	QString ipath = (QString) APATH + "/img/app.png";
	QIcon *icon = new QIcon(ipath);

	this->setWindowIcon(*icon);
	profortosi_id = fid;
	qDebug() << "FID:" << fid;

	nextblocksize = 0;
	r = 0;

	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setColumnCount(1);
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
	requestproFortosi();

}

profortosi_progress_1_2::~profortosi_progress_1_2() {
	client->disconnectFromHost();

}

void profortosi_progress_1_2::startread() {
	QDataStream in(client);
	in.setVersion(QDataStream::Qt_4_1);

	forever {
		ff: if (nextblocksize == 0) {

			if (client->bytesAvailable() < sizeof(quint16))
				break;
			in >> nextblocksize;

		}

		if (nextblocksize == 0xFFFF) {
			nextblocksize = 0;
			if (readmode == 1) {
				readmode = 0;
				goto ff;
			} else
				return;

		}

		if (client->bytesAvailable() < nextblocksize)
			break;
		QString type;
		in >> type;
		if (type == "PRS") {
			QString cname = "";
			QString code_t, sweight;
			in >> cname >> code_t >> sweight;
			ui.labelCustomer->setText(cname);
			customer = cname;
			ui.labelWeight->setText(sweight);
			weight = sweight.toInt();
			QTableWidgetItem *a = new QTableWidgetItem;

			a->setText(code_t);

			a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

			ui.tableWidget->setRowCount(r + 1);
			ui.tableWidget->setItem(r, 0, a);
			QVariant pc = ui.tableWidget->rowCount();
			ui.labelPieces->setText(pc.toString());
			r++;

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
		if (type == "IFI") {
			qDebug() << "PIRA IFI";
			delete (this);
		}
		nextblocksize = 0;
	}
	nextblocksize = 0;
}

void profortosi_progress_1_2::requestproFortosi() {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "PRS";
	out << quint16(0) << req_type << QString(profortosi_id);
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
}

void profortosi_progress_1_2::back() {
	delete (this);
}

void profortosi_progress_1_2::scan() {
	QString scanned = ui.lineScan->text();
	QRegExp kt("\\d{12,12}[X-Z]\\d{2,2}");
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
		QAbstractButton *acc = m.addButton(trUtf8("Aποδοχή"),
				QMessageBox::ActionRole);
		QAbstractButton *rej = m.addButton(trUtf8("Aπόρριψη"),
				QMessageBox::ActionRole);

		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);

		m.exec();
		if (m.clickedButton() == rej) {
			ui.lineScan->setText("");
			ui.lineScan->setFocus();
			return;
		}
	}
	norm: weight += scanned.left(3).toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->setRowCount(r + 1);
	QVariant pc = ui.tableWidget->rowCount();
	ui.labelPieces->setText(pc.toString());
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
	ui.lineScan->setText("");
	ui.lineScan->setFocus();
	++r;
}

void profortosi_progress_1_2::finalize() {
	QHostAddress addr((QString) SVR_HOST);


	qDebug() << "R=" << r;


	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "PSF";
		out << quint16(0) << req_type << customer
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< profortosi_id;
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

void profortosi_progress_1_2::temporary() {
		for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "PST";
		out << quint16(0) << req_type << customer
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< profortosi_id;
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

void profortosi_progress_1_2::cellclicked() {
	ui.pushDelete->setEnabled(TRUE);
}

void profortosi_progress_1_2::delrow() {
	int r1 = ui.tableWidget->currentRow();
	weight -= ui.tableWidget->item(r1, 0)->text().toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->removeRow(r1);
	QVariant pc = ui.tableWidget->rowCount();
	ui.labelPieces->setText(pc.toString());
	r -= 1;
	ui.pushDelete->setEnabled(FALSE);
	ui.lineScan->setFocus();
}

void profortosi_progress_1_2::check() {
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

void profortosi_progress_1_2::disable_controls() {
	ui.finalPush->setEnabled(FALSE);
	ui.lineScan->setEnabled(FALSE);
	ui.pushCancel->setEnabled(FALSE);
	ui.pushCheck->setEnabled(FALSE);
	ui.pushDelete->setEnabled(FALSE);
	ui.tableWidget->setEnabled(FALSE);
	ui.tempPush->setEnabled(FALSE);

}

void profortosi_progress_1_2::enable_controls() {
	ui.finalPush->setEnabled(TRUE);
	ui.lineScan->setEnabled(TRUE);
	ui.pushCancel->setEnabled(TRUE);
	ui.pushCheck->setEnabled(TRUE);
	ui.tableWidget->setEnabled(TRUE);
	ui.tempPush->setEnabled(TRUE);
    ui.lineScan->setFocus();
}

