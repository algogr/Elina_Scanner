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
#include "fortosi_new_1_2.h"
#include "stdio.h"
#include <iostream>
#include "ui_fortosi_new_1_2.h"
using namespace std;

fortosi_new_1_2::fortosi_new_1_2(QWidget *parent, QString ccode, QString customer, QString car1, QString car2,QString prfid) :
	QDialog(parent) {

	QHostAddress addr((QString) SVR_HOST);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
	this->ccode = ccode;
	this->customer = customer;
	this->car1 = car1;
	this->car2 = car2;
	this->prfid = prfid;

	ui.setupUi(this);
	ui.tableWidget_2->setHorizontalHeaderLabels(QStringList()<<trUtf8("Κ/A"));

	QString ipath = (QString) APATH + "/img/app.png";
	QIcon *icon = new QIcon(ipath);
	this->setWindowTitle(trUtf8("Φόρτωση κατά κωδικό"));
	this->setWindowIcon(*icon);
	QString ipath1= (QString) APATH + "/img/search.png";
	QIcon *icon1=new QIcon(ipath1);
	ui.pushSearch->setIcon(*icon1);
	r = 0;
	weight = 0;
	ui.finalButton->setFocusPolicy(Qt::NoFocus);
	ui.deleteButton->setFocusPolicy(Qt::NoFocus);
	ui.pushExit->setFocusPolicy(Qt::NoFocus);
	ui.pushTemp->setFocusPolicy(Qt::NoFocus);
	ui.labelWeight->setText("0");
	ui.tableWidget->setColumnCount(1);
	ui.tableWidget->setRowCount(0);
	ui.lineEdit->setFocus();
	ui.tableWidget->setColumnWidth(0, 200);
	ui.tableWidget_2->setColumnCount(1);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8(
			"Κωδικοί Α"));
	ui.lineEdit_2->setText(trUtf8("Π"));

	nextblocksize = 0;
	connect(client, SIGNAL(readyRead()), this, SLOT(startreadItems()));
	//connect(ui.comboBox, SIGNAL(currentIndexChanged()), this, SLOT(itemchanged()));
	connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(scan()));
	connect(ui.finalButton, SIGNAL(clicked()), this, SLOT(finalize()));
	connect(ui.pushTemp, SIGNAL(clicked()), this, SLOT(temporary()));
	connect(ui.pushExit, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(delrow()));
	connect(ui.tableWidget, SIGNAL(pressed(const QModelIndex &)), this,
			SLOT(cellclicked(const QModelIndex &)));
	connect(ui.tableWidget_2, SIGNAL(cellClicked(int ,int )), this,
			SLOT(tableclicked(int,int)));
	//connect(ui.lineEdit_2, SIGNAL(textChanged(const QString &)), this,SLOT(requestItems()));
	connect(ui.pushCheck, SIGNAL(clicked()), this, SLOT(check()));
	connect(ui.pushProf, SIGNAL(clicked()), this, SLOT(compare()));
	connect(ui.pushSearch, SIGNAL(clicked()), this, SLOT(requestItems()));
	connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
	ui.lineEdit_2->setFocus();
	//requestItems();
}

fortosi_new_1_2::~fortosi_new_1_2() {
	client->disconnectFromHost();
}

void fortosi_new_1_2::requestItems() {
	QByteArray block;
	QString like = ui.lineEdit_2->text();
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "RI";
	out << quint16(0) << req_type << like;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
}

void fortosi_new_1_2::requestDetails() {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "IC";
	out << quint16(0) << req_type;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
}

void fortosi_new_1_2::startreadItems() {
	QDataStream in(client);
	in.setVersion(QDataStream::Qt_4_1);
	int r = 0;
	ui.tableWidget->setRowCount(r);
	forever {
		if (nextblocksize == 0) {

			if (client->bytesAvailable() < sizeof(quint16))
				break;
			in >> nextblocksize;

		}

		if (nextblocksize == 0xFFFF) {
			//client->close();
			break;
		}

		if (client->bytesAvailable() < nextblocksize)
			break;
		QString scode = "";
		in >> scode;
		qDebug() << scode;
		QTableWidgetItem *a = new QTableWidgetItem;
		a->setText(scode);
		a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		ui.tableWidget_2->setRowCount(r + 1);
		ui.tableWidget_2->setItem(r, 0, a);

		++r;

		//qDebug() << req_type;
		nextblocksize = 0;
	}
	nextblocksize = 0;

}

void fortosi_new_1_2::scan() {
	QString scanned = ui.lineEdit->text();

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
		ui.lineEdit->setText("");
		ui.lineEdit->setFocus();
		return;

	}

	if (scanned.mid(12, 1) == "Y") {
		QMessageBox m;
		QSound::play("bell.wav");
		m.setText(trUtf8("O K/T δεν έχει σωστές προδιαγραφές"));
		m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);

		m.exec();

		ui.lineEdit_2->setText("");
		ui.lineEdit->setFocus();
		return;
	}

	if (scanned.mid(12, 1) == "Z") {
		QMessageBox m;
		QSound::play("bell.wav");
		m.setText(trUtf8("O K/T δεν έχει σωστές προδιαγραφές"));
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
	weight += scanned.left(3).toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->setRowCount(r + 1);
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

void fortosi_new_1_2::back() {
	delete (this);
}

void fortosi_new_1_2::finalize() {
	//QHostAddress addr((QString)SVR_HOST);

	//QTcpSocket *client = new QTcpSocket;
	//client->connectToHost(addr, 8888);
	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "FP";
		out << quint16(0) << req_type << ccode << customer << car1 << car2
				<< ui.tableWidget->item(i, 0)->text() << ui.labelWeight->text()
				<< prfid;
		out.device()->seek(0);
		out << quint16(block.size() - sizeof(quint16));
		client->write(block);
	}
	QByteArray block1;
    qDebug()<<"A1";
	QDataStream out1(&block1, QIODevice::WriteOnly);
    qDebug()<<"A2";
	out1.setVersion(QDataStream::Qt_4_1);
    qDebug()<<"A3";
	out1 << quint16(0xFFFF);
    qDebug()<<"A4";
	client->write(block1);
    qDebug()<<"A5";
	client->disconnectFromHost();
    qDebug()<<"A6";
	delete (this);

}

void fortosi_new_1_2::temporary() {
	//QHostAddress addr((QString)SVR_HOST);

	//QTcpSocket *client = new QTcpSocket;
	///client->connectToHost(addr, 8888);
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
	delete (this);

}

void fortosi_new_1_2::cellclicked(const QModelIndex &) {
	ui.deleteButton->setEnabled(TRUE);
}

void fortosi_new_1_2::delrow() {
	int r1 = ui.tableWidget->currentRow();
	weight -= ui.tableWidget->item(r1, 0)->text().toInt();
	QVariant sweight = weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->removeRow(r1);
	r -= 1;
	ui.deleteButton->setEnabled(FALSE);
	ui.lineEdit->setFocus();
}

void fortosi_new_1_2::tableclicked(int row, int col) {

	this->rowsel = row;
}

void fortosi_new_1_2::check() {
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

void fortosi_new_1_2::compare() {
	for (int i = 0; i < r; ++i) {
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "COMP";
		out << quint16(0) << req_type << ui.tableWidget->item(i, 0)->text() << prfid;
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

void fortosi_new_1_2::startread() {
	QDataStream in(client);
	qDebug() << "MIKA";



	in.setVersion(QDataStream::Qt_4_1);
	forever {

		ff: if (nextblocksize == 0) {

			if (client->bytesAvailable() < sizeof(quint16))
				break;
			//	qDebug()<<"MPIKA1";
			in >> nextblocksize;

		}

		if (nextblocksize == 0xFFFF) {
			nextblocksize = 0;
			if (readmode==2){
				QMessageBox m;
				QString mtext;
				if (reply.isEmpty()==FALSE)
				{
					mtext=reply.join("\n");
					m.setText(mtext);
					m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
				}
				else
				{
					m.setText(trUtf8("Η προφόρτωση ταυτίζεται με την φόρτωση"));



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

		in >> code_t >> problem;

		if (type == "CHKC") {
			readmode = 1;
			if(code_t=="99999")
			{
				QMessageBox m;
				QString mtext;
				m.setText(trUtf8("Ο έλεγχος ολοκληρωθηκε!"));
				m.setStandardButtons(QMessageBox::Ok);
				m.move(100,100);
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

		}
		qDebug()<<type;
		if (type == "COMP") {
			qDebug()<<"LL:"<<code_t<<problem;
			readmode=2;
			 if (problem=="0")
			{
				reply<<trUtf8("O Κ/Τ ")+code_t+trUtf8(" δεν υπάρχει στην προφόρτωση");

			}

			if (problem == "1") {
				reply << trUtf8("O Κ/Τ ") + code_t + trUtf8(" δεν διαβάστηκε");

			}

		}

		//qDebug() << req_type;
		nextblocksize = 0;

	}
	nextblocksize = 0;

}






