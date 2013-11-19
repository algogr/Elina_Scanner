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
#include "profortosi_progress_1.h"

profortosi_progress_1::profortosi_progress_1(QWidget *parent) :
	QDialog(parent) {
	ui.setupUi(this);

	QString ipath = (QString) APATH + "/img/app.png";
	QIcon *icon = new QIcon(ipath);

	this->setWindowIcon(*icon);

	QHostAddress addr((QString) SVR_HOST);
	nextblocksize = 0;
	ui.pushContinue->setEnabled(FALSE);
	ui.pushReview->setEnabled(FALSE);
	ui.pushDelete->setEnabled(FALSE);

	ui.tableWidget->setColumnCount(5);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList()
			<< trUtf8("Πελάτης") << trUtf8("Πιν.1") << trUtf8("Πιν.2")
			<< trUtf8("Κιλά"));

	ui.tableWidget->setColumnWidth(0, 150);
	ui.tableWidget->setColumnWidth(1, 50);
	ui.tableWidget->setColumnWidth(2, 50);
	ui.tableWidget->setColumnWidth(3, 50);
	ui.tableWidget->setColumnWidth(4, 0);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
	connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
	connect(ui.pushReview, SIGNAL(clicked()), this, SLOT(review()));
	connect(ui.pushContinue, SIGNAL(clicked()), this, SLOT(continious()));
	connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.pushDelete, SIGNAL(clicked()), this, SLOT(delete_pf()));
	//connect(this,SIGNAL(activated()),this,SLOT(back()));
	connect(ui.tableWidget, SIGNAL(cellClicked(int ,int )), this,
			SLOT(tableclicked(int,int)));
	//connect(client, SIGNAL(connected()),this, SLOT(requestCustomers()));
	requestFortoseis();

}

profortosi_progress_1::~profortosi_progress_1() {
	client->disconnectFromHost();

}

void profortosi_progress_1::startread() {
	QDataStream in(client);
	in.setVersion(QDataStream::Qt_4_1);
	int r = 0;

	forever {
		if (nextblocksize == 0) {

			if (client->bytesAvailable() < sizeof(quint16))
				break;
			in >> nextblocksize;

		}

		if (nextblocksize == 0xFFFF) {
			//client->close();
			break;
		}

		if (client->bytesAvailable() < nextblocksize)
			break;
		QString cname = "";
		QString car1, car2, weight, id;
		in >> cname >> car1 >> car2 >> weight >> id;
		QTableWidgetItem *a = new QTableWidgetItem;
		QTableWidgetItem *b = new QTableWidgetItem;
		QTableWidgetItem *c = new QTableWidgetItem;
		QTableWidgetItem *d = new QTableWidgetItem;
		QTableWidgetItem *e = new QTableWidgetItem;

		a->setText(cname);
		b->setText(car1);
		c->setText(car2);
		d->setText(weight);
		e->setText(id);

		a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		c->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		d->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		e->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

		ui.tableWidget->setRowCount(r + 1);
		ui.tableWidget->setItem(r, 0, a);
		ui.tableWidget->setItem(r, 1, b);
		ui.tableWidget->setItem(r, 2, c);
		ui.tableWidget->setItem(r, 3, d);
		ui.tableWidget->setItem(r, 4, e);

		++r;

		//qDebug() << req_type;
		nextblocksize = 0;
	}

}

void profortosi_progress_1::requestFortoseis() {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "PRF";
	out << quint16(0) << req_type;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
}

void profortosi_progress_1::review() {
	QString fsid = ui.tableWidget->item(rowsel, 4)->text();
	profortosi_progress_1_1 *w =
			new profortosi_progress_1_1(this, client, fsid);
	qDebug() << "FSID:" << fsid;
	w->move(0, 0);
	w->show();
}

void profortosi_progress_1::continious() {
	QString fsid = ui.tableWidget->item(rowsel, 4)->text();
	profortosi_progress_1_2 *w = new profortosi_progress_1_2(this, fsid);
	w->move(0, 0);
	w->show();

}

void profortosi_progress_1::tableclicked(int row, int col) {
	ui.pushContinue->setEnabled(TRUE);
	ui.pushReview->setEnabled(TRUE);
	ui.pushDelete->setEnabled(TRUE);
	rowsel = row;
}

void profortosi_progress_1::delete_pf() {
	QMessageBox m;
	m.setText(trUtf8("Διαγραφή Προφόρτωσης;"));

	QAbstractButton *acc = m.addButton(trUtf8("Επιβεβαίωση"),
			QMessageBox::ActionRole);
	QAbstractButton *rej = m.addButton(trUtf8("Aκύρωση"),
			QMessageBox::ActionRole);

	m.move(0, 100);
	QFont serifFont("Times", 18, QFont::Bold);
	m.setFont(serifFont);

	m.exec();
	if (m.clickedButton() == acc) {

		int r1 = ui.tableWidget->currentRow();
		QString fsid = ui.tableWidget->item(rowsel, 4)->text();
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_1);
		QString req_type = "DELPRF";
		out << quint16(0) << req_type << fsid;
		out.device()->seek(0);
		out << quint16(block.size() - sizeof(quint16));
		client->write(block);
		ui.tableWidget->removeRow(r1);
		ui.pushDelete->setEnabled(FALSE);
		ui.pushContinue->setEnabled(FALSE);
		ui.pushReview->setEnabled(FALSE);

	}

}

void profortosi_progress_1::back() {
	delete (this);

}

