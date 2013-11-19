#ifndef FORTOSI_PROGRESS_1_H
#define FORTOSI_PROGRESS_1_H

#include <QtGui/QDialog>
#include "ui_fortosi_progress_1.h"
#include <QtNetwork>
#include <QString>
#include <QTcpSocket>
#include "constants.h"
#include "fortosi_progress_1_1.h"
#include "fortosi_progress_1_2.h"

class fortosi_progress_1 : public QDialog
{
    Q_OBJECT

public:
    fortosi_progress_1(QWidget *parent = 0);
    ~fortosi_progress_1();

private:
    Ui::fortosi_progress_1Class ui;
    QTcpSocket *client;
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

#endif // FORTOSI_PROGRESS_1_H
