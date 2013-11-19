#ifndef PROFORTOSI_NEW_1_B_H
#define PROFORTOSI_NEW_1_B_H

#include <QtGui/QDialog>
#include "ui_profortosi_new_1_b.h"
#include "profortosi_new_1_1.h"
#include "profortosi_new_1_2.h"
#include <QtNetwork>
#include <QTcpSocket>


class profortosi_new_1_b : public QDialog
{
    Q_OBJECT

public:
    profortosi_new_1_b(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="", QString car1="",QString car2="");
    ~profortosi_new_1_b();
    QString ccode;
    QString customer;
	QString car1;
	QString car2;
	QTcpSocket *client;

private:
    Ui::profortosi_new_1_bClass ui;

private slots:
	void back();
	void loop();
	void code();
};

#endif // PROFORTOSI_NEW_1_B_H
