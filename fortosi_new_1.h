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
#ifndef FORTOSI_NEW_1_H
#define FORTOSI_NEW_1_H

#include <QtGui/QDialog>
//#include <QtSql>
#include "ui_fortosi_new_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include "fortosi_new_1_b.h"
#include "sxpf.h"






class fortosi_new_1 : public QDialog
{
    Q_OBJECT

public:
    //QSqlDatabase db;
    //QSqlDatabase db1;
    fortosi_new_1(QWidget *parent = 0);
    ~fortosi_new_1();
    Ui::fortosi_new_1Class ui;
    QString ccode,customer,car1,car2,prfid;



private:
    //Ui::fortosi_new_1Class ui;
    void start(QString address, quint16 port);

    void readCustomers();
    void startTransfer();
    QWidget *parent;
    //QTcpSocket *client;
    QString customers;
    QTcpSocket *client;
    quint16 blockSize;
    quint16 nextblocksize;
    int rowsel;
    QString lang;
    int r;



private slots:
	void startread();
	void requestCustomers();
	void next();
	void back();
	void tableclicked(int row,int col);
	void prof();
	void onTypeChar();
	void change_language(int state);

};

#endif // FORTOSI_NEW_1_H
