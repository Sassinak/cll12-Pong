#include "threadjoueurs.h"
#include <QString>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor,int noJ,structInfos * pinfos)
{
    m_socketDescriptor = socketDescriptor;
    if (noJ==1)
        *JoueurNo = "1";

    if(noJ == 2)
       *JoueurNo = "2";
    m_pInfo = pinfos;
}

void ThreadJoueurs::run()
{
    QTcpSocket unSocket;

    unSocket.setSocketDescriptor(m_socketDescriptor);
    if(unSocket.waitForConnected(1000))
    {
        while(unSocket.waitForReadyRead())
        {
            baRXInfos=unSocket.read(unSocket.bytesAvailable());
            if(baRXInfos[0] == "#")
                unSocket.write(JoueurNo);
            else
                RXInfosFmJoueurs(&baRXInfos);

            unSocket.write(baTXInfos);
        }
    }
    unSocket.disconnectFromHost();
    unSocket.close();

}
void ThreadJoueurs::RXInfosFmJoueurs(QByteArray &baRXInfos)
{
    //m_pInfo->
    emit siInfosToServeur(&sInfos);
}
void ThreadJoueurs::slTXInfosToJoueurs(structInfos sTXInfos)
{

    // ici exemple
    structInfos sinfos={1,325,200,10,150,420,10,1012};

    baTXInfos =sinfos.encode(sTXInfos);

}

