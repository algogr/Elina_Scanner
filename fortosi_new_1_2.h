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
#ifndef FORTOSI_NEW_1_2_H
#define FORTOSI_NEW_1_2_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_2.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QSound>
#include <QTcpSocket>
#include "constants.h"
class fortosi_new_1_2 : public QDialog
{
    Q_OBJECT

public:
    fortosi_new_1_2(QWidget *parent = 0,QString ccode="",QString customer="",QString car1="",QString car2="",QString prfid="0");
    ~fortosi_new_1_2();
    QString ccode;
    QString customer;
	QString car1;
	QString car2;
	QString prfid;
	QTcpSocket *client;
	quint16 blockSize;
	quint16 nextblocksize;

private slots:
	void startreadItems();
	//void itemchanged();
	void scan();
	void finalize();
	void temporary();
	void back();
	void delrow();
	void cellclicked(const QModelIndex &);
	void tableclicked(int row,int column);
	void requestItems();
	void check();
	void compare();
	void startread();

private:
    Ui::fortosi_new_1_2Class ui;
    int r;
    int weight;
    void requestDetails();
    QStringList reply;
    int rowsel;
    int readmode;




};

#endif // FORTOSI_NEW_1_2_H
