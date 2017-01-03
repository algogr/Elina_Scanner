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
#ifndef FORTOSI_NEW_1_1_H
#define FORTOSI_NEW_1_1_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_1.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QSound>

#include <QTcpSocket>
#include "constants.h"


class fortosi_new_1_1 : public QDialog
{

    Q_OBJECT

public:
    fortosi_new_1_1(QWidget *parent = 0,const QString &ccode="",const QString &customer="",const QString &car1="",const QString &car2="");
    ~fortosi_new_1_1();
    QString ccode;
    QString customer;
    QString car1;
    QString car2;
    QTcpSocket *client;
    quint16 nextblocksize;

private:
    Ui::fortosi_new_1_1Class ui;
    int r;
    int weight;
    QStringList reply;
    int readmode;
    void disable_controls();
    void enable_controls();

private slots:
	void scan();
	void finalize();
	void temporary();
	void back();
	void cellclicked(const QModelIndex &);
	void delrow();
	void check();

	void startread();
    void lineeditclicked();
};

#endif // FORTOSI_NEW_1_1_H
