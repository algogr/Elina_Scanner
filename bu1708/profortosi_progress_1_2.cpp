#include "profortosi_progress_1_2.h"
#include "stdio.h"
#include <iostream>
using namespace std;


profortosi_progress_1_2::profortosi_progress_1_2(QWidget *parent,QTcpSocket *client,QString fid)
    : QDialog(parent)
{
	this->client=client;
	ui.setupUi(this);
	profortosi_id=fid;
	QHostAddress addr((QString)SVR_HOST);

	nextblocksize=0;
	r=0;

	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setColumnCount(1);
	ui.pushDelete->setEnabled(FALSE);

	ui.pushCancel->setFocusPolicy(Qt::NoFocus);
	ui.finalPush->setFocusPolicy(Qt::NoFocus);
	ui.pushDelete->setFocusPolicy(Qt::NoFocus);
	ui.tempPush->setFocusPolicy(Qt::NoFocus);

	connect(ui.lineScan, SIGNAL(returnPressed()), this, SLOT(scan()));
	connect(ui.finalPush, SIGNAL(clicked()), this, SLOT(finalize()));
	connect(ui.tempPush, SIGNAL(clicked()), this, SLOT(temporary()));
	connect(ui.pushCancel, SIGNAL(clicked()), this, SLOT(back()));
		//connect(ui.tableWidget, SIGNAL(cellClicked(int row,int column)), this, SLOT(cellclicked()));
	connect(ui.pushDelete, SIGNAL(clicked()), this, SLOT(delrow()));
	connect(ui.tableWidget, SIGNAL(pressed(const QModelIndex &)), this,SLOT(cellclicked()));


	connect(client, SIGNAL(readyRead()),this, SLOT(startread()));
	requestproFortosi();


}

profortosi_progress_1_2::~profortosi_progress_1_2()
{

}

void profortosi_progress_1_2::startread()
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
	 			break;
	 		}

	 		if (client->bytesAvailable()<nextblocksize)
	 			break;
	 		QString	cname="";
	 		QString code_t,sweight;
	 		in >> cname>>code_t>>sweight ;
	 		ui.labelCustomer->setText(cname);
	 		customer=cname;
	 		ui.labelWeight->setText(sweight);
	 		weight=sweight.toInt();
	 		QTableWidgetItem *a=new QTableWidgetItem;


	 		a->setText(code_t);


	 		a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);


	 		ui.tableWidget->setRowCount(r+1);
	 		ui.tableWidget->setItem(r,0,a);





	 		r++;

	 		//qDebug() << req_type;
	 		nextblocksize=0;
	 	}

}

void profortosi_progress_1_2::requestproFortosi()
 {
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="PRS";
	out << quint16(0)<<req_type<<QString(profortosi_id);
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
 }


void profortosi_progress_1_2::back()
{
	delete(this);
}

void profortosi_progress_1_2::scan()
{
	QString scanned=ui.lineScan->text();
	if (scanned.left(1)=="A"){
		//printf("\a");
		cout <<"\a";
		ui.lineScan->setText("");
		ui.lineScan->setFocus();
	}

	if (scanned.mid(12,1)=="Y"){
		cout <<"\a";
		ui.lineScan->setText("");
		ui.lineScan->setFocus();
	}

	if (scanned.mid(12,1)=="Z"){
		cout <<"\a";
		ui.lineScan->setText("");
		ui.lineScan->setFocus();
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
	ui.lineScan->setText("");
	ui.lineScan->setFocus();
	++r;
}

void profortosi_progress_1_2::finalize()
{
		QHostAddress addr((QString)SVR_HOST);

		QTcpSocket *client = new QTcpSocket;
		client->connectToHost(addr, 8888);
		qDebug() <<"R="<< r;
		for (int i=0;i<r;++i)
		{
		QByteArray block;
		QDataStream out(&block,QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type="PSF";
		out << quint16(0)<<req_type<<customer<<ui.tableWidget->item(i,0)->text()<<ui.labelWeight->text()<<profortosi_id;
		out.device()->seek(0);
		out<<quint16(block.size()-sizeof(quint16));
		client->write(block);
		}
		QByteArray block;
		QDataStream out(&block,QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		out<<quint16(0xFFFF);
		client->write(block);
		delete(this);


}

void profortosi_progress_1_2::temporary()
{
	QHostAddress addr((QString)SVR_HOST);

	QTcpSocket *client = new QTcpSocket;
	client->connectToHost(addr, 8888);
	for (int i=0;i<r;++i)
	{
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="ST";
	out << quint16(0)<<req_type<<customer<<ui.tableWidget->item(i,0)->text()<<ui.labelWeight->text()<<profortosi_id;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
	}
	QByteArray block1;
	QDataStream out1(&block1,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1<<quint16(0xFFFF);
	client->write(block1);
	//
	delete(this);

}

void profortosi_progress_1_2::cellclicked()
{
	ui.pushDelete->setEnabled(TRUE);
}

void profortosi_progress_1_2::delrow()
{
	int r1=ui.tableWidget->currentRow();
	weight-=ui.tableWidget->item(r1,0)->text().toInt();
	QVariant sweight=weight;
	ui.labelWeight->setText(sweight.toString());
	ui.tableWidget->removeRow(r1);
	r-=1;
	ui.pushDelete->setEnabled(FALSE);
	ui.lineScan->setFocus();
}



