#ifndef FORTOSI_NEW_1_H
#define FORTOSI_NEW_1_H

#include <QtGui/QDialog>
//#include <QtSql>
#include "ui_fortosi_new_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include "fortosi_new_1_b.h"
#include "network_test.h"





class fortosi_new_1 : public QDialog
{
    Q_OBJECT

public:
    //QSqlDatabase db;
    //QSqlDatabase db1;
    fortosi_new_1(QWidget *parent = 0,QTcpSocket *pclient=0);
    ~fortosi_new_1();



private:
    Ui::fortosi_new_1Class ui;
    void start(QString address, quint16 port);

    void readCustomers();
    void startTransfer();
    QWidget *parent;
    //QTcpSocket *client;
    QString customers;
    QTcpSocket *client;
    quint16 blockSize;
    quint16 nextblocksize;
    int rowsel;
    network_test *nt;

private slots:
	void startread();
	void requestCustomers();
	void next();
	void back();
	void tableclicked(int row,int col);

};

#endif // FORTOSI_NEW_1_H
