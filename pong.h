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

    void gestionBalleetPointage(int* pinfos);
    void NouvelleBalle(int*);

    int m_tInfos[9];       // pointe sur tableau int* qui contient toutes les donnees
    QByteArray baTX;

signals:
    void siTxInfostoClients(QByteArray,int);
    void siTimeout(int);                         //un probleme

public slots:
    //void slRxInfos(int* p);
    void slRxInfos(QByteArray baRXInfos);
    
private slots:
    void on_btnStart_clicked();
    QByteArray TXInfosToJoueurs(int *pInfos,int n);
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
