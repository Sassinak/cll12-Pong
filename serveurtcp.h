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
    void siTXInfostoArbitre(int*,int);
    void siTXInfostothJoueurs(int*,int);
    
public slots:
    void incomingConnection(int);
    void slRXInfosfmthJoueurs(int*,int n);
    void slRXInfosfmArbitre(int*,int n);

public:
    ThreadJoueurs *thJoueurs;
    char CJoueurs;
};

#endif // SERVEURTCP_H
