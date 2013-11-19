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
#ifndef PROFORTOSI_PROGRESS_1_1_H
#define PROFORTOSI_PROGRESS_1_1_H

#include <QtGui/QDialog>
#include "ui_profortosi_progress_1_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QTcpSocket>

class profortosi_progress_1_1 : public QDialog
{
    Q_OBJECT

public:
    profortosi_progress_1_1(QWidget *parent = 0,QTcpSocket *client=0,QString fid="");
    ~profortosi_progress_1_1();

private:
    Ui::profortosi_progress_1_1Class ui;
    QString profortosi_id;
	quint16 nextblocksize;
	void requestproFortosi();
	QTcpSocket *client;

private slots:
	void startread();
	void back();

};

#endif // PROFORTOSI_PROGRESS_1_1_H
