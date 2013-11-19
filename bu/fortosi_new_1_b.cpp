#include "fortosi_new_1_b.h"

fortosi_new_1_b::fortosi_new_1_b(QWidget *parent,QString customer, QString car1,QString car2)
    : QDialog(parent)
{
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

fortosi_new_1_b::~fortosi_new_1_b()
{

}

void fortosi_new_1_b::back()
{
	delete(this);
}


void fortosi_new_1_b::code()
{

}

void fortosi_new_1_b::loop()
{
	fortosi_new_1_1 *w = new fortosi_new_1_1(0,customer,car1,car2);
	w->move(0,0);
	w->show();

}

