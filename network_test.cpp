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
