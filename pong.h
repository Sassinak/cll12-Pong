#ifndef PONG_H
#define PONG_H
#include "serveurtcp.h"
#include "threadjoueurs.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimeLine>
#define UNITE 10
#define WIDTH 820
#define HEIGHT 300

namespace Ui {
class pong;
}

class pong : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit pong(QWidget *parent = 0);
    ~pong();

    void gestionBalleetPointage(int* pinfos);
    void NouvelleBalle(int*);

    int m_tInfos[9];       // pointe sur tableau int* qui contient toutes les donnees

signals:
    void siTxInfostoClients(int * p,int);
    void siGagnant(int);
    void siTimeout(int);                         //un probleme

public slots:
    void slRxInfos(int* p);
    
private slots:
    void on_btnStart_clicked();

private:
    Ui::pong *ui;
    bool bstart;
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
