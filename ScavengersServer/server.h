#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socket_descriptor) override;

private:
};

#endif // SERVER_H
