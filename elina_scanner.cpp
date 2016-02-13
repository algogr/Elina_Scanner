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
//#include "networkcontrol.h"

Elina_Scanner::Elina_Scanner(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	//this->showFullScreen();
	QRegExp jim("\\A\\d{3,3}[X-Z]\\d{1,1}");
    networkstatus=FALSE;
    ifino=0;
    connect(ui.pushButton, SIGNAL(released()), this, SLOT(fortosi()));
    connect(ui.pushButton_7, SIGNAL(released()), this, SLOT(profortosi()));
    connect(ui.pushButton_2, SIGNAL(released()), this, SLOT(apografi_s()));
    connect(ui.pushButton_6, SIGNAL(released()), this, SLOT(katastrofi_s()));
    connect(ui.pushButton_4, SIGNAL(released()), this, SLOT(change_label_s()));
    connect(ui.pushButton_5, SIGNAL(released()), this, SLOT(read_label_s()));
    connect(ui.pushButton_8, SIGNAL(released()),this,SLOT(rewrap_label()));
    connect(ui.pushButton_3, SIGNAL(released()),this,SLOT(returnroll()));
    connect(ui.pushButton_9,SIGNAL(released()),this,SLOT(send()));

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


	read_ap=FALSE;
	write_ap=FALSE;
    //QString ipath=(QString)APATH+"/img/app.png";
    //QIcon *icon=new QIcon(ipath);

    //this->setWindowIcon(*icon);
    //delete icon;
	QString ipath1=(QString)APATH+"/img/truck1.png";
    //QIcon *icon1=new QIcon(ipath1);
    //ui.pushButton->setIcon(*icon1);
    //delete icon1;

	QString ipath2=(QString)APATH+"/img/prof.jpeg";
    //QIcon *icon2=new QIcon(ipath2);
    //ui.pushButton_7->setIcon(*icon2);
    //delete icon2;

	QString ipath3=(QString)APATH+"/img/apo.jpeg";
    //QIcon *icon3=new QIcon(ipath3);
    //ui.pushButton_2->setIcon(*icon3);
    //delete icon3;

	QString ipath4=(QString)APATH+"/img/kat.jpeg";
    //QIcon *icon4=new QIcon(ipath4);
    //ui.pushButton_6->setIcon(*icon4);
    //delete icon4;

	QString ipath5=(QString)APATH+"/img/change.png";
    //QIcon *icon5=new QIcon(ipath5);
    //ui.pushButton_4->setIcon(*icon5);
    //delete icon5;

	QString ipath6=(QString)APATH+"/img/read.png";
    //QIcon *icon6=new QIcon(ipath6);
    //ui.pushButton_5->setIcon(*icon6);
    //delete icon6;

    QString ipath7=(QString)APATH+"/img/rewrap.png";
    //QIcon *icon7=new QIcon(ipath7);
    //ui.pushButton_8->setIcon(*icon7);
    //delete icon7;

    QString ipath8=(QString)APATH+"/img/return.png";
    //QIcon *icon8=new QIcon(ipath8);
    //ui.pushButton_3->setIcon(*icon8);
    //delete icon8;

    //QHostAddress addr((QString)SVR_HOST);
	this->client1 = new QTcpSocket;
	//client1 = new QTcpSocket;
    //QTimer *timer=new QTimer;
    ui.statusLabel->setText("OFFLINE");
    logline="STATUS:"+ui.statusLabel->text();
    logoutput<<logline<<endl;

    ui.statusLabel->setStyleSheet("QLabel { color : red; }");

    ui.statusLabel_2->setText("DISCONNECTED");
    ui.statusLabel_2->setStyleSheet("QLabel { color : red; }");

    ui.progressBar->setVisible(false);
    ui.progressBar->setMinimum(0);



    mgr=new QNetworkConfigurationManager();
    QVariant t=mgr->allConfigurations().count();
    logline="ACTIVE INTERFACES:"+t.toString();
    logoutput<<logline<<endl;

    qDebug()<<t;
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
        //client->waitForConnected(1000);
    }

    log.close();
    //connect(mgr,SIGNAL(onlineStateChanged(bool)),this,SLOT(check_online()));
    connect(client1, SIGNAL(readyRead()),this, SLOT(startread()));
    connect(client1,SIGNAL(bytesWritten(qint64)),this,SLOT(written()));
    connect(mgr,SIGNAL(onlineStateChanged(bool)),this,SLOT(check_online()));



    //check_online();

}

Elina_Scanner::~Elina_Scanner()
{
	client1->disconnectFromHost();
    delete client1;
    delete mgr;
    //delete


}

void Elina_Scanner::fortosi()
{
    fortosi_sel *w=new fortosi_sel(this);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::profortosi()
{
	profortosi_sel *w=new profortosi_sel(this);
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
	katastrofi *w= new katastrofi(this);
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
    return_roll *w= new return_roll(this);
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
    ui.pushButton_9->setEnabled(FALSE);
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


    //////
    ///
    ///
    ///

    QNetworkRequest request(QUrl("http://"+(QString)SVR_HOST+"/upload/")); //our server with php-script

    QString bound="margin"; //name of the boundary
    //according to rfc 1867 we need to put this string here:
    QByteArray data(QString("--" + bound + "\r\n").toLocal8Bit());
    data.append("Content-Disposition: form-data; name=\"action\"\r\n\r\n");
    //data.append("testuploads.php\r\n");   //our script's name, as I understood. Please, correct me if I'm wrong
    data.append("--" + bound + "\r\n");   //according to rfc 1867
    //QFile file(path);

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

void Elina_Scanner::transmit_data()
{
    QFile old_copy("apografi_1.txt");
    old_copy.remove();
    ifino=0;
    QFile file1("apografi.txt");
    file1.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file1);
    QString line=in.readLine();
    QVariant line_count=0;
    int no=0;
    while (!line.isNull())
    {
        line_count=++no;
        line=in.readLine();
    }
    file1.close();
    apogrno=line_count.toInt();
    ui.progressBar->reset();
    ui.progressBar->setMaximum(apogrno);
    ui.progressBar->setVisible(true);
	//QHostAddress addr((QString)SVR_HOST);
	//this->client1 = new QTcpSocket;
	//this->client1->connectToHost(addr, 8889);
	//client1->reset();

    qDebug()<<"EDEEEEEEEEEEEEEE:"<<write_ap<<"ooooooo"<<read_ap;
	//if(this->write_ap==FALSE)
//	{
	//	if(this->read_ap==FALSE)
		//{

	QFile file("apografi.txt");
    file.copy("apografi_1.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	if (file.size()!=0)
	{
	this->read_ap=TRUE;
    //QHostAddress addr((QString)SVR_HOST);
    //client1->connectToHost(addr, 8889);
    //NA DV AN GINETAI ACCEPT to connection ti reply dinei
	QTextStream in(&file);

	//in.setVersion(QDataStream::Qt_4_1);
    QString line=in.readLine();
	//while (in.restatus()!=QDataStream::ReadPastEnd)
    int i=0;
    while (!line.isNull())
	{

        QString code_t,code_a;
        code_t=line.left(15);
        code_a=line.mid(15,-1)+macaddress;

		//in >> code_t >> code_a;
		//qDebug()<<"ARXIKO"<<code_t;
//		if (code_t=="\EOF") qDebug()<<"MITSIS";

		//if (code_t!="")
	//	{
        this->create_row(code_t,code_a);
        records.insert(code_t,code_a);

		//}
		//else
			//{
				//in>> code_t >> code_a;
				//qDebug()<<"jimt:"<<code_t<<"jima:"<<code_a;
			//}
			//break;

		line=in.readLine();
	}
	send_final_packet();
	//qDebug()<<"ARXIKO RECORDS"<<records;
    //client1->disconnect();
	}
	file.close();
	//timer->start(30000);
    //delete(this->client1);

    //qDebug()<<"TORA VGIKA";
    //exit(0);
	//}
//}

}

void Elina_Scanner::create_row(QString code_t,QString code_a)
 {
	//qDebug()<<"EDO MPIKA LOIPON";
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="APIN";
    out << quint16(0)<<req_type<<code_t<<code_a;
    qDebug()<<code_t<<code_a;
	//qDebug()<<"Socket State"<<client->state();
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	//qDebug()<<"BLOCKSIZE:"<<client;

	client1->write(block);
    //client1->waitForBytesWritten(1000);
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



void Elina_Scanner::startread()
{
	 QDataStream in(client1);
     in.setVersion(QDataStream::Qt_4_1);
     tr:quint16 nextblocksize=0;
	qDebug()<<"DIAVASA KATI";
	forever
	{
		if (nextblocksize==0) {
			if (client1->bytesAvailable()<sizeof(quint16))
			{
					return;
			}
			in >> nextblocksize;
			qDebug() << nextblocksize;

			}

		if (nextblocksize==0xFFFF)
			{
				qDebug()<<"VGIKA:";
				goto tr;
	                    //client->close();
				//return;
			}

		if (client1->bytesAvailable()<nextblocksize)
		{
					this->read_ap=FALSE;
					nextblocksize=0;
					return;
		}
		QString	req_type;
		in >> req_type;

		qDebug() << req_type;



		QString code_rt;
		in>>code_rt;
		qDebug()<<"CODE_RT"<<code_rt;
        ++ifino;
        ui.progressBar->setValue(ifino);
		records.remove(code_rt);
		qDebug()<<"RECORDS:::::"<<records;

        QFile file("apografi.txt");
		QMapIterator<QString, QString> i(records);
		bool jim=file.remove();
		qDebug()<<"JIM:"<<jim;
		file.open(QIODevice::WriteOnly | QIODevice::Text);
		QTextStream out(&file);
		//out.setVersion(QDataStream::Qt_4_1);


		 while (i.hasNext()) {
		     i.next();
		     QString code=i.key()+i.value()+"\n";
		     out << i.key() << ": " << i.value() ;
		     out << code;
		 }
		file.close();


		this->read_ap=FALSE;
		nextblocksize=0;

}
}


//void Elina_Scanner::timerEvent(QTimerEvent *event)
 //{
  //   if (event->timerId() == timer.timerId()) {
   //      transmit_data();
    // } else {
      //   QWidget::timerEvent(event);
     //}
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
        //transmit_data();
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
    //ui->label->setText((QString)state);
    qDebug()<<state;
    //ui->label_2->setText(state);

    if (state==QAbstractSocket::ConnectedState)
    {
        //client->connectToHost(QHostAddress("192.168.0.249"), 8889);
        //client->reset();
        //client->waitForConnected(10000);
        networkstatus=TRUE;
        ui.statusLabel_2->setText("CONNECTED");

        ui.statusLabel_2->setStyleSheet("QLabel { color : green; }");
        //transmit_data();

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
        //client->reset();
        //client->waitForConnected(1000);
    }
}

//QNetworkConfigurationManager *Elina_Scanner::mgr=new QNetworkConfigurationManager();
//QNetworkConfigurationManager Elina_Scanner::mgr;

void Elina_Scanner::send()
{
    if((mgr->allConfigurations(QNetworkConfiguration::Active).count()>0) && (networkstatus==TRUE))
        //transmit_data();
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
    //qDebug()<<code_t<<code_a;

        out.device()->seek(0);
        out<<quint16(block.size()-sizeof(quint16));
        client1->write(block);
        send_final_packet();
        m.setText(trUtf8("Aποστολή απογραφής"));
        m.setStandardButtons(QMessageBox::Ok);
        m.setInformativeText(trUtf8("Η αποστολή ολοκληρώθηκε επιτυχώς!"));
        m.move(30,120);
        ui.pushButton_9->setEnabled(TRUE);
        m.exec();
    }
    else
    {
        m.setText(trUtf8("Πρόβλημα αποστολής"));
        QSound::play("bell.wav");
        m.setStandardButtons(QMessageBox::Ok);
        m.setInformativeText(trUtf8("Η αποστολή AΠΕΤΥΧΕ!!!Ελέγξτε τον http server"));
        m.move(30,120);
        ui.pushButton_9->setEnabled(TRUE);
        m.exec();

    }

    return;
}

