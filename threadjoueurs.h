#ifndef THREADJOUEURS_H
#define THREADJOUEURS_H
#include <QThread>
#include <QTcpSocket>

class ThreadJoueurs : public QThread
{
    Q_OBJECT
public:
    explicit ThreadJoueurs(int socketDescriptor, char noJ);
    void run();
    bool bRun;
    int m_txInfos[9];  //tableau sortant

    void RXInfosFmJoueurs(QByteArray baRXInfos);
    QByteArray TXInfosToJoueurs(int *pTXInfos,int n);

signals:
    void siInfosToServeur(QByteArray);

public slots:
    void slInfosFmServeur(QByteArray);

private:
    int m_socketDescriptor;
    int* m_tinfos;          //pointeur de tableau
    int m_InfosStart[9];   //tableau de depart
    char cNoJ;
    QByteArray baRXInfos;     //trame de reception Infos - RX
    QByteArray baTXInfos;     //trame de transmission
    //QString sTX;
    //QByteArray baNojoueur;

};

#endif // THREADJOUEURS_H
