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


Elina_Scanner::Elina_Scanner(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	//this->showFullScreen();
	QRegExp jim("\\A\\d{3,3}[X-Z]\\d{1,1}");


	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(fortosi()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(profortosi()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(apografi_s()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(katastrofi_s()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(change_label_s()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(read_label_s()));
    connect(ui.pushButton_8, SIGNAL(clicked()),this,SLOT(rewrap_label()));
    connect(ui.pushButton_3, SIGNAL(clicked()),this,SLOT(returnroll()));


	read_ap=FALSE;
	write_ap=FALSE;
	QString ipath=(QString)APATH+"/img/app.png";
	QIcon *icon=new QIcon(ipath);

	this->setWindowIcon(*icon);

	QString ipath1=(QString)APATH+"/img/truck1.png";
	QIcon *icon1=new QIcon(ipath1);
	ui.pushButton->setIcon(*icon1);

	QString ipath2=(QString)APATH+"/img/prof.jpeg";
	QIcon *icon2=new QIcon(ipath2);
	ui.pushButton_7->setIcon(*icon2);

	QString ipath3=(QString)APATH+"/img/apo.jpeg";
	QIcon *icon3=new QIcon(ipath3);
	ui.pushButton_2->setIcon(*icon3);

	QString ipath4=(QString)APATH+"/img/kat.jpeg";
	QIcon *icon4=new QIcon(ipath4);
	ui.pushButton_6->setIcon(*icon4);

	QString ipath5=(QString)APATH+"/img/change.png";
	QIcon *icon5=new QIcon(ipath5);
	ui.pushButton_4->setIcon(*icon5);

	QString ipath6=(QString)APATH+"/img/read.png";
	QIcon *icon6=new QIcon(ipath6);
	ui.pushButton_5->setIcon(*icon6);

    QString ipath7=(QString)APATH+"/img/rewrap.png";
    QIcon *icon7=new QIcon(ipath7);
    ui.pushButton_8->setIcon(*icon7);

    QString ipath8=(QString)APATH+"/img/return.png";
    QIcon *icon8=new QIcon(ipath8);
    ui.pushButton_3->setIcon(*icon8);

	QHostAddress addr((QString)SVR_HOST);
	this->client1 = new QTcpSocket;
	//client1 = new QTcpSocket;
	QTimer *timer=new QTimer;
	//QBasicTimer *timer=new QBasicTimer;
	//connect(client,SIGNAL(connected()),this,SLOT(error()));
	//	connect(client,SIGNAL(disconnected()),this,SLOT(error()));
		//connect(client,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(error()));
	//connect(client, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(error()));
	connect(timer, SIGNAL(timeout()),this, SLOT(transmit_data()));
	connect(client1, SIGNAL(readyRead()),this, SLOT(startread()));
	timer->start(30000);
	//timer->start(1);
	//timer->start(30000,this);
	client1->connectToHost(addr, 8889);
	//client1->connectToHost(addr, 8889);


	//transmit_data();

//	create_row("LALALALALALALAL","LALALAKKAJKJAKJAKJKA");


	//sleep(5);

	//if (client->state()!=QAbstractSocket::ConnectedState)
	//{
		//exit(0);
	//}
	//QApplication::beep();

	//connect(client, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(error()));
}

Elina_Scanner::~Elina_Scanner()
{
	client1->disconnectFromHost();

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


void Elina_Scanner::error()
{
	//QHostAddress addr((QString)SVR_HOST);
	//forever
	//{
		//client->connectToHost(addr,8889);
		//if(client)
			//return;
	//}
	//qDebug()<<"LALAQLALA:"<<client->state();
	//delete (this);
	QMessageBox m;
	m.setText(trUtf8("Δεν υπάρχει σύνδεση στο δίκτυο"));
	m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
	m.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	QFont serifFont("Times", 18, QFont::Bold);
	m.setFont(serifFont);
	m.move(0,100);
	int ret=m.exec();
	switch (ret){

	case QMessageBox::Cancel:
		exit(0);
		break;
	case QMessageBox::Ok:
		forever
		{
			bool test=client->isOpen();
			qDebug()<< "TEST:" << test;
			QHostAddress addr((QString)SVR_HOST);
			client->connectToHost(addr, 8889);
			if (test==TRUE)
			break;
		}
	break;
	}

}

void Elina_Scanner::transmit_data()
{
	//QHostAddress addr((QString)SVR_HOST);
	//this->client1 = new QTcpSocket;
	//this->client1->connectToHost(addr, 8889);
	//client1->reset();
	//qDebug()<<"EDEEEEEEEEEEEEEE:"<<write_ap<<"ooooooo"<<read_ap;
	//if(this->write_ap==FALSE)
//	{
	//	if(this->read_ap==FALSE)
		//{

	QFile file("apografi.txt");

	file.open(QIODevice::ReadOnly | QIODevice::Text);
	if (file.size()!=0)
	{
	this->read_ap=TRUE;
	QTextStream in(&file);

	//in.setVersion(QDataStream::Qt_4_1);
    QString line=in.readLine();
	//while (in.restatus()!=QDataStream::ReadPastEnd)
    while (!line.isNull())
	{

		QString code_t,code_a;
        code_t=line.left(15);
        code_a=line.right(15);
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
