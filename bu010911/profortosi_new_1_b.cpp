#include "profortosi_new_1_b.h"

profortosi_new_1_b::profortosi_new_1_b(QWidget *parent,QTcpSocket *pclient,QString ccode,QString customer, QString car1,QString)
    : QDialog(parent)
{
	client=pclient;
	this->ccode=ccode;
	this->customer=customer;
	this->car1=car1;
	this->car2=car2;
	ui.setupUi(this);
	ui.labelCustomer->setText(customer);
	ui.labelCar1->setText(car1);
	ui.labelCar2->setText(car2);
	connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.pushCode, SIGNAL(clicked()), this, SLOT(code()));
	connect(ui.pushLoop, SIGNAL(clicked()), this, SLOT(loop()));

}

profortosi_new_1_b::~profortosi_new_1_b()
{

}

void profortosi_new_1_b::back()
{
	delete(this);
}


void profortosi_new_1_b::code()
{
	profortosi_new_1_2 *w = new profortosi_new_1_2(this,client,ccode,customer,car1,car2);
	//qDebug() << customer << car1 << car2;
	w->move(0,0);
	w->show();


}

void profortosi_new_1_b::loop()
{
	profortosi_new_1_1 *w = new profortosi_new_1_1(this,client,ccode,customer,car1,car2);
	//qDebug() << customer << car1 << car2;
	w->move(0,0);
	w->show();

}




