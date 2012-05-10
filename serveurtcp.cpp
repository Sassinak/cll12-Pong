#include "serveurtcp.h"

ServeurTCP::ServeurTCP(QObject *parent) :
    QTcpServer(parent)
{
    CJoueurs =0;
}

void ServeurTCP::incomingConnection(int socketDescriptor)
{
    while (CJoueurs <=1)
    {   //  2 joueurs max
        thJoueurs = new ThreadJoueurs(socketDescriptor,CJoueurs);
        tabJoueurs[CJoueurs]=thJoueurs;
        CJoueurs +=1;
    }
}
