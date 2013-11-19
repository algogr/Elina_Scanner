#include "fortosi_new_1.h"
#include <QHostAddress>


fortosi_new_1::fortosi_new_1(QWidget *parent,QTcpSocket *pclient)
    : QDialog(parent)
{
	this->parent=parent;

	ui.setupUi(this);
	client= pclient;

	//QHostAddress addr((QString)SVR_HOST);
	nextblocksize=0;

	ui.tableWidget->setColumnCount(2);
		ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("Κωδ.Πελάτη")<<trUtf8("Πελάτης"));

		ui.tableWidget->setColumnWidth(0,0);
		ui.tableWidget->setColumnWidth(1,280);
	//client = new QTcpSocket;
    //client->connectToHost(addr, 8888);
    connect(client, SIGNAL(readyRead()),this, SLOT(startread()));
    connect(ui.pushFront,SIGNAL(clicked()), this, SLOT(next()));
    connect(ui.pushBack, SIGNAL(clicked()), this, SLOT(back()));
    connect(ui.lineEdit_3, SIGNAL(textChanged(const QString &)), this,
    			SLOT(requestCustomers()));
    connect(ui.tableWidget,SIGNAL(cellClicked(int ,int )),this, SLOT(tableclicked(int,int)));
    	//connect(client, SIGNAL(connected()),this, SLOT(requestCustomers()));
    //requestCustomers();

    //this->nt=new network_test((QString)SVR_HOST,8889,ui.pushFront);
    ui.lineEdit_3->setFocus();




}

fortosi_new_1::~fortosi_new_1()
{

}

void fortosi_new_1::startTransfer()
{


}

void fortosi_new_1::requestCustomers()
 {
	QString like;
	like=ui.lineEdit_3->text();

	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type="RC";
	out << quint16(0)<<req_type<<like;
	out.device()->seek(0);
	out<<quint16(block.size()-sizeof(quint16));
	client->write(block);
 }

 void fortosi_new_1::startread()
 {

	 QDataStream in(client);

	 in.setVersion(QDataStream::Qt_4_1);
	 int r=0;
	 ui.tableWidget->setRowCount(r);
	 forever
	 	{

	 		if (nextblocksize==0) {

	 			if (client->bytesAvailable()<sizeof(quint16))
	 				break;
	 		//	qDebug()<<"MPIKA1";
	 		in >> nextblocksize;


	 		}

	 		if (nextblocksize==0xFFFF)
	 		{
	 			//client->close();
	 			break;
	 		}

	 		if (client->bytesAvailable()<nextblocksize)
	 			break;
	 		QString	cname,ccode;

	 		in >> ccode >> cname;
	 		qDebug()<<"CODE:"<<ccode<<" NAME:"<<cname;

	 		QTableWidgetItem *a=new QTableWidgetItem;
			QTableWidgetItem *b=new QTableWidgetItem;
	 		a->setText(ccode);
			b->setText(cname);
			a->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			b->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	 		ui.tableWidget->setRowCount(r+1);
	 		ui.tableWidget->setItem(r,0,a);
			ui.tableWidget->setItem(r,1,b);


	 		++r;

	 		//qDebug() << req_type;
	 		nextblocksize=0;
	 	}
			 nextblocksize=0;

 }

 void fortosi_new_1::next()
 {
	 QString customer= ui.tableWidget->item(rowsel,1)->text();
	 QString ccode=ui.tableWidget->item(rowsel,0)->text();
	 QString car1=ui.lineEdit->text();
	 QString car2=ui.lineEdit_2->text();
	 qDebug()<<"new:"<<client;
	 fortosi_new_1_b *w= new fortosi_new_1_b(this->parent,client,ccode,customer,car1,car2);
	 w->move(0,0);
	 w->show();
	 delete (nt);
	 delete(this);


 }

 void fortosi_new_1::back()

 {
	 delete (nt);
	 delete(this);
 }

 void fortosi_new_1::tableclicked(int row,int col)
 {

 	this->rowsel=row;
 	//ui.lineEdit_3->setText(ui.tableWidget->item(row,1)->text());
 	//ui.lineEdit_3->setFocus();
 }


