#include "scavengers_thread.h"

#include <QByteArray>
#include <QDataStream>

ScavengersThread::ScavengersThread(int socket_descriptor, QObject *parent)
    : QThread(parent), socket_descriptor_(socket_descriptor)
{

}

void ScavengersThread::run() {
    QTcpSocket tcp_socket;

    if(!tcp_socket.setSocketDescriptor(socket_descriptor_)) {
        emit error(tcp_socket.error());
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << "Testing string";

    tcp_socket.write(block);
    tcp_socket.disconnectFromHost();
    tcp_socket.waitForDisconnected();
}
