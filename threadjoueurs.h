#ifndef THREADJOUEURS_H
#define THREADJOUEURS_H
#include <QThread>
#include <QTcpSocket>

class ThreadJoueurs : public QThread
{
    Q_OBJECT
public:
    explicit ThreadJoueurs(int socketDescriptor);
    void run();

signals:
    void siPalPosfromJoueur(int);

public slots:

private:
    int m_socketDescriptor;
    QByteArray baBalle;
    QByteArray baJoueurA;
    QByteArray baJoueurB;
};

#endif // THREADJOUEURS_H
