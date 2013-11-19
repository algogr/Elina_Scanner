#ifndef FORTOSI_NEW_1_B_H
#define FORTOSI_NEW_1_B_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_b.h"
#include "fortosi_new_1_1.h"

class fortosi_new_1_b : public QDialog
{
    Q_OBJECT

public:
    fortosi_new_1_b(QWidget *parent = 0,QString customer="", QString car1="",QString car2="");
    ~fortosi_new_1_b();
    QString customer;
    QString car1;
    QString car2;

private:
    Ui::fortosi_new_1_bClass ui;

private slots:
	void back();
	void loop();
	void code();

};

#endif // FORTOSI_NEW_1_B_H
