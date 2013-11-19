#ifndef FORTOSI_NEW_1_1_H
#define FORTOSI_NEW_1_1_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_1.h"
#include <QtNetwork>
#include <QTcpSocket>


class fortosi_new_1_1 : public QDialog
{

    Q_OBJECT

public:
    fortosi_new_1_1(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="",QString car1="",QString car2="",QString fid="0");
    ~fortosi_new_1_1();
    QString ccode;
    QString customer;
    QString car1;
    QString car2;
    QString fid;
    QTcpSocket *client;

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
