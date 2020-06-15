#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);

signals:

public slots:
    void newConnection();

private:
    QTcpServer* ser;
};

#endif //SERVER_H
