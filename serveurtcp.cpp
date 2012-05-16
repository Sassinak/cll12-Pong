#include "serveurtcp.h"
#include "threadjoueurs.h"

ServeurTCP::ServeurTCP(QObject *parent)
{
    CJoueurs ='0';
}

void ServeurTCP::incomingConnection(int socketDescriptor)
{
    while (CJoueurs <='1')
    {
        //  2 joueurs max
        CJoueurs +=1;
        thJoueurs = new ThreadJoueurs(socketDescriptor,CJoueurs);
        connect(thJoueurs,SIGNAL(siInfosToServeur(int*)),this,SLOT(slRXInfosfmArbitre(int*)));
        connect(this,SIGNAL(siTXInfostothJoueurs(int*)),thJoueurs,SLOT(slInfosFmServeur(int*)));

        thJoueurs->start();
    }
}
void ServeurTCP::slRXInfosfmthJoueurs(int* p)
{
    emit(siTXInfostoArbitre(p));
}
void ServeurTCP::slRXInfosfmArbitre(int*p)
{
    emit(siTXInfostothJoueurs(p));
}

