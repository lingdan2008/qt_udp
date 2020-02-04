#include <QCoreApplication>
#include <QUdpSocket>
#include <QHostAddress>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("-------------client-------------\n");

    QString data = "Hello, Server";
    QByteArray ba = data.toUtf8();
    quint64 port = 2333;
    QUdpSocket socket;

    for(int i=0; i<3; i++) {
        qint64 len = socket.writeDatagram(ba, QHostAddress("127.0.0.1"), port);
        printf("the length of send datagram : %d\n", len);
    }

    return a.exec();
}
