#ifndef PONG_H
#define PONG_H
#include "serveurtcp.h"
#include "threadjoueurs.h"
#include "structInfos.h"
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
    void on_btnStart_clicked();
    //void gestionBalleetPointage(&structInfos);
    void NouvelleBalle();

signals:
    //void siTxInfostoClients(&structInfos);
    void siGagnant(int);
    void siTimeout(int);                         //un probleme

public slots:
    //void slRxInfos(&structInfos);
    
private slots:


private:
    Ui::pong *ui;
    int scoreA,scoreB;
    ServeurTCP *serveur;
    structInfos sInfos;
    structInfos *pInfos;
    int murGauche;
    int murDroite;
};

#endif // PONG_H
