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
#ifndef PROFORTOSI_NEW_1_2_H
#define PROFORTOSI_NEW_1_2_H

#include <QtGui/QDialog>
#include "ui_profortosi_new_1_2.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QSound>
#include <QTcpSocket>
#include "constants.h"


class profortosi_new_1_2 : public QDialog
{
    Q_OBJECT

public:
    profortosi_new_1_2(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="",QString car1="",QString car2="");
    ~profortosi_new_1_2();
    QWidget *parent;
    QString ccode;
    QString customer;
   	QString car1;
   	QString car2;
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
   	void requestItems();
   	void cellclicked(const QModelIndex &);
   	void tableclicked(int row,int column);


private:
    Ui::profortosi_new_1_2Class ui;
    int r;
	int weight;

	void requestDetails();
	int rowsel;
};

#endif // PROFORTOSI_NEW_1_2_H
