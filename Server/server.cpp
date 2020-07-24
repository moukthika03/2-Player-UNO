#include "server.h"
#include <string>
#include <iostream>

using namespace std;

server :: server(QObject *parent) : QObject(parent)
{
    Card* temp;
    int i;
    for(i = 1; i <= 108; i++)
    {
        if(i >= 105)
            temp =  new drawFour(i, 4);
        else if(i >= 101)
            temp = new Wild(i);
        else
        {
            char c;
            if(i <= 25)
                c = 'r';
            else if(i <= 50)
                c = 'g';
            else if(i <= 75)
                c = 'b';
            else
               c = 'y';
            if((i % 25) <= 10 && i % 25 !=0)
            {
                temp = new Numbered(i%25-1, c);
            }
            else if((i % 25) <= 19 && i % 25 != 0)
            {
                temp = new Numbered(i%25-10, c);
            }
            else if((i%25) <= 21 && i % 25 != 0)
            {
                temp = new Skip(i ,c);
            }
            else if((i%25) <= 21 && i % 25 != 0)
            {
                temp = new Reverse(i, c);
            }
            else
            {
                temp = new drawTwo(2, i);
            }
            card_list.push_back(temp);
        }
    }
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

string server :: convertToString(char* a)
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

            if(game.verify(game.player.card_list[selected-1]))
                break;
            else
                cout << "Please enter a valid input: ";
        }
        if (selected == 0)
        {
            bool flag = game.drawCards();
            if(!game.verifyAll())
            {
                if(flag)
                {
                    cout << "You have received and played " << game.getColor( game.top_card) << " " <<  game.getNumber( game.top_card) << endl;

                }
                else
                {
                    cout << "You have received a card" << endl;
                }
            }

            string str =  to_string(game.top_card);
            strcpy(buf, str.c_str());
            socket->write(buf);
            socket->flush();
            socket->waitForBytesWritten(30000);

            continue;
        }
        else
        {
           int val = game.player.card_list[selected - 1];
           string str =  card_list[game.player.card_list[selected]-1]->play(game, val);
           strcpy(buf, str.c_str());
           socket->write(buf);
           socket->flush();
           socket->waitForBytesWritten(30000);
        }



       /* string str =  to_string(game.top_card);
        strcpy(buf, str.c_str());
        socket->write(buf);
        socket->flush();
        socket->waitForBytesWritten(30000);*/

        l1:socket->waitForReadyRead();
        socket->read(buf, sizeof(buf));

        if(strcmp(buf, "0") == 0)
        {
            //read card from deck
            int val;
            string send;
            val = game.shuffled[0];
            send = to_string(val);
            strcpy(buf, send.c_str());
            socket->write(buf);
            socket->flush();
            socket->waitForBytesWritten(30000);
            socket->waitForReadyRead();
            socket->read(buf, sizeof(buf));
            game.top_card = atoi(buf);
        }
        else
        {
            char *token = strtok(buf, " ");
            int sent_by_client = stoi(convertToString(token));
            if(sent_by_client % 25 == 20 || sent_by_client % 25 == 21 || sent_by_client % 25 == 22 || sent_by_client % 25 == 23 )
             {
                card_list[sent_by_client - 1]->play(game, sent_by_client, 'c');
                goto l1;
             }

            string sent = convertToString(buf);
            int value = stoi(sent);
            card_list[value - 1]->play(game, value, 'c');
        }
        //server's turn again
        break;
    }



    socket->close();
}
