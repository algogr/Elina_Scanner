#ifndef KATASTROFI_H
#define KATASTROFI_H

#include <QtGui/QDialog>
#include "ui_katastrofi.h"

class katastrofi : public QDialog
{
    Q_OBJECT

public:
    katastrofi(QWidget *parent = 0);
    ~katastrofi();

private:
    Ui::katastrofiClass ui;
};

#endif // KATASTROFI_H
