#ifndef SERVEURTCP_H
#define SERVEURTCP_H

#include <QTcpServer>

class ServeurTCP : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServeurTCP(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // SERVEURTCP_H
