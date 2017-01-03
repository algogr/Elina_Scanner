/*
    Elina Scanner Inventory Management
    Copyright (C) 2012 Dimitris Paraschou

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */
#include "fortosi_sel.h"
#include "fortosi_sel_1.h"


fortosi_sel::fortosi_sel(QWidget *parent)
    : QDialog(parent)
{

    ui.setupUi(this);
    p=static_cast<Elina_Scanner*>(parent);



    client = new QTcpSocket;

    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(new_fortosi()));
    connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(progress_fortosi()));
    connect(ui.pushButton_3,SIGNAL(released()),this,SLOT(retransmit_fortosi()));
    connect(client,SIGNAL(readyRead()),this,SLOT(ready_read()));

}

fortosi_sel::~fortosi_sel()
{
    delete client;

}

void fortosi_sel::new_fortosi(){
    fortosi_new_1 *w=new fortosi_new_1(this);
    w->show();
    w->move(0,0);
  }

void fortosi_sel::progress_fortosi(){
    fortosi_progress_1 *w=new fortosi_progress_1(this);
    w->show();
    w->move(0,0);
}

void fortosi_sel::retransmit_fortosi()
{
    fortosi_sel_1 *w=new fortosi_sel_1(this);
    w->show();
    w->move(0,0);
    return;


}

void fortosi_sel::ready_read()
{
    qDebug() << "PIRA IFI";
    QMessageBox m;
    m.setText(trUtf8("Η φόρτωση εστάλει επιτυχώς!"));
    QSound::play("bell.wav");


    m.setStandardButtons(QMessageBox::Ok);
    m.move(80,120);
    m.exec();
    delete (this);
    nextblocksize = 0;


}

void fortosi_sel::send_fortosi(int n)
{
    if (p->networkstatus==TRUE)
    {
    ui.pushButton->setEnabled(FALSE);
    ui.pushButton_2->setEnabled(FALSE);
    ui.pushButton_3->setEnabled(FALSE);
    QHostAddress addr((QString) SVR_HOST);
    client->connectToHost(addr, 8889);
    QString filename;
    switch (n) {
    case 0:
        filename="fortosi.txt";
        break;
    case 1:
        filename="fortosi_2.txt";
        break;
    case 2:
        filename="fortosi_3.txt";
        break;

    default:
        filename="fortosi.txt";
        break;
    }
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

        while(line.trimmed().left(3)!="EOF")
        {
            req_type=line.trimmed();
            ccode=in.readLine().trimmed();
            customer=in.readLine().trimmed();
            car1=in.readLine().trimmed();
            car2=in.readLine().trimmed();
            code_t=in.readLine().trimmed();
            weight=in.readLine().trimmed();
            prfid=in.readLine().trimmed();
            qDebug()<<"PRFID:"<<prfid;
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);

            out << quint16(0) << req_type << ccode << customer << car1 << car2
                << code_t<< weight<< prfid;

            out.device()->seek(0);
            out << quint16(block.size() - sizeof(quint16));
            qDebug()<<"BLOCKSIZE"<<block.size();
            client->write(block);
            line=in.readLine();
            line=in.readLine();
        }
        QByteArray block1;
        QDataStream out1(&block1, QIODevice::WriteOnly);
        out1.setVersion(QDataStream::Qt_4_1);
        out1 << quint16(0xFFFF);
        client->write(block1);
        file.close();
    }
    else
    {
        line=in.readLine();

        while(line.trimmed().left(3)!="EOF")
        {
            req_type=line.trimmed();
            customer=in.readLine().trimmed();
            code_t=in.readLine().trimmed();
            weight=in.readLine().trimmed();
            prfid=in.readLine().trimmed();
            qDebug()<<"PRFID:"<<prfid;
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);

            out << quint16(0) << req_type << customer <<  code_t<< weight<< prfid;

            out.device()->seek(0);
            out << quint16(block.size() - sizeof(quint16));
            qDebug()<<"BLOCKSIZE"<<block.size();
            client->write(block);
            line=in.readLine();
            line=in.readLine();
        }
        QByteArray block1;
        QDataStream out1(&block1, QIODevice::WriteOnly);
        out1.setVersion(QDataStream::Qt_4_1);
        out1 << quint16(0xFFFF);
        client->write(block1);
        file.close();
    }
    }
    else
    {
        qDebug()<<"MPIKA";
        QMessageBox m;
        m.setText(trUtf8("Πρόβλημα επικοινωνίας με τον server!"));
        QSound::play("bell.wav");
        m.setStandardButtons(QMessageBox::Ok);
        m.move(80,120);
        m.exec();

    }



}
