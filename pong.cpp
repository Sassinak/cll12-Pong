#include "pong.h"
#include "ui_pong.h"

#define UNITE 10
#define WIDTH 820
#define HEIGHT 300

pong::pong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pong)
{
    ui->setupUi(this);
    //int tInfos (1,2,3,4,5,6,7,8);
    int tInfos [8]={WIDTH/2,HEIGHT/2,UNITE*3,HEIGHT/2,WIDTH-UNITE *40,HEIGHT/2,0,0};//pos depart : nouvelle balle
    pInfos=tInfos;

    //sInfos= new structInfos();
    //creation des objets
   /* this->J1 = new QGraphicsRectItem (0,0,UNITE,UNITE *4);
    this->J2 = new QGraphicsRectItem (0,0,UNITE,UNITE *4);
    this ->Balle = new QGraphicsEllipseItem (0,0,UNITE,UNITE);
    this->dx = -1;
    this->dy = -1;
    this->Table->setSceneRect(0,0,300,600);
    //Table->add

    //pos départ
    this->J1->setPos(sInfos->posJ1X,sInfos->posJ1Y);
    this->J2->setPos(sInfos->posJ2X,sInfos->posJ2Y);
    this->Balle->setPos(sInfos->posBalleX,sInfos->posBalleY);

    murGauche = 1;
    murDroite = 600;    //un peu bidon, ideal window.width -10
    */
}

pong::~pong()
{
    delete ui;
}
void pong::gestionBalleetPointage(int* tinfos)
//void pong::gestionBalleetPointage(structInfos sinfos)
{

    //if balle score( depasse xmaxA ou xmaxB)
    int cote=0;
   /* if(sinfos.posBalleX < murGauche)
    {
        cote = 2;
        sinfos.scoreB =+1;
        if(sinfos.scoreB == 15)
            emit siGagnant(cote); // ?
    }
    if(sinfos.posBalleX > murDroite)
    {
        cote =1;
        sinfos.scoreA =+1;
        if(sinfos.scoreA == 15)
            emit siGagnant(cote);
    }*/

    //if collision palette
    //rebondir balle
    //emit pos balle
    Balle->moveBy(dx,dy);
// if(Balle->collidesWithItem((J1)))
    //si(sinfos.posBalleY==sinfos.posJ1Y)

}

void pong::on_btnStart_clicked()
{
    serveur = new ServeurTCP();
    //connect(this,SIGNAL(siNouvelleBalle(int,int,int,int)),serveur,SLOT(slNouvelleBalle(int,int,int,int)));

}
