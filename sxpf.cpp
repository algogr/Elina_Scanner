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
#include "sxpf.h"

sxpf::sxpf(QWidget *parent,fortosi_new_1 *f) :
	QDialog(parent) {
	ui.setupUi(this);
	this->f=f;
	QHostAddress addr((QString)SVR_HOST);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
	nextblocksize = 0;
	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setColumnHidden(1,TRUE);
	ui.tableWidget->setColumnHidden(6,TRUE);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("Κωδ.Πελάτη")<<trUtf8("")<<trUtf8("Πελάτης")<<trUtf8("Πινακίδα 1")<<trUtf8("Πινακίδα 2")<<trUtf8("Κιλά"));

	request_pro();

	connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(close()));
	connect(ui.tableWidget,SIGNAL(cellClicked(int ,int )),this, SLOT(row_selected(int,int)));
}

sxpf::~sxpf() {

}

void sxpf::startread() {
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

		QString ftrdate, id, cname, car1, car2, weight,ccode;

		in >> ftrdate >> id >> cname >> car1 >> car2 >> weight >> ccode;

		qDebug()<<cname;

		QTableWidgetItem *a = new QTableWidgetItem;
		QTableWidgetItem *b = new QTableWidgetItem;
		QTableWidgetItem *c = new QTableWidgetItem;
		QTableWidgetItem *d = new QTableWidgetItem;
		QTableWidgetItem *e = new QTableWidgetItem;
		QTableWidgetItem *f = new QTableWidgetItem;
		QTableWidgetItem *g = new QTableWidgetItem;

		a->setText(ftrdate);
		b->setText(id);
		c->setText(cname);
		d->setText(car1);
		e->setText(car2);
		f->setText(weight);
		g->setText(ccode);

		a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		c->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		d->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		e->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		f->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		g->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);



		ui.tableWidget->setRowCount(r + 1);
		ui.tableWidget->setItem(r, 0, a);
		ui.tableWidget->setItem(r, 1, b);
		ui.tableWidget->setItem(r, 2, c);
		ui.tableWidget->setItem(r, 3, d);
		ui.tableWidget->setItem(r, 4, e);
		ui.tableWidget->setItem(r, 5, f);
		ui.tableWidget->setItem(r, 6, g);
		++r;

		//qDebug() << req_type;
		nextblocksize = 0;
	}

}

void sxpf::request_pro() {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "RPF";
	out << quint16(0) << req_type;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block1,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
}

void sxpf::close(){
	f->ccode=ui.tableWidget->item(selected_row,6)->text();
	f->customer=ui.tableWidget->item(selected_row,2)->text();
	f->car1=ui.tableWidget->item(selected_row,3)->text();
	f->car2=ui.tableWidget->item(selected_row,4)->text();
	f->prfid=ui.tableWidget->item(selected_row,1)->text();
	f->ui.label_Customer->setText(this->ui.tableWidget->item(selected_row,2)->text());
	f->ui.label_ccode->setText(this->ui.tableWidget->item(selected_row,6)->text());
	f->ui.lineEdit->setText(this->ui.tableWidget->item(selected_row,3)->text());
	f->ui.lineEdit_2->setText(this->ui.tableWidget->item(selected_row,4)->text());
	f->ui.lineEdit_3->setEnabled(FALSE);
	f->ui.searchButton->setEnabled(FALSE);
	f->ui.tableWidget->setEnabled(FALSE);
	client->disconnectFromHost();
	delete(client);
	delete(this);
}

void sxpf::row_selected(int x,int y){
	this->selected_row=x;
}

