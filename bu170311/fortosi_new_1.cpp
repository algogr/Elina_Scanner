#include "fortosi_new_1.h"
#include <QHostAddress>


fortosi_new_1::fortosi_new_1(QWidget *parent)
    : QDialog(parent)
{

	ui.setupUi(this);

	QHostAddress addr((QString)SVR_HOST);
	nextblocksize=0;
	client = new QTcpSocket;
    client->connectToHost(addr, 8888);
    connect(client, SIGNAL(readyRead()),this, SLOT(startread()));
    connect(ui.pushFront,SIGNAL(clicked()), this, SLOT(next()));
    connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));
	//connect(client, SIGNAL(connected()),this, SLOT(requestCustomers()));
    requestCustomers();




}

fortosi_new_1::~fortosi_new_1()
{

}

void fortosi_new_1::startTransfer()
{


}

void fortosi_new_1::requestCustomers()
 {
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="RC";
	out << quint16(0)<<req_type;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
 }

 void fortosi_new_1::startread()
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
	 			client->close();
	 			break;
	 		}

	 		if (client->bytesAvailable()<nextblocksize)
	 			break;
	 		QString	cname="";
	 		in >> cname;



	 		ui.comboBox->insertItem(r,cname);

	 		++r;

	 		//qDebug() << req_type;
	 		nextblocksize=0;
	 	}

 }

 void fortosi_new_1::next()
 {
	 QString customer= ui.comboBox->currentText();
	 QString car1=ui.lineEdit->text();
	 QString car2=ui.lineEdit_2->text();
	 fortosi_new_1_b *w= new fortosi_new_1_b(0,customer,car1,car2);
	 w->move(0,0);
	 w->show();


 }

 void fortosi_new_1::back()
 {
	 delete(this);
 }


