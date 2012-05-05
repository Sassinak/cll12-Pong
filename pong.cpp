#include "pong.h"
#include "ui_pong.h"

pong::pong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pong)
{
    ui->setupUi(this);
}

pong::~pong()
{
    delete ui;
}

void pong::gestionBalleetPointage(int x,int y, int scoreA, int scoreB)
{
    //if collision palette
        //rebondir balle
        //emit pos balle
    //if balle score( depasse xmaxA ou xmaxB)
        //score(A ou B) +1
        //emit siNouvelleBalle(xA, ymax/2,scoreA,ScoreB);
}

void pong::on_btnStart_clicked()
{
    serveur = new ServeurTCP();
    connect(this,SIGNAL(siNouvelleBalle(int,int,int,int)),serveur,SLOT(slNouvelleBalle(int,int,int,int)));

}
