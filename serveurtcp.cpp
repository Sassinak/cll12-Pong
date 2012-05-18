#include "serveurtcp.h"
#include "threadjoueurs.h"

ServeurTCP::ServeurTCP(QObject *parent)
{
    CJoueurs ='0';
}

void ServeurTCP::incomingConnection(int socketDescriptor)
{
    int NouvellePartie[9] = {'&', 50, 150, 40,100,760,100,0,0};

    memcpy(m_tinfos,NouvellePartie,9);
    while (CJoueurs <='1')
    {
        //  2 joueurs max
        CJoueurs +=1;
        thJoueurs = new ThreadJoueurs(socketDescriptor,CJoueurs);
        connect(thJoueurs,SIGNAL(siInfosToServeur(int*,int)),this,SLOT(slRXInfosfmArbitre(int*,int)));
        connect(this,SIGNAL(siTXInfostothJoueurs(int*,int)),thJoueurs,SLOT(slInfosFmServeur(int*,int)));

        thJoueurs->start();
        emit(siTXInfostothJoueurs(m_tinfos,9));
    }
}
void ServeurTCP::slRXInfosfmthJoueurs(int* p,int n)
{
    emit(siTXInfostoArbitre(p,n));
}
void ServeurTCP::slRXInfosfmArbitre(int*p, int n)
{
    emit(siTXInfostothJoueurs(p,n));
}

