#ifndef PROFORTOSI_PROGRESS_1_2_H
#define PROFORTOSI_PROGRESS_1_2_H

#include <QtGui/QDialog>
#include "ui_profortosi_progress_1_2.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "constants.h"

class profortosi_progress_1_2 : public QDialog
{
    Q_OBJECT

public:
    profortosi_progress_1_2(QWidget *parent = 0,QTcpSocket *client=0,QString fid=0);
    ~profortosi_progress_1_2();

private:
    Ui::profortosi_progress_1_2Class ui;
    QString profortosi_id;
	quint16 nextblocksize;
	QString customer;
	int weight;
	int r;
	void requestproFortosi();
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

#endif // PROFORTOSI_PROGRESS_1_2_H
