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
#include "fortosi_new_1_b.h"

fortosi_new_1_b::fortosi_new_1_b(QWidget *parent,QString ccode,QString customer, QString car1,QString car2,QString prfid)
    : QDialog(parent)
{
	qDebug()<<"ccode:"<<ccode<<"customer:"<<customer<<"car1:"<<car1<<"car2:"<<car2<<"prfid:"<<prfid;
	this->parent=parent;

	this->ccode=ccode;
	this->customer=customer;
	this->car1=car1;
	this->car2=car2;
	this->prfid=prfid;
	qDebug()<< this->prfid;
	ui.setupUi(this);
	QString ipath=(QString)APATH+"/img/app.png";
	QIcon *icon=new QIcon(ipath);

	this->setWindowIcon(*icon);
	ui.labelCustomer->setText(customer);
	ui.labelCar1->setText(car1);
	ui.labelCar2->setText(car2);
	ui.pushCode->setEnabled(FALSE);
	connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.pushCode, SIGNAL(clicked()), this, SLOT(code()));
	connect(ui.pushLoop, SIGNAL(clicked()), this, SLOT(loop()));

    delete icon;

}

fortosi_new_1_b::~fortosi_new_1_b()
{

}

void fortosi_new_1_b::back()
{
	delete(this);
}


void fortosi_new_1_b::code()
{

	fortosi_new_1_2 *w = new fortosi_new_1_2(this->parent,ccode,customer,car1,car2,prfid);
	//qDebug() << customer << car1 << car2;
	w->move(0,0);
	w->show();
	delete(this);

}

void fortosi_new_1_b::loop()
{

	fortosi_new_1_1 *w = new fortosi_new_1_1(this->parent,ccode,customer,car1,car2,prfid);
	//qDebug() << customer << car1 << car2;
	w->move(0,0);
	w->show();
	delete(this);

}

