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
#ifndef ELINA_SCANNER_H
#define ELINA_SCANNER_H

#include <QtGui/QDialog>
#include "ui_elina_scanner.h"
#include "fortosi_sel.h"
#include "apografi.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "constants.h"

#include "change_label.h"
#include "read_label.h"
#include "rewrap_sc.h"
#include "return_roll.h"


class Elina_Scanner : public QDialog
{
    Q_OBJECT

public:
    Elina_Scanner(QWidget *parent = 0);
    ~Elina_Scanner();
    QTcpSocket *client1;
    bool read_ap,write_ap;
    bool networkstatus;




private:
    Ui::Elina_ScannerClass ui;
    void create_row(QString code_t,QString code_a);
    void send_final_packet();
    QMap <QString,QString> records;
    QNetworkConfigurationManager *mgr;
    int ifino,apogrno;
    QString macaddress;
    void transmit_apografi();
    QNetworkReply* reply;
    QMessageBox apm;


private slots:
	void fortosi();
    void apografi_s();
	void katastrofi_s();
	void change_label_s();
	void read_label_s();
    void rewrap_label();
    void returnroll();
    void check_online();
    void check_state(QAbstractSocket::SocketState state);
    void send();
    void replyFinished(QNetworkReply* reply);


};

#endif // ELINA_SCANNER_H
