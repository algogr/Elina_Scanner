#ifndef FORTOSI_NEW_1A_H
#define FORTOSI_NEW_1A_H

#include <QtGui/QWidget>
#include "ui_fortosi_new_1a.h"
#include <QtNetwork>
#include <QCheckBox>
#include <QString>
#include <QTcpSocket>
#include "constants.h"
#include "fortosi_new_1_b.h"


class fortosi_new_1a : public QWidget
{
    Q_OBJECT

public:
    fortosi_new_1a(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="", QString car1="",QString car2="");
    ~fortosi_new_1a();

private:
    Ui::fortosi_new_1aClass ui;
    quint16 nextblocksize;
    int rowsel;
	void requestFortoseis(QString customer="",QString car1="",QString car2="");
	QWidget *parent;
	QString pccode;
	QString pcustomer;
	QString pcar1;
	QString pcar2;
	QTcpSocket *client;
	void requestproFortoseis(QString customer);

private slots:
	void next();
	void review();
	void back();
	void startread();
	void tableclicked(int row,int col);

};

#endif // FORTOSI_NEW_1A_H
