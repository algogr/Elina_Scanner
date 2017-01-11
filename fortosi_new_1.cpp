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
#include "fortosi_new_1.h"
#include <QHostAddress>
#include "elina_scanner.h"


fortosi_new_1::fortosi_new_1(QWidget *parent) :
    QDialog(parent) {
	this->parent = parent;
    this->setWindowFlags( ( (this->windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowCloseButtonHint) );
	ui.setupUi(this);


	QString ipath1 = (QString) APATH + "/img/truck1.png";
	QIcon *icon1 = new QIcon(ipath1);
	this->setWindowIcon(*icon1);
    delete icon1;

	QString ipath = (QString) APATH + "/img/search.png";
	QIcon *icon = new QIcon(ipath);
	ui.searchButton->setIcon(*icon);
    delete icon;

	ui.searchButton->setEnabled(FALSE);
	ui.label_ccode->setVisible(FALSE);

	QHostAddress addr((QString) SVR_HOST);
	nextblocksize = 0;
	lang = "EL";
	r=0;

	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8(
			"Κωδ.Πελάτη") << trUtf8("Πελάτης"));

	ui.tableWidget->setColumnWidth(0, 0);
	ui.tableWidget->setColumnWidth(1, 280);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
	connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
	connect(ui.pushFront, SIGNAL(clicked()), this, SLOT(next()));
	connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.lineEdit_3, SIGNAL(textChanged(const QString &)), this,
			SLOT(onTypeChar()));
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(requestCustomers()));
	connect(ui.tableWidget, SIGNAL(cellClicked(int ,int )), this,
			SLOT(tableclicked(int,int)));

	connect(ui.checkGreek, SIGNAL(stateChanged(int)), this,
			SLOT(change_language(int)));

	ui.lineEdit_3->setFocus();



}

fortosi_new_1::~fortosi_new_1() {

    client->disconnectFromHost();

    delete client;
}

void fortosi_new_1::startTransfer() {

}

void fortosi_new_1::requestCustomers() {
	QString like;
	like = ui.lineEdit_3->text();
	like = like.toUpper();
	if (lang == "EL") {
        like.replace(QString("A"), trUtf8("Α"));
        like.replace(QString("B"), trUtf8("Β"));
        like.replace(QString("E"), trUtf8("Ε"));
        like.replace(QString("Z"), trUtf8("Ζ"));
        like.replace(QString("H"), trUtf8("Η"));
        like.replace(QString("I"), trUtf8("Ι"));
        like.replace(QString("K"), trUtf8("Κ"));
        like.replace(QString("M"), trUtf8("Μ"));
        like.replace(QString("N"), trUtf8("Ν"));
        like.replace(QString("O"), trUtf8("Ο"));
        like.replace(QString("T"), trUtf8("Τ"));
        like.replace(QString("Y"), trUtf8("Υ"));
        like.replace(QString("X"), trUtf8("Χ"));
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
	out << quint16(0) << req_type << like << lang;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block1, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
}

void fortosi_new_1::startread() {

    QDataStream in(client);


    in.setVersion(QDataStream::Qt_4_1);

    ui.tableWidget->setRowCount(r);
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
        QString type, cname, ccode;

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


        nextblocksize = 0;

    }
    nextblocksize = 0;

}

void fortosi_new_1::next() {
	if (ui.lineEdit->text() == "") {
		QMessageBox m;
        QSound::play("bell.wav");
		m.setText(trUtf8("Δεν δόθηκε φορτηγό"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		return;
	}

	if (ui.label_Customer->text() == "") {
		QMessageBox m;
		QSound::play("bell.wav");
		m.setText(trUtf8("Δεν δόθηκε πελάτης"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		return;

	}

	customer = ui.label_Customer->text();
	ccode = ui.label_ccode->text();
	car1 = ui.lineEdit->text();
	car2 = ui.lineEdit_2->text();

	fortosi_new_1_b *w = new fortosi_new_1_b(this->parent, ccode, customer,
            car1, car2);
	w->move(0, 0);
	w->show();
	delete (this);

}

void fortosi_new_1::back()

{
	delete (this);
}

void fortosi_new_1::tableclicked(int row, int col) {

	this->rowsel = row;
	ui.label_Customer->setText(ui.tableWidget->item(rowsel, 1)->text());
	ui.label_ccode->setText(ui.tableWidget->item(rowsel, 0)->text());

}


void fortosi_new_1::onTypeChar() {

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

void fortosi_new_1::change_language(int state) {

	if (state == 2)
		lang = "EL";
	else
		lang = "EN";
	ui.lineEdit_3->setFocus();
}

