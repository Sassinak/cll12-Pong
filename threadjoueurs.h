#ifndef THREADJOUEURS_H
#define THREADJOUEURS_H
#include "structInfos.h"
#include <QThread>
#include <QTcpSocket>

class ThreadJoueurs : public QThread
{
    Q_OBJECT
public:
    explicit ThreadJoueurs(int socketDescriptor, int noJ,structInfos *pinfos);
    void run();
    void RXInfosFmJoueurs(QByteArray &baRXInfos);

signals:
    void siInfosToServeur(*structInfos);
    void siInfosFmServeur(*structInfos);

public slots:
    void slTXInfosToJoueurs(*structInfos sTXInfos);

private:
    int m_socketDescriptor;
    char *JoueurNo;
    QByteArray *baRXInfos;     //trame de reception Infos - RX
    QByteArray *baTXInfos;     //trame de transmission
    structInfos * m_pInfo;
};

#endif // THREADJOUEURS_H
