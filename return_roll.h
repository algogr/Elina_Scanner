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
    explicit return_roll(QWidget *parent = 0);
    ~return_roll();
    
private:
    Ui::return_roll *ui;
    int r;

    QTcpSocket *client;

    QString lastscanned;

    void create_row(QString code_t,QString code_a);
    virtual bool eventFilter(QObject *object, QEvent *event);
    QString ver_code;
    QStringList confirmed;



private slots:
    void scan();
    void insert_db();
    void lock();
    void close_now();
};

#endif // RETURN_ROLL_H
