#ifndef PROFORTOSI_PROGRESS_1_H
#define PROFORTOSI_PROGRESS_1_H

#include <QtGui/QDialog>
#include "ui_profortosi_progress_1.h"
#include <QtNetwork>
#include <QString>
#include <QTcpSocket>
#include "constants.h"
#include "profortosi_progress_1_1.h"
#include "profortosi_progress_1_2.h"


class profortosi_progress_1 : public QDialog
{
    Q_OBJECT

public:
    profortosi_progress_1(QWidget *parent = 0,QTcpSocket *pclient=0);
    ~profortosi_progress_1();
    QTcpSocket *client;

private:
    Ui::profortosi_progress_1Class ui;
    quint16 nextblocksize;
	int rowsel;
	void requestFortoseis();


private slots:
	void continious();
	void review();
	void back();
	void startread();
	void tableclicked(int row,int col);

};

#endif // PROFORTOSI_PROGRESS_1_H
