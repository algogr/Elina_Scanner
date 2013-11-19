#include "elina_scanner.h"

Elina_Scanner::Elina_Scanner(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(fortosi()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(profortosi()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(apografi_s()));
	read_ap=FALSE;
	write_ap=FALSE;


	QHostAddress addr((QString)SVR_HOST);
	this->client = new QTcpSocket;
	client1 = new QTcpSocket;
	QTimer *timer=new QTimer;

	//connect(client,SIGNAL(connected()),this,SLOT(error()));
	//	connect(client,SIGNAL(disconnected()),this,SLOT(error()));
		//connect(client,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(error()));
	connect(client, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(error()));
	connect(timer, SIGNAL(timeout()),this, SLOT(transmit_data()));
	connect(client1, SIGNAL(readyRead()),this, SLOT(startread()));
	timer->start(30000);
	client->connectToHost(addr, 8889);
	client1->connectToHost(addr, 8889);


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

}

void Elina_Scanner::fortosi()
{
	fortosi_sel *w=new fortosi_sel(this,client);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::profortosi()
{
	profortosi_sel *w=new profortosi_sel(this,client);
	w->show();
	w->move(0,0);
}

void Elina_Scanner::apografi_s()
{
	apografi *w=new apografi(this,client,0);
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
	qDebug()<<"EDEEEEEEEEEEEEEE:"<<write_ap<<"ooooooo"<<read_ap;
	//if(this->write_ap==FALSE)
//	{
	//	if(this->read_ap==FALSE)
		//{

	QFile file("apografi.dat");

	file.open(QIODevice::ReadOnly);
	if (file.size()!=0)
	{
	this->read_ap=TRUE;
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_4_1);

	while (in.status()!=QDataStream::ReadPastEnd)
	{

		QString code_t,code_a;

		in >> code_t >> code_a;
		qDebug()<<"ARXIKO"<<code_t;
		if (code_t!="")
		{
		this->create_row(code_t,code_a);
		records.insert(code_t,code_a);
		}
		//else
			//break;
	}
	send_final_packet();
	qDebug()<<"ARXIKO RECORDS"<<records;
	}
	file.close();
	//timer->start(30000);



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
	//qDebug()<<code_t<<code_a;
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

		QFile file("apografi.dat");
		QMapIterator<QString, QString> i(records);
		bool jim=file.remove();
		qDebug()<<"JIM:"<<jim;
		file.open(QIODevice::WriteOnly);
		QDataStream out(&file);
		out.setVersion(QDataStream::Qt_4_1);


		 while (i.hasNext()) {
		     i.next();
		     out << i.key() << ": " << i.value() ;
		 }
		file.close();


		this->read_ap=FALSE;
		nextblocksize=0;

}
}
