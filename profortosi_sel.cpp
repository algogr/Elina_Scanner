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
#include "profortosi_sel.h"

profortosi_sel::profortosi_sel(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QString ipath=(QString)APATH+"/img/app.png";
	QIcon *icon=new QIcon(ipath);
	this->setWindowIcon(*icon);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(new_profortosi()));
	connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(progress_profortosi()));

}

profortosi_sel::~profortosi_sel()
{

}

void profortosi_sel::new_profortosi(){
	profortosi_new_1 *w=new profortosi_new_1(this);
	w->show();
	w->move(0,0);
}

void profortosi_sel::progress_profortosi(){
	profortosi_progress_1 *w=new profortosi_progress_1(this);
	w->show();
	w->move(0,0);
}
