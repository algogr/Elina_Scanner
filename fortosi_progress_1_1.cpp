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
#include "fortosi_progress_1_1.h"

fortosi_progress_1_1::fortosi_progress_1_1(QWidget *parent,QTcpSocket *client,QString fid)
    : QDialog(parent)
{
	this->client=client;

	ui.setupUi(this);
	QString ipath=(QString)APATH+"/img/app.png";
	QIcon *icon=new QIcon(ipath);

	this->setWindowIcon(*icon);
	fortosi_id=fid;
	r=0;

	QHostAddress addr((QString)SVR_HOST);
	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("K/T")<<trUtf8("Κιλά"));
	ui.tableWidget->setColumnWidth(0,200);
	ui.tableWidget->setColumnWidth(1,75);

	ui.tableWidget->setRowCount(0);
	nextblocksize=0;
	requestFortosi();
	connect(client, SIGNAL(readyRead()),this, SLOT(startread()));
	connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));

}

fortosi_progress_1_1::~fortosi_progress_1_1()
{

}


void fortosi_progress_1_1::startread()
 {
	 QDataStream in(client);
	 in.setVersion(QDataStream::Qt_4_1);


	 forever
	 	{
	 		if (nextblocksize==0) {

	 			if (client->bytesAvailable()<sizeof(quint16))
	 				break;
	 		in >> nextblocksize;


	 		}

	 		if (nextblocksize==0xFFFF)
	 		{
	 			//client->close();
	 			//break;
	 			return;
	 		}

	 		if (client->bytesAvailable()<nextblocksize)
	 			break;
	 		QString	cname="";
	 		QString car1,car2,weight,id,code_t;
	 		in >> cname>> car1 >> car2 >> weight>> code_t;

	 		ui.labelCustomer->setText(cname);
	 		ui.labelCar1->setText(car1);
	 		ui.labelCar2->setText(car2);
	 		ui.labelWeight->setText(weight);

	 		QTableWidgetItem *a=new QTableWidgetItem;
	 		QTableWidgetItem *b=new QTableWidgetItem;

	 		a->setText(code_t);
	 		b->setText(code_t.left(3));

	 		a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

	 		ui.tableWidget->setRowCount(r+1);
	 		ui.tableWidget->setItem(r,0,a);
	 		ui.tableWidget->setItem(r,1,b);




	 		++r;

	 		//qDebug() << req_type;
	 		nextblocksize=0;
	 	}

}

void fortosi_progress_1_1::requestFortosi()
 {
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="RE";
	out << quint16(0)<<req_type<<QString(fortosi_id);
	qDebug()<<"FORTOSI_ID"<<fortosi_id;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);

 }


void fortosi_progress_1_1::back()
{
	delete(this);
}
