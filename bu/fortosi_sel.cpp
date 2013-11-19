#include "fortosi_sel.h"

fortosi_sel::fortosi_sel(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(new_fortosi()));
}

fortosi_sel::~fortosi_sel()
{

}

void fortosi_sel::new_fortosi(){
	fortosi_new_1 *w=new fortosi_new_1();
	w->show();
	w->move(0,0);
}
