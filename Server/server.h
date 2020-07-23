#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <string>
#include "game.h"

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    void set_clinet_cards(std :: string);
signals:

public slots:
    void newConnection();

private:
    QTcpServer* ser;
    char client_cards[1024];
    Game game;
};

#endif //SERVER_H
