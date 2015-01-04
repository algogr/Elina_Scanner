#include "apografi_comment.h"
#include "ui_apografi_comment.h"

apografi_comment::apografi_comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apografi_comment)
{
    ui->setupUi(this);
    p=(apografi*)parent;
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(btpressed()));
}

apografi_comment::~apografi_comment()
{
    delete ui;
}

void apografi_comment::btpressed()
{
    p->comment=ui->lineEdit->text();
    p->insert_db();
    //p->show();
}
