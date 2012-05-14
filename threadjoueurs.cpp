#include "threadjoueurs.h"
#include <QString>
#include <QStringList>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor,int noJ)
{
    m_socketDescriptor = socketDescriptor;
    if (noJ==1)
       *JoueurNo = '1';

    if(noJ == 2)
       *JoueurNo = '2';
    //*******m_pInfo = pinfos;
}

void ThreadJoueurs::run()
{
    QTcpSocket unSocket;

    unSocket.setSocketDescriptor(m_socketDescriptor);
    if(unSocket.waitForConnected(1000))
    {
        while(unSocket.waitForReadyRead())
        {
            baRXInfos = unSocket.readAll();
            //baRXInfos=unSocket.read(unSocket.bytesAvailable());****
            if(baRXInfos[0] == '#')
                unSocket.write(JoueurNo);
            else
            {
                baRXInfos = TXInfosToJoueurs(m_pInfos);
                RXInfosFmJoueurs(baRXInfos);
            }

            unSocket.write(baTXInfos);
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

    for (int i=0;i<sltemp.size();i++)
        m_pInfos[i]=sltemp.at(i).toInt();

    emit siInfosToServeur(m_pInfos);
}
QByteArray ThreadJoueurs::TXInfosToJoueurs(int* pTXInfos)
{
    //encode pour tx
    QByteArray baTXinfos;
    // ici exemple
    int n = 8;
    int tempinfos[8]={1,325,200,10,150,420,10,1012};

    baTXinfos.append(tempinfos[0]);
    for (int i=1;i<n;i++)
    {
        baTXinfos.append('.');
        baTXinfos.append(tempinfos[i]);
        //baTXInfos.append(pTXInfos[i]);
    }
    return baTXinfos;
}

