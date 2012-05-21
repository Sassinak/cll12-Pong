#include "threadjoueurs.h"
#include <QString>
#include <QStringList>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor,char noJ)
{
    m_socketDescriptor = socketDescriptor;
    int NouvellePartie[9] = {'&', 50, 150, 40,100,760,100,0,0};

    cNoJ = noJ;

    memcpy(m_InfosStart,NouvellePartie,sizeof(NouvellePartie));
}

void ThreadJoueurs::run()
{
    QTcpSocket unSocket;

    unSocket.setSocketDescriptor(m_socketDescriptor);
    if(unSocket.waitForConnected(100))
    {
        while(unSocket.waitForReadyRead(5000))
        {

            baRXInfos=unSocket.read(unSocket.bytesAvailable());
            //baRXInfos = unSocket.readAll();
            if(baRXInfos.left(1) == "&")        //trame demarrer
            {
                unSocket.write(baTXInfos.append(cNoJ));
                unSocket.waitForBytesWritten(100);
                //attendre entre les deux trames
                baTXInfos = TXInfosToJoueurs(m_InfosStart,9);
                unSocket.write(baTXInfos);
            }
            if(baRXInfos.left(1) == "#")    //trame "normale"
            {
                RXInfosFmJoueurs(baRXInfos);
                baTXInfos = TXInfosToJoueurs(m_txInfos,9);
                unSocket.write(baTXInfos);
            }            
            unSocket.waitForBytesWritten(100);
            baTXInfos.clear();
            baRXInfos.clear();
            //ThreadJoueurs::sleep(50);
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
    stemp.append(pInfos[0]);
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

