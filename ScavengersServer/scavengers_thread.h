#ifndef SCAVENGERS_THREAD_H
#define SCAVENGERS_THREAD_H

#include <QThread>
#include <QtNetwork/QTcpSocket>

class ScavengersThread : public QThread
{
    Q_OBJECT

public:
    ScavengersThread(int socket_descriptor, QObject *parent);
    void run() override;

signals:
    void error(QTcpSocket::SocketError socket_error);

private:
    int socket_descriptor_;
    QString text_;
};

#endif // SCAVENGERS_THREAD_H
