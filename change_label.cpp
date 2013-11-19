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
#include "change_label.h"
#include <QMessageBox>

change_label::change_label(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QHostAddress addr((QString)SVR_HOST);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
	ui.pushButton->setFocusPolicy(Qt::NoFocus);
	ui.pushButton->setEnabled(FALSE);
	connect (ui.pushButton,SIGNAL(released()),this,SLOT(send_change()));
	connect (ui.lineOld,SIGNAL(returnPressed()),this,SLOT(scan_old()));
	connect (ui.lineNew,SIGNAL(returnPressed()),this,SLOT(scan_new()));
}

change_label::~change_label()
{
	client->disconnectFromHost();
}

void change_label::send_change()
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "CHLAB";
	QString old_code=ui.lineOld->text();
	QString new_code=ui.lineNew->text();
	out << quint16(0) << req_type<<old_code<<new_code;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block1,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
	this->deleteLater();
}

void change_label::scan_old()
{
	QString scanned=ui.lineOld->text();
	QRegExp kt("\\d{12,12}[X-Z]\\d{2,2}");
		if (kt.exactMatch(scanned) == FALSE) {
			QMessageBox m;

			m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
			m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
			m.setStandardButtons(QMessageBox::Ok);
			m.move(0, 100);
			QFont serifFont("Times", 18, QFont::Bold);
			m.setFont(serifFont);
			m.exec();
			ui.lineOld->setText("");
			ui.lineOld->setFocus();
			return;

		}
		ui.lineNew->setFocus();
}

void change_label::scan_new()
{
	QString scanned=ui.lineNew->text();
	QRegExp kt("\\d{12,12}[X-Z]\\d{2,2}");
		if (kt.exactMatch(scanned) == FALSE) {
			QMessageBox m;

			m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
			m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
			m.setStandardButtons(QMessageBox::Ok);
			m.move(0, 100);
			QFont serifFont("Times", 18, QFont::Bold);
			m.setFont(serifFont);
			m.exec();
			ui.lineNew->setText("");
			ui.lineNew->setFocus();
            ui.pushButton->setEnabled(FALSE);
			return;

		}
        ui.pushButton->setEnabled(TRUE);
}


