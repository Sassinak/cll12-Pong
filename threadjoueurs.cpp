#include "threadjoueurs.h"
#include <QString>
#include <QStringList>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor,char noJ)
{
    m_socketDescriptor = socketDescriptor;

    cNoJ = noJ;
}

void ThreadJoueurs::run()
{
    QTcpSocket unSocket;

    unSocket.setSocketDescriptor(m_socketDescriptor);
    if(unSocket.waitForConnected(1000))
    {
        while(unSocket.waitForReadyRead(1000))
        {
            //baRXInfos = unSocket.readAll();
            baRXInfos=unSocket.read(unSocket.bytesAvailable());
            if(baRXInfos[0] == '&')
                unSocket.write(&cNoJ);
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
    int ttemp[9];
    for (int i=0;i<sltemp.size()-1;i++)
        ttemp[i]=sltemp.at(i).toInt();
    m_pInfos =ttemp;

    emit siInfosToServeur(m_pInfos);
}
QByteArray ThreadJoueurs::TXInfosToJoueurs(int* pTXInfos)
{
    //encode pour tx
    QByteArray batxinfos;

    //// ici exemple

    int TXInfos[9]={35,325,200,10,150,420,10,10};
    pTXInfos = TXInfos;////
    //transfer pour TX
    batxinfos.append((QString)pTXInfos[0]);
    for (int i=1;i<9;i++)
    {
        batxinfos.append('.');
        batxinfos.append(QString::number(pTXInfos[i]));
    }
    return batxinfos;
}
void ThreadJoueurs::slInfosFmServeur(int * p)
{
    baTXInfos = TXInfosToJoueurs(p);
}

