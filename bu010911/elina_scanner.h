#ifndef ELINA_SCANNER_H
#define ELINA_SCANNER_H

#include <QtGui/QDialog>
#include "ui_elina_scanner.h"
#include "fortosi_sel.h"
#include "profortosi_sel.h"
#include "apografi.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "constants.h"

class Elina_Scanner : public QDialog
{
    Q_OBJECT

public:
    Elina_Scanner(QWidget *parent = 0);
    ~Elina_Scanner();
    QTcpSocket *client,*client1;
    bool read_ap,write_ap;

private:
    Ui::Elina_ScannerClass ui;
    void create_row(QString code_t,QString code_a);
    void send_final_packet();
    QMap <QString,QString> records;
    QTimer *timer;




private slots:
	void fortosi();
	void profortosi();
	void apografi_s();
	void error();
	void transmit_data();
	void startread();

};

#endif // ELINA_SCANNER_H
