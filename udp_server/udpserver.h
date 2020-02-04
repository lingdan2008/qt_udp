#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>


class UdpServer : public QObject
{
    Q_OBJECT
public:
    explicit UdpServer(QObject *parent = nullptr);
    virtual ~UdpServer();
signals:

public slots:
    void recvData();

private:
    QUdpSocket *m_socket;
    quint64 m_port;
};

#endif // UDPSERVER_H
