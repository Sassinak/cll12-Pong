#include "serveurtcp.h"

ServeurTCP::ServeurTCP(QObject *parent) :
    QTcpServer(parent)
{
}

void ServeurTCP::incomingConnection(int socketDescriptor)
{
    //thJoueurs = new ThreadJoueurs(socketDescriptor);
    //connect(this, SIGNAL(siBallePosToJoueurs(int,int,int,int)),thJoueurs,SLOT(slRXBallePos(int,int,int,int)));
    //connect(this,SIGNAL(siPalPosToJoueur(int,int)),thJoueurs,SLOT(slRXPalPos(int,int)));
    //connect(this,SIGNAL(siPalPosfromJoueur(int,int)),w,SLOT()
}
