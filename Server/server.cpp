#include "server.h"
#include <iostream>
using namespace std;

server::server(QObject *parent) : QObject(parent)
{
    ser = new QTcpServer(this);
   // whenever a user connects, it will emit signal
   connect(ser, SIGNAL(newConnection()),this, SLOT(newConnection()));
   if(!ser->listen(QHostAddress::Any, 9999))
   {
       qDebug() << "Server could not start";
   }
   else
   {
       qDebug() << "Server started!";
   }
}

void server::newConnection()
{
    qDebug() <<  "Connected";
    // need to grab the socket
    QTcpSocket *socket = ser->nextPendingConnection();
    socket->write("Hello client this is the QTcpServer on port 9999");
    socket->flush();

    socket->waitForBytesWritten();
    char buf[1024] = {0};
         //str = QTextCodec::codecForMib(1015)->toUnicode(socket->readLine());
         socket->read(buf, sizeof(buf));
         qDebug() << buf;

    qDebug() <<  "Write done";
    socket->close();
}