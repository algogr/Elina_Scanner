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
#ifndef FORTOSI_NEW_1_B_H
#define FORTOSI_NEW_1_B_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_b.h"
#include "fortosi_new_1_1.h"
#include "fortosi_new_1_2.h"
#include <QtNetwork>
#include <QTcpSocket>

class fortosi_new_1_b : public QDialog
{
    Q_OBJECT

public:
    fortosi_new_1_b(QWidget *parent = 0,QString ccode="",QString customer="", QString car1="",QString car2="",QString prfid="0");
    ~fortosi_new_1_b();
    QWidget *parent;
    QString ccode;
    QString customer;
    QString car1;
    QString car2;
    QString prfid;


private:
    Ui::fortosi_new_1_bClass ui;

private slots:
	void back();
	void loop();
	void code();

};

#endif // FORTOSI_NEW_1_B_H
