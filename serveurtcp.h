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
    void siPalPosfromJoueur(int,int);
    void siPalPosToJoueur(int,int);
    void siBallePosToJoueurs(int,int);
    
public slots:
    void incomingConnection(int);
    void slNouvelleBalle(int,int,int,int);
    void slPalPosfromJoueur(int,int);
    void slPalPosToJoueur(int,int);
    void slBallePosToJoueurs(int, int);

public:
    ThreadJoueurs *thJoueurs;

};

#endif // SERVEURTCP_H
