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
                baTXInfos = TXInfosToJoueurs(NouvellePartie,sizeof(NouvellePartie));
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
    emit siInfosToServeur(baRXInfos);
}
QByteArray ThreadJoueurs::TXInfosToJoueurs(int *pInfos,int n)
{
    //encode pour tx
    QByteArray batxinfos;
    QString stemp="";
    stemp.append((QString::number(pInfos[0])));
    for (int i=1;i<n;i++)
    {
        stemp.append('.');
        stemp.append((QString::number(pInfos[i])));
    }
    batxinfos.clear();
    batxinfos.append(stemp);
    return batxinfos;
}

void ThreadJoueurs::slInfosFmServeur(QByteArray p)
{
    baTXInfos = p;
}

