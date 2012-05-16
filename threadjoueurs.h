#ifndef THREADJOUEURS_H
#define THREADJOUEURS_H
#include <QThread>
#include <QTcpSocket>

class ThreadJoueurs : public QThread
{
    Q_OBJECT
public:
    explicit ThreadJoueurs(int socketDescriptor, int noJ);
    void run();
    void RXInfosFmJoueurs(QByteArray baRXInfos);
    QByteArray TXInfosToJoueurs(int* pTXInfos);

signals:
    void siInfosToServeur(int*);

public slots:


private:
    int m_socketDescriptor;
    char* JoueurNo;
    QByteArray baRXInfos;     //trame de reception Infos - RX
    QByteArray baTXInfos;     //trame de transmission
    int* m_pInfos;
};

#endif // THREADJOUEURS_H
