#include "elina_scanner.h"

Elina_Scanner::Elina_Scanner(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(fortosi()));
}

Elina_Scanner::~Elina_Scanner()
{

}

void Elina_Scanner::fortosi()
{
	fortosi_sel *w=new fortosi_sel();
	w->show();
	w->move(0,0);
}
