#ifndef PONG_H
#define PONG_H
#include "serveurtcp.h"
#include "threadjoueurs.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimeLine>


namespace Ui {
class pong;
}

class pong : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit pong(QWidget *parent = 0);
    ~pong();
    void on_btnStart_clicked();
    void gestionBalleetPointage(int*);
    void NouvelleBalle();

signals:
    //void siTxInfostoClients(&structInfos);
    void siGagnant(int);
    void siTimeout(int);                         //un probleme

public slots:
 //   void slRxInfos(int*);
    
private slots:


private:
    Ui::pong *ui;
    int scoreA,scoreB;
    ServeurTCP *serveur;
    int *pInfos;
    QGraphicsScene *Table;
    QGraphicsRectItem *J1,*J2;
    QGraphicsEllipseItem * Balle;
    int dx, dy;
    int murGauche;
    int murDroite;
};

#endif // PONG_H
