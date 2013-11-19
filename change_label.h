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
#ifndef CHANGE_LABEL_H
#define CHANGE_LABEL_H

#include <QtGui/QDialog>
#include "ui_change_label.h"
#include <QtNetwork>
#include "constants.h"


class change_label : public QDialog
{
    Q_OBJECT

public:
    change_label(QWidget *parent = 0);
    ~change_label();

private:
    Ui::change_labelClass ui;
    QTcpSocket *client;

private slots:
	void send_change();
	void scan_old();
	void scan_new();
};

#endif // CHANGE_LABEL_H
