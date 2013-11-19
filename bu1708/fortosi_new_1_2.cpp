#include "fortosi_new_1_2.h"
#include "stdio.h"
#include <iostream>
#include "ui_fortosi_new_1_2.h"
using namespace std;

fortosi_new_1_2::fortosi_new_1_2(QWidget *parent ,QTcpSocket *pclient,QString ccode,QString customer,QString car1,QString car2,QString fid)
    : QDialog(parent)
{
	client=pclient;
	this->ccode=ccode;
	this->customer=customer;
	this->car1=car1;
	this->car2=car2;
	this->fid=fid;

	ui.setupUi(this);
	r=0;
	weight=0;
	ui.finalButton->setFocusPolicy(Qt::NoFocus);
	ui.deleteButton->setFocusPolicy(Qt::NoFocus);
	ui.pushExit->setFocusPolicy(Qt::NoFocus);
	ui.pushTemp->setFocusPolicy(Qt::NoFocus);
	ui.labelWeight->setText("0");
	ui.tableWidget->setColumnCount(1);
	ui.tableWidget->setRowCount(0);
	ui.lineEdit->setFocus();
	ui.tableWidget->setColumnWidth(0,200);
	ui.tableWidget_2->setColumnCount(1);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("Κωδικοί Α"));
	ui.lineEdit_2->setText(trUtf8("Π"));


	nextblocksize=0;
	connect(client, SIGNAL(readyRead()),this, SLOT(startreadItems()));
	//connect(ui.comboBox, SIGNAL(currentIndexChanged()), this, SLOT(itemchanged()));
	connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(scan()));
	connect(ui.finalButton, SIGNAL(clicked()), this, SLOT(finalize()));
	connect(ui.pushTemp, SIGNAL(clicked()), this, SLOT(temporary()));
	connect(ui.pushExit, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(delrow()));
	connect(ui.tableWidget, SIGNAL(pressed(const QModelIndex &)), this,SLOT(cellclicked(const QModelIndex &)));
	connect(ui.tableWidget_2,SIGNAL(cellClicked(int ,int )),this, SLOT(tableclicked(int,int)));
	connect(ui.lineEdit_2, SIGNAL(textChanged(const QString &)), this,
		    			SLOT(requestItems()));
	ui.lineEdit_2->setFocus();
	requestItems();
}

fortosi_new_1_2::~fortosi_new_1_2()
{

}

void fortosi_new_1_2::requestItems()
 {
	QByteArray block;
	QString like=ui.lineEdit_2->text();
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="RI";
	out << quint16(0)<<req_type<<like;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
 }

void fortosi_new_1_2::requestDetails()
 {
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="IC";
	out << quint16(0)<<req_type;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
 }


void fortosi_new_1_2::startreadItems()
 {
	 QDataStream in(client);
	 in.setVersion(QDataStream::Qt_4_1);
	 int r=0;
	 ui.tableWidget->setRowCount(r);
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
	 			break;
	 		}

	 		if (client->bytesAvailable()<nextblocksize)
	 			break;
	 		QString	scode="";
	 		in >> scode;
			qDebug()<<scode;
	 		QTableWidgetItem *a=new QTableWidgetItem;
	 		a->setText(scode);
			a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		ui.tableWidget_2->setRowCount(r+1);
			ui.tableWidget_2->setItem(r,0,a);




	 		++r;

	 		//qDebug() << req_type;
	 		nextblocksize=0;
	 	}
			nextblocksize=0;

 }

void fortosi_new_1_2::scan()
{
	QString scanned=ui.lineEdit->text();
	if (scanned.left(1)=="A"){
		//printf("\a");
		cout <<"\a";
		ui.lineEdit->setText("");
		ui.lineEdit->setFocus();
	}

	if (scanned.mid(12,1)=="Y"){
		cout <<"\a";
		ui.lineEdit_2->setText("");
		ui.lineEdit->setFocus();
	}

	if (scanned.mid(12,1)=="Z"){
		cout <<"\a";
		ui.lineEdit->setText("");
		ui.lineEdit->setFocus();
	}
	weight+=scanned.left(3).toInt();
	QVariant sweight=weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->setRowCount(r+1);
	QTableWidgetItem *code=new QTableWidgetItem;
	if (r>0)
	code->setText(ui.tableWidget->item(r-1,0)->text());
	ui.tableWidget->setItem(r,0,code);



    for (int i=r-1;i>0;--i)
    {

    	ui.tableWidget->item(i,0)->setText(ui.tableWidget->item(i-1,0)->text());

    }
    ui.tableWidget->item(0,0)->setText(scanned);

	//ui.tableWidget->setItem(0,0,code);
	ui.lineEdit->setText("");
	ui.lineEdit->setFocus();
	r++;
}

void fortosi_new_1_2::back()
{
	delete(this);
}

void fortosi_new_1_2::finalize()
{
		//QHostAddress addr((QString)SVR_HOST);

		//QTcpSocket *client = new QTcpSocket;
		//client->connectToHost(addr, 8888);
		for (int i=0;i<r;++i)
		{
		QByteArray block;
		QDataStream out(&block,QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type="FP";
		out << quint16(0)<<req_type<<ccode<<customer<<car1<<car2<<ui.tableWidget->item(i,0)->text()<<ui.labelWeight->text()<<fid;
		out.device()->seek(0);
		out<<quint16(block.size()-sizeof(quint16));
		client->write(block);
		}
		QByteArray block1;
		QDataStream out1(&block1,QIODevice::WriteOnly);
		out1.setVersion(QDataStream::Qt_4_1);
		out1<<quint16(0xFFFF);
		client->write(block1);
		delete(this);


}

void fortosi_new_1_2::temporary()
{
	//QHostAddress addr((QString)SVR_HOST);

	//QTcpSocket *client = new QTcpSocket;
	///client->connectToHost(addr, 8888);
	for (int i=0;i<r;++i)
	{
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="FT";
	out << quint16(0)<<req_type<<ccode<<customer<<car1<<car2<<ui.tableWidget->item(i,0)->text()<<ui.labelWeight->text()<<fid;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
	}
	QByteArray block1;
	QDataStream out1(&block1,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1<<quint16(0xFFFF);
	client->write(block1);
	delete(this);

}

void fortosi_new_1_2::cellclicked(const QModelIndex &)
{
	ui.deleteButton->setEnabled(TRUE);
}

void fortosi_new_1_2::delrow()
{
	int r1=ui.tableWidget->currentRow();
	weight-=ui.tableWidget->item(r1,0)->text().toInt();
	QVariant sweight=weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->removeRow(r1);
	r-=1;
	ui.deleteButton->setEnabled(FALSE);
	ui.lineEdit->setFocus();
}

void fortosi_new_1_2::tableclicked(int row,int col)
 {

 	this->rowsel=row;
 }
























































