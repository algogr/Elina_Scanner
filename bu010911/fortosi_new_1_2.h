#ifndef FORTOSI_NEW_1_2_H
#define FORTOSI_NEW_1_2_H

#include <QtGui/QDialog>
#include "ui_fortosi_new_1_2.h"
#include <QtNetwork>
#include <QTcpSocket>

class fortosi_new_1_2 : public QDialog
{
    Q_OBJECT

public:
    fortosi_new_1_2(QWidget *parent = 0,QTcpSocket *pclient=0,QString ccode="",QString customer="",QString car1="",QString car2="",QString fid="0");
    ~fortosi_new_1_2();
    QString ccode;
    QString customer;
	QString car1;
	QString car2;
	QString fid;
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
	void cellclicked(const QModelIndex &);
	void tableclicked(int row,int column);
	void requestItems();

private:
    Ui::fortosi_new_1_2Class ui;
    int r;
    int weight;
    void requestDetails();
    int rowsel;




};

#endif // FORTOSI_NEW_1_2_H
