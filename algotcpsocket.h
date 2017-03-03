#ifndef ALGOTCPSOCKET_H
#define ALGOTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkConfigurationManager>
#include <QHostAddress>

class AlgoTcpSocket : public QTcpSocket
{

    Q_OBJECT

private:

    QHostAddress ipAddress;
    int port;
    QNetworkConfigurationManager mgr;
public:
    AlgoTcpSocket(QHostAddress address,int tcpPort);
    ~AlgoTcpSocket();
    bool networkstatus;
    void connectToHost();


private slots:
    void checkState(QAbstractSocket::SocketState state);
    void checkOnline();

};

#endif // ALGOTCPSOCKET_H
