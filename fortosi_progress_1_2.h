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
#ifndef FORTOSI_PROGRESS_1_2_H
#define FORTOSI_PROGRESS_1_2_H

#include <QtGui/QDialog>
#include "ui_fortosi_progress_1_2.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QSound>
#include <QTcpSocket>
#include "constants.h"


class fortosi_progress_1_2 : public QDialog
{
    Q_OBJECT

public:
    fortosi_progress_1_2(QWidget *parent = 0,QString fid=0);
    ~fortosi_progress_1_2();


private:
    Ui::fortosi_progress_1_2Class ui;
    QString fortosi_id;
    quint16 nextblocksize;
    QString customer,prfid;
    int weight;
    int r;
    void requestFortosi();
    QTcpSocket *client;
    QStringList reply;
	int readmode;
	void disable_controls();
	void enable_controls();
	QDataStream in;


private slots:
	void startread();
	void scan();
	void finalize();
	void temporary();
	void back();
	void delrow();
	void cellclicked();
	void check();


};

#endif // FORTOSI_PROGRESS_1_2_H
