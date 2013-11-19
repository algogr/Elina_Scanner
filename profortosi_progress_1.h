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
#ifndef PROFORTOSI_PROGRESS_1_H
#define PROFORTOSI_PROGRESS_1_H

#include <QtGui/QDialog>
#include "ui_profortosi_progress_1.h"
#include <QtNetwork>
#include <QString>
#include <QTcpSocket>
#include "constants.h"
#include "profortosi_progress_1_1.h"
#include "profortosi_progress_1_2.h"


class profortosi_progress_1 : public QDialog
{
    Q_OBJECT

public:
    profortosi_progress_1(QWidget *parent = 0);
    ~profortosi_progress_1();
    QTcpSocket *client;

private:
    Ui::profortosi_progress_1Class ui;
    quint16 nextblocksize;
	int rowsel;
	void requestFortoseis();


private slots:
	void continious();
	void review();
	void back();
	void startread();
	void tableclicked(int row,int col);
	void delete_pf();

};

#endif // PROFORTOSI_PROGRESS_1_H
