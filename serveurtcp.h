#ifndef SERVEURTCP_H
#define SERVEURTCP_H
#include <QTcpServer>
#include <threadjoueurs.h>

class ServeurTCP : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServeurTCP(QObject *parent = 0);
    
signals:
    void siTXInfostoArbitre(QByteArray);
    void siTXInfostothJoueurs(QByteArray);
    
public slots:
    void incomingConnection(int);
    void slRXInfosfmthJoueurs(QByteArray);
    void slRXInfosrmArbitre(QByteArray);

public:
    ThreadJoueurs *thJoueurs;
    ThreadJoueurs tabJoueurs[2];
    int CJoueurs;
};

#endif // SERVEURTCP_H
