#ifndef FORTOSI_NEW_1_1_H
#define FORTOSI_NEW_1_1_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_1.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "constants.h"

class fortosi_new_1_1 : public QDialog
{
    Q_OBJECT

public:
    fortosi_new_1_1(QWidget *parent = 0,QString customer="",QString car1="",QString car2="");
    ~fortosi_new_1_1();
    QString customer;
    QString car1;
    QString car2;

private:
    Ui::fortosi_new_1_1Class ui;
    int r;
    int weight;

private slots:
	void scan();
	void finalize();
	void temporary();
	void back();
	void cellclicked(const QModelIndex &);
	void delrow();
};

#endif // FORTOSI_NEW_1_1_H
