#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class client: public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);

signals:

public slots:
    void readyRead();

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
