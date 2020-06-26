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
    while(buf[0] != '!')
    {
        cout << "\n\nEnter the message: ";
        cin >> buf;
        cin.sync();
        socket->write(buf);
        socket->flush();
        socket->waitForBytesWritten(30000);

        socket->waitForReadyRead();
        socket->read(buf, sizeof(buf));
        cout << "Message sent by Server is: " << buf << endl;
    }

    qDebug("\nCompleted");

}
