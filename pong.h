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
    void gestionBalleetPointage(int* pinfos);
    void NouvelleBalle(int*);

    int *pInfos;        // pointe sur tableau int* qui contient toutes les donnees

signals:
    void siTxInfostoClients(int * p);
    void siGagnant(int);
    void siTimeout(int);                         //un probleme

public slots:
    void slRxInfos(int* p);
    
private slots:


private:
    Ui::pong *ui;
    int scoreA,scoreB, code;
    ServeurTCP *serveur;

    QGraphicsScene *Table;
    QGraphicsRectItem *J1,*J2;
    QGraphicsEllipseItem * Balle;
    int dx, dy;
    int murGauche;
    int murDroite;
};

#endif // PONG_H
