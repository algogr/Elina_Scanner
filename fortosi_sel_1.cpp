#include "fortosi_sel_1.h"
#include "ui_fortosi_sel_1.h"
#include <QTextStream>
#include <QDebug>



fortosi_sel_1::fortosi_sel_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fortosi_sel_1)
{
    p=static_cast<fortosi_sel*>(parent);
    ui->setupUi(this);
    connect(ui->pushBack,SIGNAL(released()),this,SLOT(back()));


    connect(ui->pushSend,SIGNAL(released()),this,SLOT(send()));
    connect(ui->tableWidget, SIGNAL(cellClicked(int ,int )), this,SLOT(tableclicked(int,int)));
    ui->tableWidget->setColumnCount(4);
    //ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("Πελάτης") << trUtf8("Πινακίδα 1") << trUtf8("Πινακίδα 2") << trUtf8("Κιλά"));


    ui->tableWidget->setColumnWidth(0, 280);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->setColumnWidth(2, 200);
    ui->tableWidget->setColumnWidth(3, 100);
    r=0;
    readfile("fortosi.txt");
    readfile("fortosi_2.txt");
    readfile("fortosi_3.txt");



}

fortosi_sel_1::~fortosi_sel_1()
{
    delete ui;
}

void fortosi_sel_1::back()
{
    delete this;
}

void fortosi_sel_1::tableclicked(int row, int col)
{
    selrow=row;
}

void fortosi_sel_1::send()
{
    p->send_fortosi(selrow);

}


void fortosi_sel_1::readfile(const QString filename)
{
    qDebug()<<"R:"<<r;
    r+=1;
    QFile file(filename);
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"DEN MPOTO";
        return;
    }
    QString line=in.readLine();
    QString req_type,ccode,customer,car1,car2,code_t,weight,prfid;

    if (line.trimmed()=="1")
    {
        line=in.readLine();

            req_type=line.trimmed();
            ccode=in.readLine().trimmed();
            customer=in.readLine().trimmed();
            car1=in.readLine().trimmed();
            car2=in.readLine().trimmed();
            code_t=in.readLine().trimmed();
            weight=in.readLine().trimmed();
            prfid=in.readLine().trimmed();
            qDebug()<<"PRFID:"<<prfid;
            line=in.readLine();
            line=in.readLine();
        QTableWidgetItem *a = new QTableWidgetItem;
        QTableWidgetItem *b = new QTableWidgetItem;
        QTableWidgetItem *c = new QTableWidgetItem;
        QTableWidgetItem *d = new QTableWidgetItem;
        a->setText(customer);
        b->setText(car1);
        c->setText(car2);
        d->setText(weight);
        a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        c->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        d->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

        ui->tableWidget->setRowCount(r);
        ui->tableWidget->setItem(r-1, 0, a);
        ui->tableWidget->setItem(r-1, 1, b);
        ui->tableWidget->setItem(r-1, 2, c);
        ui->tableWidget->setItem(r-1, 3, d);
        file.close();
    }
    else
    {
        line=in.readLine();

        //while(line.trimmed().left(3)!="EOF")
        //{
            req_type=line.trimmed();
            customer=in.readLine().trimmed();
            code_t=in.readLine().trimmed();
            weight=in.readLine().trimmed();
            prfid=in.readLine().trimmed();
            qDebug()<<"PRFID:"<<prfid;

        //}
        QTableWidgetItem *a = new QTableWidgetItem;
        QTableWidgetItem *b = new QTableWidgetItem;
        QTableWidgetItem *c = new QTableWidgetItem;
        QTableWidgetItem *d = new QTableWidgetItem;
        a->setText(customer);
        b->setText("");
        c->setText("");
        d->setText(weight);
        a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        c->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        d->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

        ui->tableWidget->setRowCount(r);
        ui->tableWidget->setItem(r-1, 0, a);
        ui->tableWidget->setItem(r-1, 1, b);
        ui->tableWidget->setItem(r-1, 2, c);
        ui->tableWidget->setItem(r-1, 3, d);

        file.close();
    }


}
