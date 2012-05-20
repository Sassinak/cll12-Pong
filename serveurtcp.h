#ifndef SERVEURTCP_H
#define SERVEURTCP_H
#include <QTcpServer>
#include <threadjoueurs.h>

class ServeurTCP : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServeurTCP();//QObject *parent = 0);
    ~ServeurTCP();
signals:
    void siTXInfostoArbitre(QByteArray);
    void siTXInfostothJoueurs(QByteArray);
    
public slots:
    void incomingConnection(int);
    void slRXInfosfmthJoueurs(QByteArray barx);
    void slRXInfosfmArbitre(QByteArray batx);

public:
    ThreadJoueurs *thJoueurs;
    char CJoueurs;
    int m_tinfos[9];
};

#endif // SERVEURTCP_H
