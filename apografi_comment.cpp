#include "apografi_comment.h"
#include "ui_apografi_comment.h"

apografi_comment::apografi_comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apografi_comment)
{
    ui->setupUi(this);
}

apografi_comment::~apografi_comment()
{
    delete ui;
}
