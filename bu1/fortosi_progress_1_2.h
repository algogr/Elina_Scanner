#ifndef FORTOSI_PROGRESS_1_2_H
#define FORTOSI_PROGRESS_1_2_H

#include <QtGui/QDialog>
#include "ui_fortosi_progress_1_2.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "constants.h"


class fortosi_progress_1_2 : public QDialog
{
    Q_OBJECT

public:
    fortosi_progress_1_2(QWidget *parent = 0,QTcpSocket *client=0,QString fid=0);
    ~fortosi_progress_1_2();


private:
    Ui::fortosi_progress_1_2Class ui;
    QString fortosi_id;
    quint16 nextblocksize;
    QString customer;
    int weight;
    int r;
    void requestFortosi();
    QTcpSocket *client;

private slots:
	void startread();
	void scan();
	void finalize();
	void temporary();
	void back();
	void delrow();
	void cellclicked();

};

#endif // FORTOSI_PROGRESS_1_2_H
