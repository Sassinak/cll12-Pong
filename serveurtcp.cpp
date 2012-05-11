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
        connect(thJoueurs,SIGNAL(siInfosFmServeur(structInfos),this,SLOT(slRXInfosfmArbitre(structInfos))));
        connect(thJoueurs,SIGNAL(siInfosToServeur(structInfos),this,SLOT(slRXInfosfmthJoueurs(structInfos)));

        tabJoueurs[CJoueurs]=thJoueurs;
        CJoueurs +=1;
    }
}
