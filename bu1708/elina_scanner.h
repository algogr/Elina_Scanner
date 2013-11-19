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
    QTcpSocket *client;

private:
    Ui::Elina_ScannerClass ui;


private slots:
	void fortosi();
	void profortosi();
	void apografi_s();
	void error();
};

#endif // ELINA_SCANNER_H
