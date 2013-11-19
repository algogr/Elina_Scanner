#ifndef PROFORTOSI_SEL_H
#define PROFORTOSI_SEL_H

#include <QtGui/QDialog>
#include "ui_profortosi_sel.h"
#include "profortosi_new_1.h"
#include "profortosi_progress_1.h"
#include <QtNetwork>
#include <QTcpSocket>


class profortosi_sel : public QDialog
{
    Q_OBJECT

public:
    profortosi_sel(QWidget *parent = 0,QTcpSocket *pclient=0);
    ~profortosi_sel();
    QTcpSocket *client;

private:
    Ui::profortosi_selClass ui;

private slots:
	void new_profortosi();
	void progress_profortosi();
};

#endif // PROFORTOSI_SEL_H
