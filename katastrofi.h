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
#ifndef KATASTROFI_H
#define KATASTROFI_H

#include <QtGui/QDialog>
#include "ui_katastrofi.h"
#include <QtGui/QWidget>
#include <QtGui/QMessageBox>
#include <QtNetwork>
#include "constants.h"

class katastrofi : public QDialog
{
    Q_OBJECT

public:
    katastrofi(QWidget *parent = 0);
    ~katastrofi();

private:
    Ui::katastrofiClass ui;
    int r;

	QTcpSocket *client;

	QString lastscanned;

	void create_row(QString code_t,QString code_a);
    virtual bool eventFilter(QEvent *event);
	QString ver_code;
	QStringList confirmed;



private slots:
	void scan();
	void insert_db();
	void lock();
	void close_now();
};

#endif // KATASTROFI_H
