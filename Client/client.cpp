#include "client.h"
#include <QDebug>
#include <iostream>
#include <QTextCodec>
using namespace std;

client::client(QObject* parent):QObject(parent)
{
    qDebug() << "Constructor\n";
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
    char buf[1024];
         //str = QTextCodec::codecForMib(1015)->toUnicode(socket->readLine());
         socket->read(buf, sizeof(buf));
         qDebug() << buf;
         //cout << buf << endl;

    qDebug("\nDone");

}
