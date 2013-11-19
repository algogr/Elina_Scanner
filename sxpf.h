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
#ifndef SXPF_H
#define SXPF_H

#include <QtGui/QDialog>
#include <QtNetwork>
#include "ui_sxpf.h"
#include "constants.h"
#include "fortosi_new_1.h"
class fortosi_new_1;

class sxpf : public QDialog
{
    Q_OBJECT

public:
    sxpf(QWidget *parent,fortosi_new_1 *f);
    ~sxpf();
    QTcpSocket *client;

private:
    Ui::sxpfClass ui;
    quint16 nextblocksize;
    void request_pro();
    fortosi_new_1 *f;
    int selected_row;

private slots:
	void startread();
	void close();
	void row_selected(int x,int y);

};

#endif // SXPF_H
