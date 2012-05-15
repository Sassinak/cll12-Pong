#ifndef SERVEURTCP_H
#define SERVEURTCP_H
#include <QTcpServer>
#include <threadjoueurs.h>

class ServeurTCP : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServeurTCP(QObject *parent = 0);
    
signals:
    void siTXInfostoArbitre(int*);
    void siTXInfostothJoueurs(int*);
    
public slots:
    void incomingConnection(int);
 //   void slRXInfosfmthJoueurs(int*);
  //  void slRXInfosfmArbitre(int*);

public:
    ThreadJoueurs *thJoueurs;
    int CJoueurs;
};

#endif // SERVEURTCP_H
