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
#ifndef FORTOSI_PROGRESS_1_1_H
#define FORTOSI_PROGRESS_1_1_H

#include <QtGui/QDialog>
#include "ui_fortosi_progress_1_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QTcpSocket>

class fortosi_progress_1_1 : public QDialog
{
    Q_OBJECT

public:
    fortosi_progress_1_1(QWidget *parent = 0,QTcpSocket *client=0,QString fid="");
    ~fortosi_progress_1_1();


private:
    Ui::fortosi_progress_1_1Class ui;
    QString fortosi_id;
    quint16 nextblocksize;
    void requestFortosi();
    QTcpSocket *client;
    int r;

private slots:
	void startread();
	void back();

};

#endif // FORTOSI_PROGRESS_1_1_H
