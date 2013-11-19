#ifndef PROFORTOSI_PROGRESS_1_1_H
#define PROFORTOSI_PROGRESS_1_1_H

#include <QtGui/QDialog>
#include "ui_profortosi_progress_1_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QTcpSocket>

class profortosi_progress_1_1 : public QDialog
{
    Q_OBJECT

public:
    profortosi_progress_1_1(QWidget *parent = 0,QTcpSocket *client=0,QString fid="");
    ~profortosi_progress_1_1();

private:
    Ui::profortosi_progress_1_1Class ui;
    QString profortosi_id;
	quint16 nextblocksize;
	void requestproFortosi();
	QTcpSocket *client;

private slots:
	void startread();
	void back();

};

#endif // PROFORTOSI_PROGRESS_1_1_H
