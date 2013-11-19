/*
 * network_test.cpp
 *
 *  Created on: Jul 6, 2011
 *      Author: jim
 */

#include "network_test.h"

network_test::network_test(QString ip, int port,QWidget *widget) {
	// TODO Auto-generated constructor stub
	QTcpSocket *test=new QTcpSocket;
	this->test=test;
	this->widget=widget;
	this->ip=ip;
	this->port=port;

	this->timer= new QTimer;
	connect(timer, SIGNAL(timeout()), this, SLOT(check_conn()));
	connect(test, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(error()));
	timer->start(1000);

}

network_test::~network_test() {
	// TODO Auto-generated destructor stub
}

void network_test::check_conn()
{
		widget->setEnabled(TRUE);

		QHostAddress addr((QString)ip);
		test->connectToHost(addr,port);
		qDebug()<<"jim";
		test->close();

}

void network_test::error()
{

	widget->setEnabled(FALSE);
}
