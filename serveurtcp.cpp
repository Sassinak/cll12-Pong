#include "serveurtcp.h"
#include "threadjoueurs.h"

ServeurTCP::ServeurTCP(QObject *parent)
{
    CJoueurs =0;
}

void ServeurTCP::incomingConnection(int socketDescriptor)
{
    while (CJoueurs <=1)
    {   //  2 joueurs max
        thJoueurs = new ThreadJoueurs(socketDescriptor,CJoueurs);
        connect(thJoueurs,SIGNAL(siInfosFmServeur(int*)),this,SLOT(slRXInfosfmArbitre(int*)));
        connect(thJoueurs,SIGNAL(siInfosToServeur(int*)),this,SLOT(slRXInfosfmthJoueurs(int*)));

        //tabJoueurs[CJoueurs]=thJoueurs;
        CJoueurs +=1;
        thJoueurs->start();
    }
}
void slRXInfosfmthJoueurs(int*){}
void slRXInfosfmArbitre(int*){}

