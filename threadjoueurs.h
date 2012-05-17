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
    int* m_pInfos;  // pointeur d'infos
    void RXInfosFmJoueurs(QByteArray baRXInfos);
    QByteArray TXInfosToJoueurs(int *pTXInfos,int n);

signals:
    void siInfosToServeur(int*,int);

public slots:
    void slInfosFmServeur(int*,int n);

private:
    int m_socketDescriptor;
    int* m_tinfos;
    char cNoJ;
    QByteArray baRXInfos;     //trame de reception Infos - RX
    QByteArray baTXInfos;     //trame de transmission
    QString sTX;
    QByteArray banojoueur;

};

#endif // THREADJOUEURS_H
