#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>

#include "../ScavengersLib/database.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socket_descriptor) override;

private:
    Database db_;
};

#endif // SERVER_H
