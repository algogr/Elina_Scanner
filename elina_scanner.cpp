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
#include "elina_scanner.h"
#include <QProgressDialog>
#include "QGridLayout"

//#include "networkcontrol.h"

Elina_Scanner::Elina_Scanner(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    networkstatus=FALSE;
    ifino=0;

    foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
        {
            // Return only the first non-loopback MAC Address
            if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
                macaddress=netInterface.hardwareAddress();
        }
   QString logline="";
   QFile log("log.txt");
   log.open(QIODevice::ReadWrite | QIODevice::Text);
   QTextStream logoutput(&log);
   logline="MAC:"+macaddress;
   logoutput<<logline<<endl;


   ui.bReadLabel->setHidden(true);


	read_ap=FALSE;
	write_ap=FALSE;


    this->client1 = new QTcpSocket(this);
    ui.statusLabel->setText("OFFLINE");
    logline="STATUS:"+ui.statusLabel->text();

    logoutput<<logline<<endl;

    ui.statusLabel->setStyleSheet("QLabel { color : red; }");

    ui.statusLabel_2->setText("DISCONNECTED");
    ui.statusLabel_2->setStyleSheet("QLabel { color : red; }");





    mgr=new QNetworkConfigurationManager();
    QVariant t=mgr->allConfigurations().count();
    logline="ACTIVE INTERFACES:"+t.toString();
    logoutput<<logline<<endl;


    ui.statusLabel->setText(t.toString());
    if (mgr->allConfigurations(QNetworkConfiguration::Active).count()>0)
    {
        logline="ACTIVENETWORK";
        logoutput<<logline<<endl;

        ui.statusLabel->setText("ONLINE");
        ui.statusLabel->setStyleSheet("QLabel { color : green; }");
        QHostAddress addr((QString)SVR_HOST);

        client1->connectToHost(addr, 8889);
        connect(this->client1,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(check_state(QAbstractSocket::SocketState)));

    }

    log.close();


    connect(mgr,SIGNAL(onlineStateChanged(bool)),this,SLOT(check_online()));

    connect(ui.bFortosi, SIGNAL(released()), this, SLOT(fortosi()));
    connect(ui.bApografi, SIGNAL(released()), this, SLOT(apografi_s()));
    connect(ui.bAnalyser, SIGNAL(released()), this, SLOT(katastrofi_s()));
    connect(ui.bChangeLabel, SIGNAL(released()), this, SLOT(change_label_s()));
    connect(ui.bRewrap, SIGNAL(released()),this,SLOT(rewrap_label()));
    connect(ui.bReturn, SIGNAL(released()),this,SLOT(returnroll()));
    connect(ui.bTransmitApografi,SIGNAL(released()),this,SLOT(send()));





}

Elina_Scanner::~Elina_Scanner()
{
	client1->disconnectFromHost();
    delete client1;
    delete mgr;



}

void Elina_Scanner::fortosi()
{
    fortosi_sel *w=new fortosi_sel(this);
	w->show();
	w->move(0,0);
}


void Elina_Scanner::apografi_s()
{
	apografi *w=new apografi(this,0);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::katastrofi_s()
{
    //katastrofi *w= new katastrofi(this);
    return_roll *w= new return_roll(this,1);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::change_label_s()
{
	change_label *w= new change_label(this);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::read_label_s()
{
	read_label *w= new read_label(this);
	w->show();
	w->move(0,0);
}


void Elina_Scanner::rewrap_label()
{
    rewrap_sc *w= new rewrap_sc(this);
    w->show();
    w->move(0,0);
}


void Elina_Scanner::returnroll()
{
    return_roll *w= new return_roll(this,0);
    w->show();
    w->move(0,0);
}


void Elina_Scanner::transmit_apografi()
{
    QFile old_copy("apografi_1.txt");

    ifino=0;
    QFile file("apografi.txt");
    if (!file.exists())
    {
        QMessageBox m;
        m.setText(trUtf8("Δεν βρέθηκε το αρχείο απογραφής!(apografi.txt)"));
        QSound::play("bell.wav");
        m.setStandardButtons(QMessageBox::Ok);
        m.setInformativeText(trUtf8("Η αποστολή δεν έγινε!"));
        m.move(20,120);
        m.exec();

        return;
    }

    ui.bTransmitApografi->setEnabled(FALSE);
    old_copy.remove();
    file.copy("apografi_1.txt");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    foreach(QNetworkInterface interface, QNetworkInterface::allInterfaces())
        {
            // Return only the first non-loopback MAC Address
            if (!(interface.flags() & QNetworkInterface::IsLoopBack))

            {
            QString text = interface.hardwareAddress();
            qDebug() << text;
            }
        }



    QNetworkRequest request(QUrl("http://"+(QString)SVR_HOST+"/upload/"));

    QString bound="margin"; //name of the boundary
    //according to rfc 1867 we need to put this string here:
    QByteArray data(QString("--" + bound + "\r\n").toLocal8Bit());
    data.append("Content-Disposition: form-data; name=\"action\"\r\n\r\n");
    data.append("--" + bound + "\r\n");   //according to rfc 1867


        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"NO FILE";
            return;
        }
    QString filename=file.fileName();
    //QString filename="algo.db";
    data.append("Content-Disposition: form-data; name=\"upload\"; filename=\""+filename+"\"\r\n");  //name of the input is "uploaded" in my form, next one is a file name.
    ///data.append("Content-Type: image/jpeg\r\n\r\n"); //data type
    //data.append("Content-Type: application/binary\r\n\r\n"); //data type
    data.append("Content-Type: text/plain\r\n\r\n"); //data type
    data.append(file.readAll());   //let's read the file
    data.append("\r\n");
    data.append("--" + bound + "--\r\n");  //closing boundary according to rfc 1867
    request.setRawHeader(QString("Content-Type").toLocal8Bit(),QString("multipart/form-data; boundary=" + bound).toLocal8Bit());
    request.setRawHeader(QString("Content-Length").toLocal8Bit(), QString::number(data.length()).toLocal8Bit());
    reply = manager->post(request,data);

}





void Elina_Scanner::check_online()
{

    QList<QNetworkConfiguration> activeConfigs = mgr->allConfigurations(QNetworkConfiguration::Active);
    QHostAddress addr((QString)SVR_HOST);
    if (activeConfigs.count() > 0)
    {

        client1->connectToHost(addr, 8889);
        qDebug()<<"ONLINE";


        ui.statusLabel->setText("ONLINE");
        ui.statusLabel->setStyleSheet("QLabel { color : green; }");
        connect(this->client1,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(check_state(QAbstractSocket::SocketState)));

    }
    else
        {
            client1->abort();
            client1->close();
            qDebug()<<"OFFLINE";
            ui.statusLabel->setText("OFFLINE");
            ui.statusLabel->setStyleSheet("QLabel { color : red; }");
            networkstatus=FALSE;
        }
        //Q_ASSERT(!mgr.isOnline())

}

void Elina_Scanner::check_state(QAbstractSocket::SocketState state)
{

    if (state==QAbstractSocket::ConnectedState)
    {
        networkstatus=TRUE;

        ui.statusLabel_2->setText("CONNECTED");
        ui.statusLabel_2->setStyleSheet("QLabel { color : green; }");


    }
    else if(state==QAbstractSocket::UnconnectedState)
    {
        networkstatus=FALSE;

        ui.statusLabel_2->setText("DISCONNECTED");
        ui.statusLabel_2->setStyleSheet("QLabel { color : red; }");
        client1->abort();
        client1->reset();
        if (mgr->allConfigurations(QNetworkConfiguration::Active).count()>0)
        {
            QHostAddress addr((QString)SVR_HOST);
            client1->connectToHost(addr, 8889);
        }

    }
}


void Elina_Scanner::send()
{
    if((mgr->allConfigurations(QNetworkConfiguration::Active).count()>0) && (networkstatus==TRUE))

        transmit_apografi();
    else
    {
        QMessageBox m;
        m.setText(trUtf8("Πρόβλημα επικοινωνίας με τον server!"));
        QSound::play("bell.wav");
        m.setStandardButtons(QMessageBox::Ok);
        m.setInformativeText(trUtf8("Η αποστολή δεν έγινε! Ελέγξτε τον http server"));
        m.move(30,120);
        m.exec();
    }
}



void Elina_Scanner::replyFinished(QNetworkReply *reply)
{
    qDebug()<<"FINISHED";
    reply->deleteLater();
    QMessageBox m;
    if (reply->error() == QNetworkReply::NoError)
    {
        QFile file("apografi.txt");
        file.remove();
        QByteArray block;
        QDataStream out(&block,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_1);
        QString req_type="APIN_NEW";
        out << quint16(0)<<req_type;


        out.device()->seek(0);
        out<<quint16(block.size()-sizeof(quint16));
        client1->write(block);
        send_final_packet();
        m.setText(trUtf8("Aποστολή απογραφής"));
        m.setStandardButtons(QMessageBox::Ok);
        m.setInformativeText(trUtf8("Η αποστολή ολοκληρώθηκε επιτυχώς!"));
        m.move(30,120);

        ui.bTransmitApografi->setEnabled(TRUE);
        m.exec();
    }
    else
    {
        m.setText(trUtf8("Πρόβλημα αποστολής"));
        QSound::play("bell.wav");
        m.setStandardButtons(QMessageBox::Ok);
        m.setInformativeText(trUtf8("Η αποστολή AΠΕΤΥΧΕ!!!Ελέγξτε τον http server"));
        m.move(30,120);

        ui.bTransmitApografi->setEnabled(TRUE);
        m.exec();

    }

    return;
}

void Elina_Scanner::send_final_packet()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);
    out << quint16(0xFFFF);
    client1->write(block);



    return;


}
