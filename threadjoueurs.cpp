#include "threadjoueurs.h"
#include <QString>
#include <QStringList>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor,char noJ)
{
    m_socketDescriptor = socketDescriptor;
    int NouvellePartie[9] = {'&', 50, 150, 40,100,760,100,0,0};

    cNoJ = noJ;

    memcpy(m_txInfos,NouvellePartie,9);
}

void ThreadJoueurs::run()
{
    QTcpSocket unSocket;
    int NouvellePartie[9] = {'&', 50, 150, 40,100,760,100,0,0};

    unSocket.setSocketDescriptor(m_socketDescriptor);
    if(unSocket.waitForConnected(1000))
    {
        while(unSocket.ConnectedState)         //.waitForReadyRead(1000))
        {
            baRXInfos=unSocket.read(unSocket.bytesAvailable());
            if(baRXInfos.left(1) == "&")
            {
                unSocket.write(baTXInfos.append(cNoJ));
                baTXInfos = TXInfosToJoueurs(NouvellePartie,9);
            }
            else
            {
                RXInfosFmJoueurs(baRXInfos);
                baTXInfos = TXInfosToJoueurs(m_txInfos,9);
            }
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

    memcpy(m_rxInfos,ttemp,3);

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
    memcpy(m_txInfos,p,n);
    baTXInfos = TXInfosToJoueurs(p,n);
}

