#include "structInfos.h"

QByteArray * structInfos::encode(structInfos *pinfos)
{
    //du serveur vers client
    QByteArray *baTx;
    QDataStream dsInfos(baTx,QIODevice::WriteOnly);
    dsInfos <<pinfos->posBalleX;
    dsInfos <<posBalleY;
    dsInfos <<posJ1X;
    dsInfos <<posJ1Y;
    dsInfos <<posJ2X;
    dsInfos <<posJ2Y;
    return baTx;
}

structInfos* structInfos::decode(QByteArray &baRx)
{
    //utilisé par le client
    structInfos sInfos;
    QDataStream dsInfos(baRx,QIODevice::ReadOnly);
    dsInfos>>posBalleX;
    dsInfos>>posBalleY;
    dsInfos>>posJ1X;
    dsInfos>>posJ1Y;
    dsInfos>>posJ2X;
    dsInfos>>posJ2Y;
    return sInfos;
}
void structInfos::extraitposJnX(QByteArray posJoueur,structInfos *pinfos)
{
    //extrait x,y assigne au bon joueur dans la structInfos
    int x,y;
    x = (int)posJoueur[0];
    y = (int)posJoueur[1];
    if(x==pinfos->posJ1X)
        pinfos->posJ1Y = posJoueur[1];
    if(y == pinfos->posJ2X)
        pinfos->posJ2Y ==posJoueur[1];
}


