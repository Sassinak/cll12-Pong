#include "pong.h"
#include "ui_pong.h"
#include <QtGui>

#define UNITE 10
#define WIDTH 820
#define HEIGHT 300

pong::pong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pong)
{
    ui->setupUi(this);
    //int tInfos {1,2,3,4,5,6,7,8};
    int startInfos [9]={'%',WIDTH/2,HEIGHT/2,UNITE*3,HEIGHT/2,WIDTH-UNITE *40,HEIGHT/2,0,0};//pos depart : nouvelle balle
    memcpy(m_tInfos,startInfos,9);
    bstart = false;

    //creation des objets
    this->J1 = new QGraphicsRectItem (0,0,UNITE,UNITE *4);
    this->J2 = new QGraphicsRectItem (0,0,UNITE,UNITE *4);
    this ->Balle = new QGraphicsEllipseItem (0,0,UNITE,UNITE);
    this->dx = -1;
    this->dy = -1;
    //this->Table->setSceneRect(0,0,300,600);
    //Table->add

    //pos départ
    this->Balle->setPos(startInfos[2],startInfos[3]);
    this->J1->setPos(startInfos[4],startInfos[5]);
    this->J2->setPos(startInfos[6],startInfos[7]);

    murGauche = 1;
    murDroite = 600;    //un peu bidon, ideal window.width -10
}

pong::~pong()
{
    delete ui;
}

void pong::on_btnStart_clicked()
{
    if(!bstart){
            serveur = new ServeurTCP();
            connect(this, SIGNAL(siTxInfostoClients(QByteArray)),serveur, SLOT(slRXInfosfmArbitre(QByteArray)));
            connect(serveur,SIGNAL(siTXInfostoArbitre(QByteArray)), this, SLOT(slRxInfos(QByteArray)));
            if(!serveur->listen(QHostAddress::Any, 60123))
                QMessageBox::information(this,"Erreur","Erreur de connection");
            ui->btnStart->setText("Arret");
        }
     if(bstart){
            serveur->close();
            ui->btnStart->setText("Demarrer");
        }
        bstart= !bstart;
}
 // Trame recue des clients
void pong::slRxInfos(QByteArray baRXInfos)
{
    //decode rx byte array [3]
    QString stemp(baRXInfos);
    QStringList sltemp = stemp.split('.');
    int ttemp[sltemp.size()];

    for (int i=0;i<sltemp.size()-1;i++)
        ttemp[i]=sltemp.at(i).toInt();

    // recoit la pos de la palette de chaque joueur
    if(ttemp[1]<100)    //si x a gauche: joueur 1
    {
        J1->setPos(ttemp[1],ttemp[2]);   //mise à jour pos joueur
        m_tInfos[4]=ttemp[2];        // et tableau d'infos.
    }
    else
    {
        J2->setPos(ttemp[1],ttemp[2]);
        m_tInfos[6]=ttemp[2];
    }
    //Au Jeu!
    gestionBalleetPointage(m_tInfos);
}

void pong::gestionBalleetPointage(int* pinfos)
{
    int tempinfos[9];
    memcpy(tempinfos,pinfos,9);

    Balle->moveBy(dx*10*0.005,dy*10*0.005);

    //collisions
    // limites terrain
    if(Balle->y()>HEIGHT-10 || Balle->y()<= 0)
        dy = -dy;
    //avec palettes joueurs
    if(Balle->collidesWithItem(J1)|| Balle->collidesWithItem(J2))
        dx =-dx;

    //if balle score( depasse xmaxA ou xmaxB)
    if(Balle->x() < murGauche)
    {
        tempinfos[8] =+1;      //score B joueur 2
        if(tempinfos[8] == 15)
            tempinfos[0]= int('$'); //code Winner!
    }
    if(Balle->x() > murDroite)
    {
        tempinfos[9] =+1;      //score A joueur 1
        if(tempinfos[9] == 15)
             tempinfos[0]= int('$');
    }

    //prep pour tx
    tempinfos[1]= Balle->x();
    tempinfos[2]= Balle->y();
    tempinfos[3]= J1->x();
    tempinfos[4]= J1->y();
    tempinfos[5]= J2->x();
    tempinfos[6]= J2->y();

    memcpy(m_tInfos,tempinfos,sizeof(tempinfos));

    //conversion immediate en qbytearray pour tx
    baTX = TXInfosToJoueurs(m_tInfos,sizeof(m_tInfos));

    emit(siTxInfostoClients(baTX,9));
}
QByteArray pong::TXInfosToJoueurs(int *pInfos,int n)
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


