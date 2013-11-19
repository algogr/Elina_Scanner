#include "fortosi_sel.h"

fortosi_sel::fortosi_sel(QWidget *parent,QTcpSocket *pclient)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(new_fortosi()));
	connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(progress_fortosi()));
	client=pclient;
}

fortosi_sel::~fortosi_sel()
{

}

void fortosi_sel::new_fortosi(){
	fortosi_new_1 *w=new fortosi_new_1(this,client);
	w->show();
	w->move(0,0);
}

void fortosi_sel::progress_fortosi(){
	fortosi_progress_1 *w=new fortosi_progress_1(this,client);
	w->show();
	w->move(0,0);
}
