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
#include "profortosi_new_1.h"

profortosi_new_1::profortosi_new_1(QWidget *parent) :
	QDialog(parent) {
	ui.setupUi(this);

	QString ipath = (QString) APATH + "/img/prof.png";
	QIcon *icon = new QIcon(ipath);

	QString ipath1 = (QString) APATH + "/img/search.png";
	QIcon *icon1 = new QIcon(ipath1);
	ui.searchButton->setIcon(*icon1);

	this->setWindowIcon(*icon);
	ui.searchButton->setIcon(*icon);

	QHostAddress addr((QString) SVR_HOST);
	nextblocksize = 0;
	lang = "EL";

	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8(
			"Κωδ.Πελάτη") << trUtf8("Πελάτης"));
	ui.tableWidget->setColumnWidth(0, 0);
	ui.tableWidget->setColumnWidth(1, 280);

	connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
	connect(ui.pushFront, SIGNAL(clicked()), this, SLOT(next()));
	connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));

	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(requestCustomers()));
	connect(ui.tableWidget, SIGNAL(cellClicked(int ,int )), this,
			SLOT(tableclicked(int,int)));
	connect(ui.checkGreek, SIGNAL(stateChanged(int)), this,
			SLOT(change_language(int)));
	connect(ui.lineEdit_3, SIGNAL(textChanged(const QString &)), this,
			SLOT(onTypeChar()));

	//connect(client, SIGNAL(connected()),this, SLOT(requestCustomers()));
	ui.lineEdit_3->setFocus();
}

profortosi_new_1::~profortosi_new_1() {
	client->disconnectFromHost();

}

void profortosi_new_1::startTransfer() {

}

void profortosi_new_1::requestCustomers() {
	QString like;
	like = ui.lineEdit_3->text();
	like = like.toUpper();
	if (lang == "EL") {
		like.replace(QString("C"), trUtf8("Ψ"));
		like.replace(QString("D"), trUtf8("Δ"));
		like.replace(QString("F"), trUtf8("Φ"));
		like.replace(QString("G"), trUtf8("Γ"));
		like.replace(QString("J"), trUtf8("Ξ"));
		like.replace(QString("L"), trUtf8("Λ"));
		like.replace(QString("P"), trUtf8("Π"));
		like.replace(QString("R"), trUtf8("Ρ"));
		like.replace(QString("S"), trUtf8("Σ"));
		like.replace(QString("U"), trUtf8("Θ"));
		like.replace(QString("V"), trUtf8("Ω"));
	}

	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "RC";
	out << quint16(0) << req_type << like;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
}

void profortosi_new_1::startread() {
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
		QString cname, ccode;
		in >> ccode >> cname;

		QTableWidgetItem *a = new QTableWidgetItem;
		QTableWidgetItem *b = new QTableWidgetItem;
		a->setText(ccode);
		b->setText(cname);
		a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		ui.tableWidget->setRowCount(r + 1);
		ui.tableWidget->setItem(r, 0, a);
		ui.tableWidget->setItem(r, 1, b);

		++r;

		//qDebug() << req_type;
		nextblocksize = 0;
	}
	nextblocksize = 0;
}

void profortosi_new_1::next() {
	QString customer = ui.tableWidget->item(rowsel, 1)->text();
	QString ccode = ui.tableWidget->item(rowsel, 0)->text();
	QString car1 = ui.lineEdit->text();
	QString car2 = ui.lineEdit_2->text();
	profortosi_new_1_b *w = new profortosi_new_1_b(this, client, ccode,
			customer, car1, car2);
	w->move(0, 0);
	w->show();
	delete(this);

}

void profortosi_new_1::back() {
	delete (this);
}

void profortosi_new_1::tableclicked(int row, int col) {

	this->rowsel = row;
}

void profortosi_new_1::onTypeChar() {

	if (ui.lineEdit_3->text() != "")
		ui.searchButton->setEnabled(TRUE);
	else
		ui.searchButton->setEnabled(FALSE);

	QString like = ui.lineEdit_3->text();
	like = like.toUpper();
		if (lang == "EL") {
			like.replace(QString("C"), trUtf8("Ψ"));
			like.replace(QString("D"), trUtf8("Δ"));
			like.replace(QString("F"), trUtf8("Φ"));
			like.replace(QString("G"), trUtf8("Γ"));
			like.replace(QString("J"), trUtf8("Ξ"));
			like.replace(QString("L"), trUtf8("Λ"));
			like.replace(QString("P"), trUtf8("Π"));
			like.replace(QString("R"), trUtf8("Ρ"));
			like.replace(QString("S"), trUtf8("Σ"));
			like.replace(QString("U"), trUtf8("Θ"));
			like.replace(QString("V"), trUtf8("Ω"));
		}
		ui.lineEdit_3->setText(like);
}

void profortosi_new_1::change_language(int state) {

	if (state == 2)
		lang = "EL";
	else
		lang = "EN";
	ui.lineEdit_3->setFocus();
}
