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
#ifndef FORTOSI_PROGRESS_1_H
#define FORTOSI_PROGRESS_1_H

#include <QtGui/QDialog>
#include "ui_fortosi_progress_1.h"
#include <QtNetwork>
#include <QString>
#include <QTcpSocket>
#include "constants.h"
#include "fortosi_progress_1_1.h"
#include "fortosi_progress_1_2.h"


class fortosi_progress_1 : public QDialog
{
    Q_OBJECT

public:
    fortosi_progress_1(QWidget *parent = 0);
    ~fortosi_progress_1();
    QTcpSocket *client;

private:
    Ui::fortosi_progress_1Class ui;
    quint16 nextblocksize;
    int rowsel;
    void requestFortoseis();


private slots:
	void continious();
	void review();
	void back();
	void startread();
	void tableclicked(int row,int col);
	void delete_f();
};

#endif // FORTOSI_PROGRESS_1_H
