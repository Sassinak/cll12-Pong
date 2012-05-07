#ifndef THREADJOUEURS_H
#define THREADJOUEURS_H

#include <QThread>
#include <QTcpSocket>

class ThreadJoueurs : public QThread
{
    Q_OBJECT
public:
    explicit ThreadJoueurs(int socketDescriptor);
    void run();

signals:
    void siInfosToServeur(QByteArray);
    void siInfosFmServeur(QByteArray);

public slots:
    void slTXInfosToJoueurs(QByteArray baTXInfos);
    void slRXInfosFmJoueurs(QByteArray);

private:
    int m_socketDescriptor;

    QByteArray baRXInfos;     //trame de reception Infos - RX
    QByteArray baTXInfos;     //trame de transmission

    QByteArray batrame;
};

#endif // THREADJOUEURS_H
