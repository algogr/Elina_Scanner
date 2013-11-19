#include "profortosi_sel.h"

profortosi_sel::profortosi_sel(QWidget *parent,QTcpSocket *pclient)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(new_profortosi()));
	connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(progress_profortosi()));
	client=pclient;
}

profortosi_sel::~profortosi_sel()
{

}

void profortosi_sel::new_profortosi(){
	profortosi_new_1 *w=new profortosi_new_1(this,client);
	w->show();
	w->move(0,0);
}

void profortosi_sel::progress_profortosi(){
	profortosi_progress_1 *w=new profortosi_progress_1(this,client);
	w->show();
	w->move(0,0);
}
