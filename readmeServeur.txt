//serveur arbitre

contient classes
    threadjoueurs
    serveurtcp
    pong
    int tInfos [] : contient NO Joueur + toutes les coordonnees
        - code de message (#(35) = norm, $ = gagnant, % = Timeout/nouvelle balle, & = Nouvelle Partie, @ = ?? (64)
        - pos balle (x,y)
        - pos joueur1 (x,y)
        - pos joueur2 (x+400, y)
        - scoreA
         scoreB

pong:
  X  - un gui simple avec bouton demarrer
        fenetre observation?
  X  - RX infos = int[3]    {'#', int Jx, int Jy}
  X  - gere la balle (x, y)
        -debut de partie
       - gere les collisions avec le mur
       - avec les palettes
       - depasse murs du fond/score
            - gere les points
            - declare le gagnant
    - TX infos: int pInfos[9]
serveurtcp:
 X  - attend 2 connections
 x  - part les threadsjoueurs
        - en assignant noJoueur
    - tx/rx int * pInfos > arbitre(gui) ou /thjoueurs >> clients

threadjoueurs:
    - communique entre le serveur et les clients/joueurs par tcp/ip
    - tx/rx les infos: int[] <--> qbytearray
            - avec le serveur >--> GUI pour collisions
            - avec les joueurs <--rx (Jn(x,y)

refs sur net: http://code.google.com/p/movement-game/source/browse/trunk/test/gametest/pong.cpp?r=52
            + .hpp
            - http://lists.trolltech.com/qt-interest/2004-11/thread00856-0.html
