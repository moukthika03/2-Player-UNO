#include "server.h"
#include <string>
#include <iostream>

using namespace std;

server :: server(QObject *parent) : QObject(parent)
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

void server :: set_clinet_cards(string str_1)
{
    int n = str_1.length();
    strcpy(client_cards, str_1.c_str());
}

void server :: newConnection()
{
    qDebug() << "Connected";
    // need to grab the socket
    QTcpSocket *socket = ser->nextPendingConnection();
   // char buf[1024] = {0};
    socket->write(client_cards);
    socket->flush();
    socket->waitForBytesWritten(30000);
    /*while(buf[0] != '!')
    {
        socket->waitForReadyRead();
        socket->read(buf, sizeof(buf));

        if(!strcmp(buf, "end") || !strcmp(buf, "End") || !strcmp(buf, "END"))
        {
            cout << "Client closed the connection" << endl;
            cout << "Closing connection...";
            break;
        }
        cout << "\n\nMessage sent by Client is: " << buf;

        cout << "\n\nEnter the message: ";
        cin >> buf;
        cin.sync();
        socket->write(buf);
        socket->flush();
        socket->waitForBytesWritten(30000);
    }*/


    socket->close();
}
