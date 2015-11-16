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
#ifndef FORTOSI_SEL_H
#define FORTOSI_SEL_H

#include <QtGui/QDialog>
#include "ui_fortosi_sel.h"
#include "fortosi_new_1.h"
#include "fortosi_progress_1.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "constants.h"
#include "elina_scanner.h"
class Elina_Scanner;
class fortosi_sel : public QDialog
{
    Q_OBJECT

public:
    fortosi_sel(QWidget *parent = 0);
    ~fortosi_sel();
    Elina_Scanner *p;
    void send_fortosi(int n);

private:
    Ui::fortosi_selClass ui;
    QTcpSocket *client;
    quint16 nextblocksize;

private slots:
	void new_fortosi();
	void progress_fortosi();
    void retransmit_fortosi();
    void ready_read();
};

#endif // FORTOSI_SEL_H
