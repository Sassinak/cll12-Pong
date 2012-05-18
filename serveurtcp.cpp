#include "serveurtcp.h"
#include "threadjoueurs.h"

ServeurTCP::ServeurTCP() //QObject *parent)
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
        connect(thJoueurs,SIGNAL(siInfosToServeur(QByteArray)),this,SLOT(slRXInfosfmArbitre(QByteArray)));
        connect(this,SIGNAL(siTXInfostothJoueurs(QByteArray)),thJoueurs,SLOT(slInfosFmServeur(QByteArray)));

        thJoueurs->start();
    }
}
void ServeurTCP::slRXInfosfmthJoueurs(QByteArray barx)
{
    emit(siTXInfostoArbitre(barx));
}
void ServeurTCP::slRXInfosfmArbitre(QByteArray batx)
{
    emit(siTXInfostothJoueurs(batx));
}

