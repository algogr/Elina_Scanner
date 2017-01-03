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
#include "fortosi_new_1a.h"

fortosi_new_1a::fortosi_new_1a(QWidget *parent,QTcpSocket *pclient,QString ccode,QString customer, QString car1,QString car2)
    : QWidget(parent)
{
	ui.setupUi(this);
	QString ipath=(QString)APATH+"/img/app.png";
	QIcon *icon=new QIcon(ipath);

	this->setWindowIcon(*icon);
	this->parent=parent;
	client=pclient;
	pcustomer=customer;
	pccode=ccode;
	pcar1=car1;
	pcar2=car2;
	qDebug()<<"new1:"<<client;

		//QHostAddress addr((QString)SVR_HOST);
	nextblocksize=0;
	//ui.pushContinue->setEnabled(FALSE);

	ui.pushReview->setEnabled(FALSE);
	ui.pushContinue->setFocusPolicy(Qt::NoFocus);
	ui.pushBack->setFocusPolicy(Qt::NoFocus);
	//ui.pushBack->setEnabled(FALSE);

	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("Πελάτης")<<trUtf8("Πιν.1")<<trUtf8("Πιν.2")<<trUtf8("Κιλά")<<trUtf8("")<<trUtf8("Επιλεγμένο"));

	ui.tableWidget->setColumnWidth(0,0);
	ui.tableWidget->setColumnWidth(1,150);
	ui.tableWidget->setColumnWidth(2,50);
	ui.tableWidget->setColumnWidth(3,45);
	ui.tableWidget->setColumnWidth(4,45);
	ui.tableWidget->setColumnWidth(5,0);
	ui.tableWidget->setColumnWidth(6,25);
	//client = new QTcpSocket;
	//client->connectToHost(addr, 8888);
	connect(client, SIGNAL(readyRead()),this, SLOT(startread()));
	connect(ui.pushReview,SIGNAL(clicked()), this, SLOT(review()));
	connect(ui.pushContinue,SIGNAL(clicked()), this, SLOT(next()));
	connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));
		//connect(this,SIGNAL(activated()),this,SLOT(back()));
	connect(ui.tableWidget,SIGNAL(cellClicked(int ,int )),this, SLOT(tableclicked(int,int)));
			//connect(client, SIGNAL(connected()),this, SLOT(requestCustomers()));
	requestproFortoseis(pccode);

}

fortosi_new_1a::~fortosi_new_1a()
{

}

void fortosi_new_1a::startread()
 {
	 QDataStream in(client);
	 in.setVersion(QDataStream::Qt_4_1);
	 int r=0;

	 forever
	 	{
	 		if (nextblocksize==0) {

	 			if (client->bytesAvailable()<sizeof(quint16))
	 				break;
	 		in >> nextblocksize;


	 		}

	 		if (nextblocksize==0xFFFF)
	 		{
	 			// client->close();
	 			break;
	 		}

	 		if (client->bytesAvailable()<nextblocksize)
	 			break;
	 		QString	cname="",ccode="";
	 		QString car1,car2,weight,id;
	 		in >> ccode >> cname>> car1 >> car2 >> weight>> id;
	 		QTableWidgetItem *z=new QTableWidgetItem;
	 		QTableWidgetItem *a=new QTableWidgetItem;
	 		QTableWidgetItem *b=new QTableWidgetItem;
	 		QTableWidgetItem *c=new QTableWidgetItem;
	 		QTableWidgetItem *d=new QTableWidgetItem;
	 		QTableWidgetItem *e=new QTableWidgetItem;
	 		QTableWidgetItem *f=new QTableWidgetItem;
			z->setText(ccode);
	 		a->setText(cname);
	 		b->setText(car1);
	 		c->setText(car2);
	 		d->setText(weight);
	 		e->setText(id);


	 		z->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		c->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		d->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		e->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

	 		ui.tableWidget->setRowCount(r+1);
	 		ui.tableWidget->setItem(r,0,z);
	 		ui.tableWidget->setItem(r,1,a);
	 		ui.tableWidget->setItem(r,2,b);
	 		ui.tableWidget->setItem(r,3,c);
	 		ui.tableWidget->setItem(r,4,d);
	 		ui.tableWidget->setItem(r,5,e);
	 		ui.tableWidget->setItem(r,6,f);
	 		ui.tableWidget->setCellWidget(r,6,new QCheckBox());



	 		++r;

	 		//qDebug() << req_type;
	 		nextblocksize=0;
	 	}

}

void fortosi_new_1a::requestproFortoseis(QString customer)
 {
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="PRFC";
	out << quint16(0)<<req_type<<customer;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
 }

void fortosi_new_1a::review()
{
	//QString fsid=ui.tableWidget->item(rowsel,4)->text();
	//fortosi_progress_1_1 *w = new fortosi_progress_1_1(this,fsid);
	//qDebug()<<"FSID:"<<fsid;
	//w->move(0,0);
	//w->show();
}

void fortosi_new_1a::next()
{
	QString fsid="";
	for (int i=0;i<ui.tableWidget->rowCount();++i)
	{

		QWidget *t= ui.tableWidget->cellWidget(i,6);
		QCheckBox* u;
		u=(QCheckBox*)t;
		if (u->checkState()==2)
		{
			fsid=ui.tableWidget->item(i,5)->text();
		}

	}
	if (fsid=="")
		fsid="NULL";

    fortosi_new_1_b *w = new fortosi_new_1_b(this->parent,pccode,pcustomer,pcar1,pcar2);
	w->move(0,0);
	w->show();
	delete(this);

}

void fortosi_new_1a::tableclicked(int row,int col)
{
	ui.pushContinue->setEnabled(TRUE);
	ui.pushReview->setEnabled(TRUE);
	rowsel=row;
}

void fortosi_new_1a::back()
{
	delete(this);

}

