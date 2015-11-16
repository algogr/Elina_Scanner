#ifndef FORTOSI_SEL_1_H
#define FORTOSI_SEL_1_H

#include <QDialog>
#include <QFile>
#include "constants.h"
#include "fortosi_sel.h"
class fortosi_sel;
namespace Ui {
class fortosi_sel_1;
}

class fortosi_sel_1 : public QDialog
{
    Q_OBJECT

public:
    explicit fortosi_sel_1(QWidget *parent = 0);
    ~fortosi_sel_1();
    fortosi_sel *p;

private:
    Ui::fortosi_sel_1 *ui;
    int selrow,r;
    void readfile(const QString filename);


private slots:
    void back();
    void send();
    void tableclicked(int row,int col);
};

#endif // FORTOSI_SEL_1_H
