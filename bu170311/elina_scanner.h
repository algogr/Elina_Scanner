#ifndef ELINA_SCANNER_H
#define ELINA_SCANNER_H

#include <QtGui/QDialog>
#include "ui_elina_scanner.h"
#include "fortosi_sel.h"

class Elina_Scanner : public QDialog
{
    Q_OBJECT

public:
    Elina_Scanner(QWidget *parent = 0);
    ~Elina_Scanner();

private:
    Ui::Elina_ScannerClass ui;

private slots:
	void fortosi();
};

#endif // ELINA_SCANNER_H
