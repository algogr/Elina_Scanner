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
#ifndef PROFORTOSI_SEL_H
#define PROFORTOSI_SEL_H

#include <QtGui/QDialog>
#include "ui_profortosi_sel.h"
#include "profortosi_new_1.h"
#include "profortosi_progress_1.h"
#include <QtNetwork>
#include <QTcpSocket>


class profortosi_sel : public QDialog
{
    Q_OBJECT

public:
    profortosi_sel(QWidget *parent = 0);
    ~profortosi_sel();


private:
    Ui::profortosi_selClass ui;

private slots:
	void new_profortosi();
	void progress_profortosi();
};

#endif // PROFORTOSI_SEL_H
