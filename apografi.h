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

#ifndef APOGRAFI_H
#define APOGRAFI_H

#include <QtGui/QWidget>
#include <QtGui/QMessageBox>
#include <QtNetwork>
#include "ui_apografi.h"
#include "constants.h"

class apografi : public QDialog
{
    Q_OBJECT

public:
    apografi(QWidget *parent = 0,int mode=0);
    ~apografi();

private:
    Ui::apografiClass ui;
    int r;
    int mode;
    // 0 arxiki, 1 kanoniki


    QString lastscanned;


    virtual bool eventFilter(QObject *object, QEvent *event);
    QString ver_code;
    QStringList confirmed;
    bool iska;


private slots:
	void scan();
	void insert_db();
	void lock();



};

#endif // APOGRAFI_H
