//serveur arbitre

contient classes
    threadjoueurs
    serveurtcp
    pong
    int tInfos [] : contient NO Joueur + toutes les coordonnees

    - pos balle (x,y)
    - pos joueur1 (x,y)
    - pos joueur2 (x+400, y)
    - scoreA
    - scoreB

pong:
  X  - un gui simple avec bouton demarrer
        fenetre observation?
  X  - part le tcpserveur avec tableau de thJoueurs[2]
    - RX infos = int[n]
    - gere la balle (x, y)
        -debut de partie
       - gere les collisions avec le mur
       - avec les palettes
       - depasse murs du fond
    - gere les points
        - affiche les points
        - declare le gagnant
    - TX infos:structInfos

serveurtcp:
 X  - attend 2 connections
 x  - part les threadsjoueurs
        - en assignant noJoueur
    - tx/rx baInfos > arbitre(gui) ou /thjoueurs >> clients

threadjoueurs:
    - communique entre le serveur et les clients/joueurs par tcp/ip
    - tx/rx les infos: int[] <--> qbytearray
            - avec le serveur >--> GUI pour collisions
            - avec les joueurs <--rx (Jn(x,y)

refs sur net: http://code.google.com/p/movement-game/source/browse/trunk/test/gametest/pong.cpp?r=52
            + .hpp
            - http://lists.trolltech.com/qt-interest/2004-11/thread00856-0.html
