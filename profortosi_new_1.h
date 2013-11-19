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
#ifndef PROFORTOSI_NEW_1_H
#define PROFORTOSI_NEW_1_H

#include <QtGui/QDialog>
#include "ui_profortosi_new_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include "profortosi_new_1_b.h"
#include "constants.h"

class profortosi_new_1 : public QDialog
{
    Q_OBJECT

public:
    profortosi_new_1(QWidget *parent = 0);
    ~profortosi_new_1();
    QTcpSocket *client;

private:
    Ui::profortosi_new_1Class ui;
    void start(QString address, quint16 port);

	void readCustomers();
	void startTransfer();
	//QTcpSocket *client;
	QString customers;
	quint16 blockSize;
	quint16 nextblocksize;
	int rowsel;
	QString lang;

    private slots:
    	void startread();
    	void requestCustomers();
    	void next();
    	void back();
    	void tableclicked(int row,int col);
    	void change_language(int state);
    	void onTypeChar();
};

#endif // PROFORTOSI_NEW_1_H
