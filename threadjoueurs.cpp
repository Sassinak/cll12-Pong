#include "threadjoueurs.h"
#include <QString>
#include <QStringList>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor,char noJ)
{
    m_socketDescriptor = socketDescriptor;

    cNoJ = noJ;                             //recuperation nojoueur
    int NouvellePartie[9] = {'&',50,HEIGHT/2,UNITE*4,(HEIGHT/2)-20,WIDTH-UNITE *4,(HEIGHT/2)-20,0,0};//pos depart : nouvelle balle
    memcpy(m_tNouvellePartie,NouvellePartie,sizeof(NouvellePartie));     //et initialisation des joueurs
}

void ThreadJoueurs::run()
{
    QTcpSocket unSocket;


    unSocket.setSocketDescriptor(m_socketDescriptor);
    if(unSocket.waitForConnected(1000))
    {
        while(unSocket.ConnectedState)         //.waitForReadyRead(1000))
        {
            baRXInfos=unSocket.read(unSocket.bytesAvailable());
            if(baRXInfos.left(1) == "&")    //code de connection des joueurs
            {
                unSocket.write(baTXInfos.append(cNoJ));     //assignation du numero
                baTXInfos = TXInfosToJoueurs(m_tNouvellePartie,9);  // trame de debut de partie (= NouvellePartie)
            }
            else
            {
                RXInfosFmJoueurs(baRXInfos);                //recoit {'#', JnX, JnY}
                baTXInfos = TXInfosToJoueurs(m_txInfos,9);  //repond trame {code, balle X, balle Y, J1X, J1Y, J2X, J2Y, ScoreA, ScoreB}
            }                                               // code = '#' (normale), '$' (gagnant), '%' (Nouvelle Balle)
            unSocket.write(baTXInfos);
            unSocket.waitForBytesWritten(10);
        }
    }
    unSocket.disconnectFromHost();
    unSocket.close();

}
void ThreadJoueurs::RXInfosFmJoueurs(QByteArray baRXInfos)
{
    //decode rx byte array
    QString stemp(baRXInfos);
    QStringList sltemp = stemp.split('.');
    int ttemp[3];

    for (int i=0;i<sltemp.size()-1;i++)
        ttemp[i]=sltemp.at(i).toInt();

    memcpy(m_rxInfos,ttemp,sizeof(ttemp));

    emit siInfosToServeur(m_rxInfos,3);
}
QByteArray ThreadJoueurs::TXInfosToJoueurs(int *pTXInfos,int n)
{
    //encode pour tx
    QByteArray batxinfos;
    QString stemp="";
    stemp.append((QString::number(pTXInfos[0])));
    for (int i=1;i<n;i++)
    {
        stemp.append('.');
        stemp.append((QString::number(pTXInfos[i])));
    }
    batxinfos.clear();
    batxinfos.append(stemp);
    return batxinfos;
}
void ThreadJoueurs::slInfosFmServeur(int * p, int n)
{
    memcpy(m_txInfos,p,sizeof(p));
    baTXInfos = TXInfosToJoueurs(p,n);
}

