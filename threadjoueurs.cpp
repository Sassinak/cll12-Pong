#include "threadjoueurs.h"
#include <QStringList>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor,int nJ)
{
    m_socketDescriptor = socketDescriptor;
    if (nJ==1)
        *JoueurNo = "1";

    if(nJ == 2)
       *JoueurNo = "2";
}

void ThreadJoueurs::run()
{
    QByteArray baInit;
    QTcpSocket unSocket;

    unSocket.setSocketDescriptor(m_socketDescriptor);
    if(unSocket.waitForConnected(1000))
    {
        while(unSocket.waitForReadyRead())
        {
            baInit=unSocket.read(unSocket.bytesAvailable());
            if(baInit == "#")
                unSocket.write(JoueurNo);
            unSocket.write(baTXInfos);
        }
    }
    unSocket.disconnectFromHost();
    unSocket.close();

}
void ThreadJoueurs::slRXInfosFmJoueurs(QByteArray baRXInfos)
{
   /* int balleX,balley;
    QString stemp;
    QString sRX=baRXInfos;
    QStringList qsltemp= sRX.split('.');
    balleX= qsltemp.at(0).toInt();
    balley=qsltemp.at(1).toInt();*/
    emit siInfosToServeur(baRXInfos);


}
void ThreadJoueurs::slTXInfosToJoueurs(QByteArray baTXInfos)
{
    //construction par boutte. ici exemple
    QString trame="325.200.10.150.420.10.10.12";
    QString trame = sInfos.posBalleX;
    batrame.append(trame);
}

