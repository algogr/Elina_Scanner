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
#ifndef FORTOSI_NEW_1A_H
#define FORTOSI_NEW_1A_H

#include <QtGui/QWidget>
#include "ui_fortosi_new_1a.h"
#include <QtNetwork>
#include <QCheckBox>
#include <QString>
#include <QTcpSocket>
#include "constants.h"
#include "fortosi_new_1_b.h"


class fortosi_new_1a : public QWidget
{
    Q_OBJECT

public:
    fortosi_new_1a(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="", QString car1="",QString car2="");
    ~fortosi_new_1a();

private:
    Ui::fortosi_new_1aClass ui;
    quint16 nextblocksize;
    int rowsel;
	void requestFortoseis(QString customer="",QString car1="",QString car2="");
	QWidget *parent;
	QString pccode;
	QString pcustomer;
	QString pcar1;
	QString pcar2;
	QTcpSocket *client;
	void requestproFortoseis(QString customer);

private slots:
	void next();
	void review();
	void back();
	void startread();
	void tableclicked(int row,int col);

};

#endif // FORTOSI_NEW_1A_H
