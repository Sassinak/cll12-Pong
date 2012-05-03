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
    void siPalPosfromJoueur(int);
    void siPalPosToJoueur(int);
    void siBallePosToJoueurs(int, int);
    
public slots:
    void incomingConnection(int);
    void slPalPosfromJoueur(int);
    void slPalPosToJoueur(int);
    void slBallePosToJoueurs(int, int);

public:
    ThreadJoueurs *thJoueurs;

};

#endif // SERVEURTCP_H
