#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "game.h"

class client: public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    string convertToString(char*);

signals:

public slots:
    void readyRead();

private:
    QTcpSocket* socket;
    Game game;
};

#endif // CLIENT_H
