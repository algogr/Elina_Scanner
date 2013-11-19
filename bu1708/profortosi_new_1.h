#ifndef PROFORTOSI_NEW_1_H
#define PROFORTOSI_NEW_1_H

#include <QtGui/QDialog>
#include "ui_profortosi_new_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include "profortosi_new_1_b.h"


class profortosi_new_1 : public QDialog
{
    Q_OBJECT

public:
    profortosi_new_1(QWidget *parent = 0,QTcpSocket *pclient=0);
    ~profortosi_new_1();
    QTcpSocket *client;

private:
    Ui::profortosi_new_1Class ui;
    void start(QString address, quint16 port);

	void readCustomers();
	void startTransfer();
	//QTcpSocket *client;
	QString customers;
	quint16 blockSize;
	quint16 nextblocksize;
	int rowsel;

    private slots:
    	void startread();
    	void requestCustomers();
    	void next();
    	void back();
    	void tableclicked(int row,int col);
};

#endif // PROFORTOSI_NEW_1_H
