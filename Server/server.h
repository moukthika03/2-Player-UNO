#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <string>
#include "game.h"
#include "card.h"
#include "player.h"
#include <drawfour.h>
#include <wild.h>
#include <numbered.h>
#include <reverse.h>
#include <drawtwo.h>
#include <skip.h>

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    void set_clinet_cards(std :: string);
    string convertToString(char*);
    void penalty();
signals:

public slots:
    void newConnection();

private:
    QTcpServer* ser;
    char client_cards[1024];
    vector<Card*> card_list;
    Game game;
};

#endif //SERVER_H
