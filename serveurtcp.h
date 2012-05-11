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
    void siTXInfostoArbitre(structInfos);
    void siTXInfostothJoueurs(structInfos);
    
public slots:
    void incomingConnection(int);
    void slRXInfosfmthJoueurs(structInfos);
    void slRXInfosfmArbitre(structInfos);

public:
    ThreadJoueurs *thJoueurs;
    ThreadJoueurs tabJoueurs[2];
    int CJoueurs;
};

#endif // SERVEURTCP_H
