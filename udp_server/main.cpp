#include <QCoreApplication>
#include "udpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("-------------server-------------\n");
    UdpServer socket;

    return a.exec();
}
