#ifndef RETURN_ROLL_H
#define RETURN_ROLL_H

#include <QDialog>
#include <QtGui/QWidget>
#include <QtGui/QMessageBox>
#include <QtNetwork>
#include "constants.h"

namespace Ui {
class return_roll;
}

class return_roll : public QDialog
{
    Q_OBJECT
    
public:
    //mode 0=return,1=katastrofi
    explicit return_roll(QWidget *parent = 0,int mode=0);
    ~return_roll();
    
private:
    Ui::return_roll *ui;
    int r,mode;

    QTcpSocket *client;

    QString lastscanned;

    void create_row(const QString &code_t,const QString &code_a,int islast);
    bool eventFilter(QObject *object, QEvent *event);
    QString ver_code;
    QStringList confirmed;
    quint16 nextblocksize;




private slots:
    void scan();
    void insert_db();
    void lock();
    void close_now();
    void startread();
};

#endif // RETURN_ROLL_H
