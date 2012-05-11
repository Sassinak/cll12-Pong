#include "pong.h"
#include "ui_pong.h"

pong::pong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pong)
{
    ui->setupUi(this);
    sInfos = new structInfos(12,145,10,150,400,150,0,0);
    murGauche = 1;
    murDroite = 600;    //un peu bidon, ideal window.width
}

pong::~pong()
{
    delete ui;
}

void pong::gestionBalleetPointage(structInfos sinfos)
{
    //if collision palette
        //rebondir balle
        //emit pos balle
    //if balle score( depasse xmaxA ou xmaxB)
    if(sinfos.posBalleX < murGauche)
    {
        sinfos.scoreA =+1;
        if(sinfos.scoreA == 15)
            emit siGagnant(1);
    }
    if(sinfos.posBalleX > murDroite)
    {
        sinfos.scoreB =+1;
        if(sinfos.scoreB == 15)
            emit siGagnant(2);
    }

        //emit siNouvelleBalle(xA, ymax/2,scoreA,ScoreB);
}

void pong::on_btnStart_clicked()
{
    serveur = new ServeurTCP();
    connect(this,SIGNAL(siNouvelleBalle(int,int,int,int)),serveur,SLOT(slNouvelleBalle(int,int,int,int)));

}
