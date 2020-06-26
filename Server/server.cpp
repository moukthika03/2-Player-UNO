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
    char* buf = new char [1024];

    socket->write("Hello client this is the QTcpServer on port 9999");
    socket->flush();
    socket->waitForBytesWritten(30000);
    while(buf[0] != '!')
    {
        socket->waitForReadyRead();
        socket->read(buf, sizeof(buf));
        cout << "\n\nMessage sent by Client is: " << buf;

        cout << "\n\nEnter the message: ";
        cin >> buf;
        cin.sync();
        socket->write(buf);
        socket->flush();
        socket->waitForBytesWritten(30000);
    }
    cout << "\n\nClosing the socket";

    socket->close();
}
