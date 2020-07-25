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

void server :: penalty()
{
    cout << "You have not pressed 'Uno' before putting the card. You get two more cards." << endl;

    for(unsigned i = 0; i < 2; i++)
    {
        int val = game.draw();
        game.player.card_list.push_back(val);
    }
}
void server :: newConnection()
{
    bool win = true;
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
            try {
                cin>>selected;

                int val;
                if(selected == 0)
                   val = 0;
                else
                    val = game.player.card_list[selected-1];
                if(game.verify(val))
                {
                    break;
                }
                else
                {
                    throw selected;
                }
            } catch (...) {
                cout << "Please enter a valid input: ";
            }
        }
        if (game.player.card_list.size() == 2 && game.verifyAll() && selected != 0)
        {
            char uno[5];
            cin >> uno;
            if(strcmp("Uno", uno) != 0)
            {
                penalty();
                string str = "1 ";
                str +=  to_string(game.top_card);
                strcpy(buf, str.c_str());
                socket->write(buf);
                socket->flush();
                socket->waitForBytesWritten(30000);
                goto l1;
            }
        }
        if (game.player.card_list.size() == 0)
        {
            string str = "1 win";
            strcpy(buf, str.c_str());
            socket->write(buf);
            socket->flush();
            socket->waitForBytesWritten(30000);
            break;
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

           if(val % 25 >= 19 && val % 25 <= 24)
           {
               string str =  card_list[game.player.card_list[selected]-1]->play(game, val);
               strcpy(buf, str.c_str());
               socket->write(buf);
               socket->flush();
               socket->waitForBytesWritten(30000);
               continue;
           }
           else if (val >= 101 && val <= 104)
           {

               char c;
                cout << "Please enter a color (r for red, y is for yellow, g is for green, b is for blue) " << endl;
                cin >> c;
                switch (c)
                {
                    case 'r' :  game.top_card = -1;
                                    break;
                    case 'y' :  game.top_card = -2;
                                break;
                    case 'g' :  game.top_card = -3;
                                break;
                    case 'b' :  game.top_card = -4;
                }
                 string str =  card_list[game.player.card_list[selected]-1]->play(game, val);
                 strcpy(buf, str.c_str());
                 socket->write(buf);
                 socket->flush();
                 socket->waitForBytesWritten(30000);

           }
           else if(val >= 104 && val <= 108)
           {
               char c;
                cout << "Please enter a color (r for red, y is for yellow, g is for green, b is for blue) " << endl;
                cin >> c;
                switch (c)
                {
                    case 'r' :  game.top_card = -1;
                                    break;
                    case 'y' :  game.top_card = -2;
                                break;
                    case 'g' :  game.top_card = -3;
                                break;
                    case 'b' :  game.top_card = -4;
                }
                 string str =  card_list[game.player.card_list[selected]-1]->play(game, val);
                 strcpy(buf, str.c_str());
                 socket->write(buf);
                 socket->flush();
                 socket->waitForBytesWritten(30000);
                 continue;
           }
           else
           {
               string str =  card_list[game.player.card_list[selected]-1]->play(game, val);
               strcpy(buf, str.c_str());
               socket->write(buf);
               socket->flush();
               socket->waitForBytesWritten(30000);
           }
        }

        cout << "\nBefore Reading " << endl;
        l1:socket->waitForReadyRead(-1);
        socket->read(buf, sizeof(buf));
        cout << "\nAfter Reading " << endl;

        if(strcmp(buf, "win") == 0)
        {
            win = false;
            break;
        }
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
            socket->waitForReadyRead(-1);
            socket->read(buf, sizeof(buf));
            game.top_card = atoi(buf);
        }
        else if(strcmp(buf, "penalty") == 0)
        {
            string c = "2 ";
            int a = game.draw();
            c.append(to_string(a));
            c.append(" ");
            a = game.draw();
            c.append(to_string(a));
            strcpy(buf, c.c_str());
            socket->write(buf);
            socket->flush();
            socket->waitForBytesWritten(30000);

        }
        else
        {
            char *token = strtok(buf, " ");
            int sent_by_client = stoi(convertToString(token));
            if(sent_by_client % 25 >= 19 && sent_by_client % 25 <= 24)
            {
                card_list[sent_by_client - 1]->play(game, sent_by_client, 'c');
                goto l1;
            }
            if(sent_by_client >= 101 && sent_by_client <= 104)
            {
                token = strtok(buf, " ");
                card_list[sent_by_client - 1]->play(game, sent_by_client, *token);
            }
            if(sent_by_client >= 104 && sent_by_client <= 108)
            {
                token = strtok(buf, " ");
                card_list[sent_by_client - 1]->play(game, sent_by_client, *token);
                goto l1;
            }
            else
            {
                card_list[sent_by_client - 1]->play(game, sent_by_client, 'c');
            }

        }
        //server's turn again
    }

    if(win)
    {
        cout << "Congratulations you Won!!!" << endl;
    }
    else
    {
        cout << "Sorry, You lost. Better luck next time" << endl;
    }

    socket->close();
}
