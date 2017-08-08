#include "server.h"

#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>

#include "scavengers_thread.h"

#include <QDebug>

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    listen(QHostAddress("123.123.123.123"), 8765);
}

void Server::incomingConnection(qintptr socket_descriptor) {
    qDebug() << "Incoming connection socket descriptor: " << socket_descriptor;
    ScavengersThread *thread = new ScavengersThread(socket_descriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
