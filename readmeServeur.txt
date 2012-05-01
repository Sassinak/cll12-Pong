//serveur arbitre

contient classes
    threadjoueurs
    serveurtcp
    pong


pong:
    - un gui simple avec bouton demarrer
        fenetre observation?
    - part le tcpserveur
    - gere la balle (x, y, angle)
        -debut de partie
       - gere les collisions avec le mur
       - avec les palettes
    - gere les points
        - affiche les points
        - declare le gagnant

serveurtcp:
    - attend 2 connections
    - part les threadsjoueurs

threadjoueurs:
    - communique entre le serveur et les joueurs
        - re-transmet la position de la balle
        - recoit/transmet la position de la palette de chaque joueur
            - avec le serveur pour collisions
