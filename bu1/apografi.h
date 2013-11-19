#ifndef APOGRAFI_H
#define APOGRAFI_H

#include <QtGui/QWidget>
#include <QtGui/QMessageBox>
#include <QtNetwork>
#include <QTimer>
#include "ui_apografi.h"
#include "constants.h"

class apografi : public QDialog
{
    Q_OBJECT

public:
    apografi(QWidget *parent = 0,QTcpSocket *client=0,int mode=0);
    ~apografi();

private:
    Ui::apografiClass ui;
    int r;
    int mode;
    // 0 arxiki, 1 kanoniki
    QTcpSocket *client,*test;
    quint16 nextblocksize;
    QString lastscanned;
    void checkdb(QString code_t);
    void create_row(QString code_t,QString code_a);
    virtual bool eventFilter(QObject *object, QEvent *event);
    QTimer *timer;
    bool insert_verification;
    QString ver_code;
    int row_sent;

    int startread();

private slots:
	void scan();
	int startread_1();
	void insert_db();
	void lock();
	void check_conn();
	void error();

};

#endif // APOGRAFI_H