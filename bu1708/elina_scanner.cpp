#include "elina_scanner.h"

Elina_Scanner::Elina_Scanner(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(fortosi()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(profortosi()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(apografi_s()));


	QHostAddress addr((QString)SVR_HOST);
	client = new QTcpSocket;
	//connect(client,SIGNAL(connected()),this,SLOT(error()));
	//	connect(client,SIGNAL(disconnected()),this,SLOT(error()));
		//connect(client,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(error()));
	connect(client, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(error()));
	client->connectToHost(addr, 8889);

	//sleep(5);

	//if (client->state()!=QAbstractSocket::ConnectedState)
	//{
		//exit(0);
	//}
	//QApplication::beep();

	//connect(client, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(error()));
}

Elina_Scanner::~Elina_Scanner()
{

}

void Elina_Scanner::fortosi()
{
	fortosi_sel *w=new fortosi_sel(this,client);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::profortosi()
{
	profortosi_sel *w=new profortosi_sel(this,client);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::apografi_s()
{
	apografi *w=new apografi(this,client,0);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::error()
{
	//QHostAddress addr((QString)SVR_HOST);
	//forever
	//{
		//client->connectToHost(addr,8889);
		//if(client)
			//return;
	//}
	//qDebug()<<"LALAQLALA:"<<client->state();
	//delete (this);
	QMessageBox m;
	m.setText(trUtf8("Δεν υπάρχει σύνδεση στο δίκτυο"));
	m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
	m.setStandardButtons(QMessageBox::Ok);
	m.move(100,100);
	m.exec();
	forever
	{
		bool test=client->isOpen();
		qDebug()<< "TEST:" << test;
		QHostAddress addr((QString)SVR_HOST);
		client->connectToHost(addr, 8889);
		if (test==TRUE)
			break;
	}


}
