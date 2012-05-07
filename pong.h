#ifndef PONG_H
#define PONG_H
#include "serveurtcp.h"
#include "threadjoueurs.h"
#include <QMainWindow>

namespace Ui {
class pong;
}

class pong : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit pong(QWidget *parent = 0);
    ~pong();
    void gestionBalleetPointage(int,int,int,int);

signals:
    void siBallePos(int,int,int,int);       //balle et pointage - debut(0,0) et apres un score
    void siPalPos(int,int);
    //void siPalstoServeur(int,int,int,int);      // chaque joueur filtre ses donnees(J2(x+400,y))
    void siTimeout(int);                         //un probleme

public slots:
   void slPalfmJoueur(int,int);                 //comment gerer 2 joueurs?
   //void sl
    
private slots:
    void on_btnStart_clicked();

private:
    Ui::pong *ui;
    int scoreA,scoreB;
    ServeurTCP *serveur;
};

#endif // PONG_H
