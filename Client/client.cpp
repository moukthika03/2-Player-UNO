
#include "client.h"
#include <QDebug>
#include <iostream>
#include <QTextCodec>
using namespace std;

client::client(QObject* parent):QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    socket->connectToHost("localhost", 9999);
    if (socket->waitForConnected(30000))
        qDebug("Connected!");
}

void client::readyRead()
{
    qDebug() << "Reading\n";
    //QString str;
    char buf[1024] = {0};
    //str = QTextCodec::codecForMib(1015)->toUnicode(socket->readLine());
    socket->read(buf, sizeof(buf));
    cout << buf;
    /*while(buf[0] != '!')
    {
        char buf_2[1024] = {0};
        cout << "\n\nEnter the message: ";
        cin >> buf_2;
        cin.sync();
        socket->write(buf_2);
        socket->flush();
        socket->waitForBytesWritten(30000);

        socket->waitForReadyRead();
        socket->read(buf_2, sizeof(buf_2));
        if(!strcmp(buf, "end") || !strcmp(buf, "End") || !strcmp(buf, "END"))
        {
        cout << "Server closed the connection" << endl;
        cout << "Closing connection...";
        break;
        }

        cout << "Message sent by Server is: " << buf_2 << endl;
    }*/

    qDebug("\nCompleted");

}
