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
#include "read_label.h"
#include <QMessageBox>
#include <QtNetwork>

read_label::read_label(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QString ipath=(QString)APATH+"/img/clear.png";
	QIcon *icon=new QIcon(ipath);
	ui.pushButton->setIcon(*icon);

	QString ipath2=(QString)APATH+"/img/delete.png";
	QIcon *icon2=new QIcon(ipath2);
	ui.pushButton_2->setIcon(*icon2);

	QHostAddress addr((QString)SVR_HOST);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
	nextblocksize=0;
	ui.pushButton->setFocusPolicy(Qt::NoFocus);
	ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
	connect(ui.lineEdit,SIGNAL(returnPressed()),this,SLOT(send_code()));
	connect(client,SIGNAL(readyRead()),this,SLOT(startread()));
	connect(ui.pushButton,SIGNAL(pressed()),this,SLOT(clear_edit()));
	connect(ui.pushButton_2,SIGNAL(pressed()),this,SLOT(end_it()));
}

read_label::~read_label()
{
	client->disconnectFromHost();
}


void read_label::send_code()
{
	QString scanned=ui.lineEdit->text();
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
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "READLAB";
	QString code=ui.lineEdit->text();
	out << quint16(0) << req_type<<code;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block1,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);

}

void read_label::startread()
{
	QDataStream in(client);
		 qDebug()<<"MIKA";

		 in.setVersion(QDataStream::Qt_4_1);
		 forever
		 	{

		 		if (nextblocksize==0) {

		 			if (client->bytesAvailable()<sizeof(quint16))
		 				break;
		 		//	qDebug()<<"MPIKA1";
		 		in >> nextblocksize;


		 		}

		 		if (nextblocksize==0xFFFF)
		 		{
		 			//client->close();
		 			break;
		 		}

		 		if (client->bytesAvailable()<nextblocksize)
		 			break;
		 		QString	code,per,xrisi,grm,epimik,filla,md,cd;

		 		in >> code>>per>>xrisi>>grm>>epimik>>filla>>md>>cd;

		 		ui.labelcode->setText(code);
		 		ui.labelper->setText(per);
		 		ui.labelxrisi->setText(xrisi);
		 		ui.labelgrm->setText(grm);
		 		ui.labelepimikinsi->setText(epimik);
		 		ui.labelfylla->setText(filla);
		 		ui.labelmd->setText(md);
		 		ui.labelcd->setText(cd);





		 		nextblocksize=0;

		 	}
				 nextblocksize=0;

}

void read_label::clear_edit()
{
	ui.lineEdit->setText("");
}

void read_label::end_it()
{
	this->hide();
}
