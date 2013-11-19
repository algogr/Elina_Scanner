#ifndef PROFORTOSI_NEW_1_1_H
#define PROFORTOSI_NEW_1_1_H

#include <QtGui/QDialog>
#include "ui_profortosi_new_1_1.h"
#include <QtNetwork>
#include <QTcpSocket>


class profortosi_new_1_1 : public QDialog
{
    Q_OBJECT

public:
    profortosi_new_1_1(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="",QString car1="",QString car2="");
    ~profortosi_new_1_1();
    QString ccode;
    QString customer;
	QString car1;
	QString car2;
	QTcpSocket *client;

private:
    Ui::profortosi_new_1_1Class ui;
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

#endif // PROFORTOSI_NEW_1_1_H
