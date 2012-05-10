//serveur arbitre

contient classes
    threadjoueurs
    serveurtcp
    pong

pong:
  X  - un gui simple avec bouton demarrer
        fenetre observation?
  X  - part le tcpserveur
    - rx infos: balle et pals des joueurs
    - gere la balle (x, y)
        -debut de partie
       - gere les collisions avec le mur
       - avec les palettes
    - gere les points
        - affiche les points
        - declare le gagnant
    - tx infos: balle, pal1,pal2, scoreA, scoreB

serveurtcp:
 X   - attend 2 connections
 x  - part les threadsjoueurs
    - tx/rx les infos: balle, pal1,pal2, scoreA, scoreB

threadjoueurs:
    - communique entre le serveur et les joueurs
    - tx/rx les infos: balle, pal1,pal2, scoreA, scoreB
            - avec le serveur+GUI pour collisions
            - avec les joueurs

ref sur net: http://code.google.com/p/movement-game/source/browse/trunk/test/gametest/pong.cpp?r=52
            + .hpp
