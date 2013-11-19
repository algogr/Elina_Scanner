#ifndef FORTOSI_SEL_H
#define FORTOSI_SEL_H

#include <QtGui/QDialog>
#include "ui_fortosi_sel.h"
#include "fortosi_new_1.h"
#include "fortosi_progress_1.h"

class fortosi_sel : public QDialog
{
    Q_OBJECT

public:
    fortosi_sel(QWidget *parent = 0);
    ~fortosi_sel();

private:
    Ui::fortosi_selClass ui;

private slots:
	void new_fortosi();
	void progress_fortosi();
};

#endif // FORTOSI_SEL_H
