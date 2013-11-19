#include "fortosi_new_1_1.h"
#include "stdio.h"
#include <iostream>
#include <QHostAddress>
using namespace std;

fortosi_new_1_1::fortosi_new_1_1(QWidget *parent,QTcpSocket *pclient,QString ccode,QString customer,QString car1,QString car2,QString fid)
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
	ui.finalPush->setFocusPolicy(Qt::NoFocus);
	ui.devPush->setFocusPolicy(Qt::NoFocus);
	ui.back->setFocusPolicy(Qt::NoFocus);
	ui.labelWeight->setText("0");
	ui.tableWidget->setColumnCount(1);
	ui.tableWidget->setRowCount(0);
	ui.lineEdit->setFocus();
	ui.tableWidget->setColumnWidth(0,200);
	connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(scan()));
	connect(ui.finalPush, SIGNAL(clicked()), this, SLOT(finalize()));
	connect(ui.devPush, SIGNAL(clicked()), this, SLOT(temporary()));
	connect(ui.back, SIGNAL(clicked()), this, SLOT(back()));
	//connect(ui.tableWidget, SIGNAL(cellClicked(int row,int column)), this, SLOT(cellclicked()));
	connect(ui.pushdelrow, SIGNAL(clicked()), this, SLOT(delrow()));
	connect(ui.tableWidget, SIGNAL(pressed(const QModelIndex &)), this,SLOT(cellclicked(const QModelIndex &)));
}

fortosi_new_1_1::~fortosi_new_1_1()
{

}

void fortosi_new_1_1::scan()
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
		ui.lineEdit->setText("");
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

void fortosi_new_1_1::back()
{
	delete(this);
}

void fortosi_new_1_1::finalize()
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

void fortosi_new_1_1::temporary()
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

void fortosi_new_1_1::cellclicked(const QModelIndex &)
{
	ui.pushdelrow->setEnabled(TRUE);
}

void fortosi_new_1_1::delrow()
{
	int r1=ui.tableWidget->currentRow();
	weight-=ui.tableWidget->item(r1,0)->text().toInt();
	QVariant sweight=weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->removeRow(r1);
	r-=1;
	ui.pushdelrow->setEnabled(FALSE);
	ui.lineEdit->setFocus();
}
