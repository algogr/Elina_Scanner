#include <QSound>
#include "apografi.h"
#include "stdio.h"
#include <iostream>

apografi::apografi(QWidget *parent,QTcpSocket client1,int mode)
    : QDialog(parent)
{

	ui.setupUi(this);
	ui.label->setVisible(FALSE);
	QHostAddress addr((QString)SVR_HOST);
	client=new QTcpSocket;
	client->connectToHost(addr, 8889);
	//client_w=new QTcpSocket;
	this->parent=(Elina_Scanner*)parent;

	//this->client=client;
	this->r=0;
	this->mode=mode;
	lastscanned="A";
	row_sent=1;
	insert_verification=TRUE;
	nextblocksize=0;

	if (mode==0)
	{
			ui.tableWidget->setColumnCount(2);
			ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("K/T")<<trUtf8("K/A"));
			ui.tableWidget->setColumnWidth(0,200);
			ui.tableWidget->setColumnWidth(1,200);

	}
			else
			{
		ui.tableWidget->setColumnCount(1);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("K/T"));
		ui.tableWidget->setColumnWidth(0,200);
			}
	ui.pushButton->setFocusPolicy(Qt::NoFocus);
	ui.tableWidget->setFocusPolicy(Qt::NoFocus);
	//this->timer = new QTimer();
	//connect(timer, SIGNAL(timeout()), this, SLOT(check_conn()));
    //timer->start(1000);
    //this->test=new QTcpSocket;

	connect (ui.lineScan,SIGNAL(returnPressed()),this,SLOT(scan()));
	connect (ui.lineScan,SIGNAL(lostFocus()),this,SLOT(lock()));
	//connect(client, SIGNAL(readyRead()),this, SLOT(startread()));
	connect(ui.pushButton,SIGNAL(released()),this,SLOT(insert_db()));
	//connect(test, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(error()));
	//connect(client,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(status_disconn()));
	//connect(client, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(status_disconn()));

}

apografi::~apografi()
{

}

void apografi::scan()
{
	ui.pushButton->setFocusPolicy(Qt::NoFocus);
	if (mode==1)
			{
	QString scanned=ui.lineScan->text();
	for (int i=0;i<ui.tableWidget->rowCount();++i)
	{
		if(ui.tableWidget->item(i,0)->text()==scanned)
		{
			QMessageBox m;
			QSound::play("bell.wav");
			m.setText(trUtf8("O K/T έχει ήδη διαβαστεί"));
			m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
			m.setStandardButtons(QMessageBox::NoButton);
			m.move(0,100);
			QFont serifFont("Times", 18, QFont::Bold);
			m.setFont(serifFont);

			m.exec();
			ui.lineScan->setText("");
			ui.lineScan->setFocus();

			return;
		}

	}

	ui.tableWidget->setRowCount(r+1);
	QTableWidgetItem *code=new QTableWidgetItem;

	if (r>0)
	code->setText(ui.tableWidget->item(r-1,0)->text());

	ui.tableWidget->setItem(r,0,code);



    for (int i=r-1;i>0;--i)
    {

    	ui.tableWidget->item(i,0)->setText(ui.tableWidget->item(i-1,0)->text());


    }
    ui.tableWidget->item(0,0)->setText(scanned);

	//ui.tableWidget->setItem(0,0,code);
	ui.lineScan->setText("");
	ui.lineScan->setFocus();
	//checkdb(scanned);
	++r;
			}

	else
	{
		QString scanned=ui.lineScan->text();
		if(lastscanned.left(1)=="A" && scanned.left(1)=="A")
		{

			for (int i=0;i<15;++i)
			{
				QApplication::beep();
					}
			QMessageBox m;
			QPushButton *q=new QPushButton;
			m.setText(trUtf8("Πρέπει να διαβαστεί Κ/Τ"));
			m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
			m.setStandardButtons(QMessageBox::Ok);
			//m.setEscapeButton(QMessageBox::Ok);
			//m.addButton(q,QMessageBox::RejectRole);
			//m.setStyleSheet(Qt::NoButton);
			//m.setDefaultButton(q);
			//q->setFocus();
			//q->setVisible(FALSE);
			m.move(0,100);
			QFont serifFont("Times", 18, QFont::Bold);
			m.setFont(serifFont);

			m.exec();

			ui.lineScan->setText("");
			ui.lineScan->setFocus();
			return;


		}

		if(lastscanned.left(1)!="A" && scanned.left(1)!="A")
				{
			for (int i=0;i<15;++i)
						{
							QApplication::beep();
								}


					QMessageBox m;
					m.setText(trUtf8("Πρέπει να διαβαστεί Κ/A"));
					m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
					m.setStandardButtons(QMessageBox::Ok);
					QFont serifFont("Times", 18, QFont::Bold);
					m.setFont(serifFont);

					m.move(0,100);
					m.exec();
					ui.lineScan->setText("");
					ui.lineScan->setFocus();
					return;


				}


			for (int i=0;i<ui.tableWidget->rowCount();++i)
			{
				if(ui.tableWidget->item(i,0)->text()==scanned)
				{
					for (int i=0;i<15;++i)
								{
									QApplication::beep();
										}
					QMessageBox m;
					m.setText(trUtf8("O K/T έχει ήδη διαβαστεί"));
					m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
					m.setStandardButtons(QMessageBox::Ok);
					m.move(0,100);
					QFont serifFont("Times", 18, QFont::Bold);
					m.setFont(serifFont);

					m.exec();
					ui.lineScan->setText("");
					ui.lineScan->setFocus();
					return;
				}

			}
			if (scanned.left(1)!="A")
			{
			ui.tableWidget->setRowCount(r+1);
			QTableWidgetItem *code=new QTableWidgetItem;
			QTableWidgetItem *code_a=new QTableWidgetItem;
			if (r>0)
			{
			code->setText(ui.tableWidget->item(r-1,0)->text());
			code_a->setText(ui.tableWidget->item(r-1,1)->text());
			}
			ui.tableWidget->setItem(r,0,code);
			ui.tableWidget->setItem(r,1,code_a);



		    for (int i=r-1;i>0;--i)
		    {

		    	ui.tableWidget->item(i,0)->setText(ui.tableWidget->item(i-1,0)->text());
		    	ui.tableWidget->item(i,1)->setText(ui.tableWidget->item(i-1,1)->text());

		    }
		    ui.tableWidget->item(0,0)->setText(scanned);
		    ui.tableWidget->item(0,1)->setText("");

			//ui.tableWidget->setItem(0,0,code);
			ui.lineScan->setText("");
			ui.lineScan->setFocus();
			//checkdb(scanned);
//			++r;


			}
			else
			{
				ui.tableWidget->item(0,1)->setText(scanned);
				ui.lineScan->setText("");
				ui.lineScan->setFocus();

				++r;

			}
			lastscanned=scanned;
	}
	ui.pushButton->setFocusPolicy(Qt::NoFocus);

}

void apografi::checkdb(QString code_t)
 {
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="APCH";
	out << quint16(0)<<req_type<<code_t;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
 }
int apografi::startread_1()
{
	return 1;
}

int apografi::startread()
 {

	 QDataStream in(client);

	 in.setVersion(QDataStream::Qt_4_1);

	 //nextblocksize=0;
	 QString type,code_t;

	 qDebug()<<"MPIKA";

	 forever
	 	{
	 		ter: if (nextblocksize==0) {
	 			qDebug()<< client->bytesAvailable();
	 			if (client->bytesAvailable()<sizeof(quint16))
	 				break;
	 		in >> nextblocksize;


	 		}

	 		if (nextblocksize==0xFFFF)
	 		{


	 			if (client->bytesAvailable()<sizeof(quint16))
	 			{
	 				if (confirmed.size()==ui.tableWidget->rowCount())
	 				{
					delete(this);
	 				break;
	 				}
	 				else
	 					verify_codes();

	 			}

	 			in >> nextblocksize;
	 			qDebug()<<"TELIKO nextblocksize:"<<nextblocksize;
	 			goto ter;
	 		}

	 		if (client->bytesAvailable()<nextblocksize)
	 			break;


	 		in >> type >> code_t;
	 		qDebug()<<"code_t:reply"<<code_t;
	 		qDebug()<<"type"<<type;
	 		confirmed << code_t;
	 		qDebug()<< confirmed;

	 			 		//if(type=="APIN")
			//{

	 			//client->reset();
			//}







	 		//qDebug() << req_type;
	 		nextblocksize=0;
	 	}
		 nextblocksize=0;
		 return 0;

}

void apografi::insert_db()
{
	ui.pushButton->setEnabled(FALSE);
	ui.lineScan->setEnabled(FALSE);
	ui.label->setVisible(TRUE);
	//forever
	//{
		qDebug()<<"FLAG READ:"<<parent->read_ap;
	//if (parent->read_ap==FALSE)
	//	{
		parent->write_ap=TRUE;
		QFile file("apografi.dat");
		QMap <QString,QString> records;
		if (!file.exists())
		{
		if (!file.open(QIODevice::WriteOnly)) {
		qDebug() << "Cannot open file for writing: "
		<< qPrintable(file.errorString()) << endl;

		}
		}
		else file.open(QIODevice::Append);
		QDataStream out(&file);
		out.setVersion(QDataStream::Qt_4_1);




		for (int i=0;i<ui.tableWidget->rowCount();i++)
		{


		QString code_t=ui.tableWidget->item(i,0)->text();
		QString code_a=ui.tableWidget->item(i,1)->text();
		//records.insert(code_t,code_a);

		out << code_t <<code_a;
		if (code_t !="")
		create_row(code_t,code_a);
		//sleep(5);
		//if (client->canReadLine ())
		//startread();
		//if (this->insert_verification!=TRUE)
			//goto tr;

		}
		//out << records;
		file.close();
		parent->write_ap=FALSE;


		//return;
	//}
	//}
		//else i-=1;
	//return;

	delete(this);
}


void apografi::create_row(QString code_t,QString code_a)
 {
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="APIN";
	out << quint16(0)<<req_type<<code_t<<code_a;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	qDebug()<<"BLOCKSIZE1:"<<block;
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block,QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);


	return;
 }

void apografi::lock()
{
	ui.lineScan->setFocus();
}

void apografi::check_conn()
{
	QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

	    foreach(const QNetworkInterface & interface, interfaces)
	    {
	        //if (interface.flags() & QNetworkInterface::IsUp)
	            //qDebug() << interface.name() << interface.flags();
	            //if (interface.flags()==37)
	            	//qDebug()<<"jim1";
	    }

	ui.pushButton->setEnabled(TRUE);
	//qDebug()<<"jim";
	//QHostAddress addr((QString)SVR_HOST);
	//test->connectToHost(addr,8889);
	//=client->isReadable();
	bool test=client->isValid();
	///qDebug()<<"READABLE"<<test;
	//test->close();
	//test->abort();
	//ui.pushButton->setEnabled(TRUE);
}



bool apografi::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusOut)
    	ui.lineScan->setFocus();
    return FALSE;
}

void apografi::error()
{
	ui.pushButton->setEnabled(FALSE);
}



void apografi::verify_codes()
{
	for (int i=0;i<ui.tableWidget->rowCount();i++)
	{
		if(confirmed.contains(ui.tableWidget->item(i,0)->text()))
				confirmed.removeAll(ui.tableWidget->item(i,0)->text());

		retransmit(i);

	}
}
void apografi::retransmit(int i)
{
	QString code_t=ui.tableWidget->item(i,0)->text();
	QString code_a=ui.tableWidget->item(i,1)->text();
	confirmed.removeAll(ui.tableWidget->item(i,0)->text());
	create_row(code_t,code_a);
}






