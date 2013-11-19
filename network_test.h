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
 * network_test.h
 *
 *  Created on: Jul 6, 2011
 *      Author: jim
 */

#ifndef NETWORK_TEST_H_
#define NETWORK_TEST_H_

#include <QtGui/QWidget>
#include <QtNetwork>
#include <QTimer>
#include "constants.h"

class network_test:public QObject
{
	Q_OBJECT
public:
	network_test(QString ip="A", int port=0,QWidget *widget=0);
	virtual ~network_test();

private:
	QTcpSocket *test;
	QTimer *timer;
	QString ip;
	QWidget *widget;
	int port;

private slots:
	void check_conn();
	void error();
};

#endif /* NETWORK_TEST_H_ */
