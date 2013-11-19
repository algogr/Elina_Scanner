#ifndef FORTOSI_NEW_1_B_H
#define FORTOSI_NEW_1_B_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_b.h"
#include "fortosi_new_1_1.h"
#include "fortosi_new_1_2.h"
#include <QtNetwork>
#include <QTcpSocket>

class fortosi_new_1_b : public QDialog
{
    Q_OBJECT

public:
    fortosi_new_1_b(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="", QString car1="",QString car2="",QString fid="0");
    ~fortosi_new_1_b();
    QWidget *parent;
    QString ccode;
    QString customer;
    QString car1;
    QString car2;
    QString fid;
    QTcpSocket *client;

private:
    Ui::fortosi_new_1_bClass ui;

private slots:
	void back();
	void loop();
	void code();

};

#endif // FORTOSI_NEW_1_B_H
