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
