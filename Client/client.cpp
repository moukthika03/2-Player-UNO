#include <bits/stdc++.h>
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
string client :: convertToString(char* a)
{
    int i = 0;
    string s = "";
    while(a[i] != '\0') {
        s = s + a[i];
        i++;
    }
    cout << "\nS is " << s << endl;
    return s;
}
void client::readyRead()
{
    qDebug() << "Reading\n";
    //QString str;
    char buf[1024] = {0};
    //str = QTextCodec::codecForMib(1015)->toUnicode(socket->readLine());
    socket->read(buf, sizeof(buf));
    cout << buf;
    string s = convertToString(buf);
    game.setFirstCards(s);
    int selected;
    while(true)
    {
        socket->waitForReadyRead();
        socket->read(buf, sizeof(buf));
        cout << "\nThe topcard is now: " << buf;
        cout << "\nEnter the card number you want to choose ( 0 to take a card from deck ): " ;
        cin >> selected;
        string str =  to_string(selected);
        strcpy(buf, str.c_str());
        socket->write(buf);
        socket->flush();
        socket->waitForBytesWritten(30000);

        break;
    }

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
    socket->close();
    qDebug("\nCompleted");

}
