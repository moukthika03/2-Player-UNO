#include "server.h"
#include <string>
#include <iostream>


using namespace std;

server :: server(QObject *parent) : QObject(parent)
{
    cout << "\ninside_server\n";
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



void server :: newConnection()
{
    qDebug() << "Connected to the Client";
    string client_cards_string = game.shuffle_and_distribute();
    QTcpSocket *socket = ser->nextPendingConnection();
    char buf[1024] = {0};
    strcpy(client_cards, client_cards_string.c_str());
    socket->write(client_cards);
    socket->flush();
    socket->waitForBytesWritten(30000);
    int selected;
    while(true)
    {
        game.displayCards();
        cout << "\nEnter the card number you want to choose ( 0 to take a card from deck ): " ;
        while(true)
        {
            cin >> selected;
            if(game.verify(game.player.card_list[selected]))
                break;
            else
                cout << "Please enter a valid input: ";
        }

        game.card_list[game.player.card_list[selected]-1]->play();

        string str =  to_string(game.top_card);
        strcpy(buf, str.c_str());
        socket->write(buf);
        socket->flush();
        socket->waitForBytesWritten(30000);

        socket->waitForReadyRead();
        socket->read(buf, sizeof(buf));
        break;
    }
    /*while(true)
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
