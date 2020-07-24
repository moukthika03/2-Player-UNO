#include <bits/stdc++.h>
#include "client.h"
#include "game.h"
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
        char *token = strtok(buf, " ");
        if(strcmp(token, "1") == 0)
        {
            token = strtok(NULL, " ");
            game.top_card = stoi(convertToString(token));
            if(game.top_card % 25 == 20 || game.top_card % 25 == 21 )
            {
                cout << "Your chance has been 'Skipped' as the player has played a skip card" << endl;
                continue;
            }
            if(game.top_card % 25 == 24 || game.top_card % 25 == 25)
            {
                 cout << "Your chance has been 'Skipped' as the player has played a reverse card" << endl;
                 continue;
            }
           l1: game.displayCards();
            cout << "\nEnter the card number you want to choose ( 0 to take a card from deck ): " ;
            while(true)
            {
                cin >> selected;
                selected--;
                if(game.verify(game.player.card_list[selected]))
                    break;
                else
                    cout << "Please enter a valid input";
            }
            if (selected == 0 && !game.verifyAll())
            {
                strcpy(buf, "0");

                socket->write(buf);
                socket->flush();
                socket->waitForBytesWritten(30000);


                socket->waitForReadyRead();
                socket->read(buf, sizeof(buf));

                string str = convertToString(buf);

                int value = stoi(str);
                if(game.verify(value))
                {
                    cout << "You have received and played" << game.getColor(value) << " " << game.getNumber(value) << endl;
                    game.top_card = value;
                    string str =  to_string(value);
                    strcpy(buf, str.c_str());
                    socket->write(buf);
                    socket->flush();
                    socket->waitForBytesWritten(30000);
                }
                else
                {
                    cout << "You have received" << game.getColor(value) << " " << game.getNumber(value) << endl;
                    game.player.card_list.push_back(value);
                    string str =  to_string(game.top_card);
                    strcpy(buf, str.c_str());
                    socket->write(buf);
                    socket->flush();
                    socket->waitForBytesWritten(30000);
                }

            }
            else if(game.player.card_list[selected-1] % 25 == 20 || game.player.card_list[selected-1] % 25 == 21 || game.player.card_list[selected-1]% 25 == 24 || game.player.card_list[selected-1] % 25 == 25 )
            {
                game.player.card_list.erase(game.player.card_list.begin()+ selected-1);
                goto l1;
            }

            else if(game.player.card_list[selected-1] % 25 == 22 || game.player.card_list[selected-1] % 25 == 23)
            {
                string str =  to_string(game.player.card_list[selected-1]);
                game.player.card_list.erase(game.player.card_list.begin()+ selected-1);
                strcpy(buf, str.c_str());
                socket->write(buf);
                socket->flush();
                socket->waitForBytesWritten(30000);
                goto l1;
            }
            else if (game.player.card_list[selected-1] <= 104 && game.player.card_list[selected-1] >= 101)
            {
                char c;
                 cout << "Please enter a color (r for red, y is for yellow, g is for green, b is for blue) " << endl;
                 cin >> c;
                 string str =  to_string(game.player.card_list[selected-1]);

                 switch (c)
                 {
                     case 'r' :  str += " r";
                                     break;
                     case 'y' :  str += " y";
                                 break;
                     case 'g' :  str += " g";
                                 break;
                     case 'b' :  str += " b";
                 }


                 game.player.card_list.erase(game.player.card_list.begin()+ selected-1);
                 strcpy(buf, str.c_str());
                 socket->write(buf);
                 socket->flush();
                 socket->waitForBytesWritten(30000);
            }
            else
            {
                string str =  to_string(game.player.card_list[selected-1]);
                game.player.card_list.erase(game.player.card_list.begin()+ selected-1);
                strcpy(buf, str.c_str());
                socket->write(buf);
                socket->flush();
                socket->waitForBytesWritten(30000);
            }
        }

        else if(strcmp(token, "2") == 0)
        {
            while (token != NULL)
            {
               int num = stoi(token);
               game.player.card_list.push_back(num);
               token = strtok(NULL, " ");
            }
        }
        else
        {
            while (token != NULL)
            {
               int num = stoi(token);
               game.player.card_list.push_back(num);
               token = strtok(NULL, " ");
            }
        }
        /*string top = convertToString(buf);
        game.top_card = stoi(top);*/



        break;
    }


    socket->close();
    qDebug("\nCompleted");

}
