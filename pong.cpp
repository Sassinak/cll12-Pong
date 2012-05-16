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
    //int tInfos (1,2,3,4,5,6,7,8);
    int startInfos [9]={'%',WIDTH/2,HEIGHT/2,UNITE*3,HEIGHT/2,WIDTH-UNITE *40,HEIGHT/2,0,0};//pos depart : nouvelle balle
    pInfos=startInfos;
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
    this->J1->setPos(pInfos[4],pInfos[5]);
    this->J2->setPos(pInfos[6],pInfos[7]);
    this->Balle->setPos(pInfos[2],pInfos[3]);

    murGauche = 1;
    murDroite = 600;    //un peu bidon, ideal window.width -10

}

pong::~pong()
{
    delete ui;
}
void pong::gestionBalleetPointage(int* pinfos)
{
    Balle->moveBy(dx*10*0.005,dy*10*0.005);

    //collisions
    // limite terrain
    if(Balle->y()>HEIGHT-10 || Balle->y()<= 0)
        dy = -dy;
    //avec palettes joueurs
    if(Balle->collidesWithItem(J1)|| Balle->collidesWithItem(J2))
        dx =-dx;

    //if balle score( depasse xmaxA ou xmaxB)
    if(Balle->x() < murGauche)
    {
        pinfos[8] =+1;      //score B joueur 2
        if(pinfos[8] == 15)
            pinfos[0]= int('$');
    }
    if(Balle->x() > murDroite)
    {
        pinfos[9] =+1;      //score A joueur 1
        if(pinfos[9] == 15)
             pinfos[0]= int('$');
    }
    pinfos[1]= Balle->x();
    pinfos[2]= Balle->y();
    pinfos[3]= J1->x();        //prep pour tx
    pinfos[4]= J1->y();
    pinfos[5]= J2->x();
    pinfos[6]= J2->y();

    emit(siTxInfostoClients(pinfos));
}

void pong::slRxInfos(int * p)
{
    code = p[0];
    Balle->setPos(p[1],p[2]);
    J1->setPos(p[3],p[4]);
    J2->setPos(p[5],p[6]);
    scoreA = p[7];
    scoreB = p[8];

    gestionBalleetPointage(p);
}

void pong::on_btnStart_clicked()
{
    if(!bstart){
            serveur = new ServeurTCP();
            connect(this, SIGNAL(siTxInfostoClients(int*)),serveur, SLOT(slRXInfosfmArbitre(int*)));
            connect(serveur,SIGNAL(siTXInfostoArbitre(int*)), this, SLOT(slRxInfos(int*)));
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
