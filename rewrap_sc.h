#ifndef REWRAP_SC_H
#define REWRAP_SC_H

#include <QDialog>
#include "constants.h"
#include <QtNetwork>
#include <QMessageBox>

namespace Ui {
class rewrap_sc;
}

class rewrap_sc : public QDialog
{
    Q_OBJECT
    
public:
    explicit rewrap_sc(QWidget *parent = 0);
    ~rewrap_sc();
    
private:
    Ui::rewrap_sc *ui;
    QTcpSocket *client,*client1;
    quint16 nextblocksize;
    void insert_production(QStringList old_codes, QStringList new_codes);

private slots:
    void scanned_oldA();
    void scanned_new1A();
    void scanned_new2A();
    void scanned_new3A();
    void scanned_new4A();
    void scanned_new5A();
    void scanned_old();
    void scanned_new1();
    void scanned_new2();
    void scanned_new3();
    void scanned_new4();
    void scanned_new5();
    void insertClicked();
    void cancelClicked();
    void startread();
};

#endif // REWRAP_SC_H
