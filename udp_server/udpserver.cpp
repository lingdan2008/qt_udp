#include "udpserver.h"
#include <iostream>
#include <QNetworkDatagram>

UdpServer::UdpServer(QObject *parent) : QObject(parent)
{
    m_port = 2333;
    m_socket = new QUdpSocket();
    m_socket->bind(QHostAddress("127.0.0.1"), m_port);

    QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(recvData()));
}

UdpServer::~UdpServer()
{
    delete m_socket;
}

void UdpServer::recvData()
{
    while(m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        QByteArray ba = datagram.data();

        std::cout << ba.toStdString() << std::endl;
    }
}
