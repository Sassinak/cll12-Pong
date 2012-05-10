#ifndef THREADJOUEURS_H
#define THREADJOUEURS_H
#include "structInfos.h"
#include <QThread>
#include <QTcpSocket>

class ThreadJoueurs : public QThread
{
    Q_OBJECT
public:
    explicit ThreadJoueurs(int socketDescriptor, int nJ);
    void run();

signals:
    void siInfosToServeur(QByteArray);
    void siInfosFmServeur(QByteArray);

public slots:
    void slTXInfosToJoueurs(QByteArray baTXInfos);
    void slRXInfosFmJoueurs(QByteArray);

private:
    int m_socketDescriptor;
    char *JoueurNo;
    QByteArray baRXInfos;     //trame de reception Infos - RX
    QByteArray baTXInfos;     //trame de transmission

    QByteArray batrame;
    structInfos sInfos;         //structure de coordonees
};

#endif // THREADJOUEURS_H
