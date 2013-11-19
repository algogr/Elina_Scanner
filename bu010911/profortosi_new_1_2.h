#ifndef PROFORTOSI_NEW_1_2_H
#define PROFORTOSI_NEW_1_2_H

#include <QtGui/QDialog>
#include "ui_profortosi_new_1_2.h"
#include <QtNetwork>
#include <QTcpSocket>


class profortosi_new_1_2 : public QDialog
{
    Q_OBJECT

public:
    profortosi_new_1_2(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="",QString car1="",QString car2="");
    ~profortosi_new_1_2();
    QWidget *parent;
    QString ccode;
    QString customer;
   	QString car1;
   	QString car2;
   	QTcpSocket *client;
   	quint16 blockSize;
   	quint16 nextblocksize;

private slots:
   	void startreadItems();
   	//void itemchanged();
   	void scan();
   	void finalize();
   	void temporary();
   	void back();
   	void delrow();
   	void requestItems();
   	void cellclicked(const QModelIndex &);
   	void tableclicked(int row,int column);


private:
    Ui::profortosi_new_1_2Class ui;
    int r;
	int weight;

	void requestDetails();
	int rowsel;
};

#endif // PROFORTOSI_NEW_1_2_H
