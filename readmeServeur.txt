//serveur arbitre

Permet à deux joueurs de jouer au ping-pong, en ligne. On démarre le serveur.


contient classes:
    threadjoueurs
    serveurtcp
    pong

Utilise :  les infos passent entre threads/objets par QbyteArray
    int tInfos [9] : contient NO Joueur + toutes les coordonnees
        - code de message (#(35) = norm, $ = gagnant, % = Timeout/nouvelle balle, & = Nouvelle Partie, @ = ?? (64)
        - pos balle (x,y)
        - pos joueur1 (x,y)
        - pos joueur2 (x+400, y)
        - scoreA
        - scoreB

pong:
  X  - un gui simple avec bouton demarrer
        (fenetre observation?)
  X  - RX bainfos --> int[3] {'#', int Jx, int Jy} via SLOT
  X  - gere la balle (x, y)
       - debut de partie
       - gere les collisions avec le mur
       - avec les palettes
       - depasse murs du fond/score
            - gere les points
            - declare le gagnant
  x - TX bainfos: int pInfos[9]--> QbyteArray via SIGNAL

serveurtcp:
 X  - attend 2 connections
 x  - part les threadsjoueurs
 x      - en assignant noJoueur
    - SIGNAUX / SLOTS:
 x      -tx/rx QByteArray baInfos <-> arbitre(gui) <->thjoueurs

threadjoueurs:
 x    - communique entre le serveur et les clients/joueurs par tcp/ip
 x   - tx/rx qbytearray
 x           - tx noJoueur
 x           - avec le serveur <--> GUI pour collisions SIGNAL/SLOT
 x           - avec les joueurs <--> qbA infos(<-tcp-> clients)


refs sur net: http://code.google.com/p/movement-game/source/browse/trunk/test/gametest/pong.cpp?r=52
            + .hpp

