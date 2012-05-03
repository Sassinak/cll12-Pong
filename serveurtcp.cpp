#include "serveurtcp.h"

ServeurTCP::ServeurTCP(QObject *parent) :
    QTcpServer(parent)
{
}

void ServeurTCP::incomingConnection(int socketDescriptor)
{
    thJoueurs = new ThreadJoueurs(socketDescriptor);
    //connect(this, SIGNAL(siBallePosToJoueurs(int,int)),thJoueurs)
}
