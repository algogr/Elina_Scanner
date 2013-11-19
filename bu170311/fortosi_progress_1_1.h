#ifndef FORTOSI_PROGRESS_1_1_H
#define FORTOSI_PROGRESS_1_1_H

#include <QtGui/QDialog>
#include "ui_fortosi_progress_1_1.h"
#include "constants.h"
#include <QtNetwork>
#include <QTcpSocket>

class fortosi_progress_1_1 : public QDialog
{
    Q_OBJECT

public:
    fortosi_progress_1_1(QWidget *parent = 0,QString fid="");
    ~fortosi_progress_1_1();

private:
    Ui::fortosi_progress_1_1Class ui;
    QString fortosi_id;
    QTcpSocket *client;
    quint16 nextblocksize;
    void requestFortosi();

private slots:
	void startread();
	void back();

};

#endif // FORTOSI_PROGRESS_1_1_H
