#include "algotcpsocket.h"
#include <QNetworkConfiguration>
AlgoTcpSocket::AlgoTcpSocket(QHostAddress address,int tcpPort):QTcpSocket(),ipAddress(address),port(tcpPort),mgr()
{
    connect(this,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(checkState(QAbstractSocket::SocketState)));
    connect(&mgr,SIGNAL(onlineStateChanged(bool)),this,SLOT(checkOnline()));

}

AlgoTcpSocket::~AlgoTcpSocket()
{
    qDebug()<<"Algo closed";
}

void AlgoTcpSocket::connectToHost()
{
    QTcpSocket::connectToHost(ipAddress,port);

}

void AlgoTcpSocket::checkState(QAbstractSocket::SocketState state)
{
    if (state==QAbstractSocket::ConnectedState)
        networkstatus=TRUE;



    else if(state==QAbstractSocket::UnconnectedState)
    {
        networkstatus=FALSE;
        connectToHost();
   }


}

void AlgoTcpSocket::checkOnline()
{
    QList<QNetworkConfiguration> activeConfigs = mgr.allConfigurations(QNetworkConfiguration::Active);
    if (activeConfigs.count() > 0)
    {

        connectToHost();
        qDebug()<<"ONLINE";
        networkstatus=TRUE;


    }
    else
        {
            //abort();
            //close();
            qDebug()<<"OFFLINE";
            networkstatus=FALSE;
        }

}
