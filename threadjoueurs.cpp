#include "threadjoueurs.h"
#include <QStringList>

ThreadJoueurs::ThreadJoueurs(int socketDescriptor)
{
    m_socketDescriptor = socketDescriptor;
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
                unSocket.write("ok");
            unSocket.write(baTXInfos);
        }
    }
    unSocket.disconnectFromHost();
    unSocket.close();

}
void ThreadJoueurs::slRXInfosFmJoueurs(QByteArray baRXInfos)
{
    int balleX,balley;
    QString stemp;
    QString sRX=baRXInfos;
    QStringList qsltemp= sRX.split('.');
    balleX= qsltemp.at(0).toInt();

}
void ThreadJoueurs::slTXInfosToJoueurs(QByteArray baTXInfos)
{

    QString trame="325.200.10.150.420.10.10.12";
    batrame.append(trame);
}

