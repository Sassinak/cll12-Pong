#ifndef STRUCTINFOS_H
#define STRUCTINFOS_H
#include <QString>
#include <QDataStream>

class structInfos
{
public:
    int posBalleX;
    int posBalleY;
    int posJ1X;
    int posJ1Y;
    int posJ2X;
    int posJ2Y;
    int scoreA;
    int scoreB;
public:
    QByteArray* encode(structInfos *pinfos); //for tx to client
    structInfos*decode(QByteArray &baRx);//for RX BY CLIENT
    void extraitposJnX(QByteArray, structInfos *pinfo); // extrait palX
};


#endif // STRUCTINFOS_H
