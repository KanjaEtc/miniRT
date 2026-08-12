**Quel point du plan represente chaque pixel ?**

Les pixels de notre fenetre representent les points du plan dans le champ de 
vision de la camera.


1) Calculer la taille de l'ecran

Ecran = portion du plan dans le champ de vision de la camera. C'est ce qui sera affiche sur la fenetre du PC lors du rendu final.


*Hauteur H de l'ecran* :
							H = 2 x tan(FOV / 2)

Dans cette formule, FOV est exprime en radians.
Pour convertir les degres en radians :
							
					FOVradians = FOVdegres x pi / 180


*Largeur W de l'ecran* :
							W = H x ratio

Ou ratio =
			nombre de pixels dans la largeur de la fenetre / nombre de pixels
					dans la hauteur de l'ecran

Exemple : si la fenetre fait 800 pixels de large et 600 pixels de haut (800x600)
	alors le ratio est de 800 / 600.

L'ecran fait H unites de haut et W unites de large.


2) Passer d'un pixel a un point dans le plan

- version longue (avec explications) (a.)
- version courte (sans explications) (b.)

a. Version longue (avec explications)

Ecran a les caracteristiques suivantes :
- son centre est (0,0)
- coins : (-W/2, -H/2) ; (W/2, -H/2) ; (W/2, H/2) ; (-W/2, H/2)

Imaginons un plan carre de cote 1. Son centre a les coordonnees (0,0). Les coordonnees x,y de chaque point de ce carre varient donc entre [-0.5,0.5]. Essayons de representer chaque pixel dans ce plan.

On commencera par convertir les coordonnees de chaque pixel (comprises ici entre 0 et 800 pour la largeur, et 0 et 600 pour la hauteur) en valeurs entre [0,1]. Ensuite, pour les faire entrer dans le plan carre on les convertira en valeurs entre [-0.5,0.5]. Puis on ajustera ces coordonnees selon la hauteur H de l'ecran et sa largeur W : ca permettra de passer du plan carre a la fenetre qui, elle, ne sera pas forcement carree (ici elle est de 800 sur 600).

Pour un pixel donne, la coordonnee x depend de la largeur de la fenetre (ici entre 0 et 800) et la coordonnee y de sa hauteur (ici entre 0 et 600). On commence par convertir les coordonnees des pixels en coordonnees entre [0,1].

			Coordonnee x = largeur_pixel / largeur_fenetre
Ou :
- x varie entre [0,1]
- largeur_fenetre est le nombre de pixels de largeur de la fenetre (ici 800)
- largeur_pixel est compris entre 0 et largeur_fenetre 

			Coordonnee y = hauteur_pixel / hauteur_fenetre

On convertit ensuite ces coordonnees [0,1] en coordonnees [-0.5,0.5].

			x = x - 0.5

			y = 0.5 - y

Pour que les images ne paraissent pas deformees, on finit par adapter ces coordonnees en fonction de la hauteur H de l'ecran et sa largeur W :

			x = x * W

			y = y * H

Les coordonnees x et y finalement obtenues sont celles du point P si et seulement si la camera regarde dans une direction strictement parallele a un des trois axes x, y et z du plan.

Pour generaliser on commence par definir trois vecteurs, right, up et forward, qui representent les axes horizontal, vertical et de profondeur du point de vue de la camera. 


Forward : c'est la direction dans laquelle regarde la camera :

			forward = normalize(x_camera, y_camera, z_camera)

Right : il est perpendiculaire a forward :

			right = normalize((0,1,0) * forward)
Up :
			up = forward * right

Les coordonnees de P peuvent maintenant etre calculees :

			P = C + forward * 1 + right * x + up * y
Ou :
- C est la position de la camera
- 1 est une valeur definie par convention
- x et y correspondent au x et au y calcules ci-dessus

Il faudra ensuite lancer le rayon de la camera vers ce point :

			rayon = normalize(P - C)

b. Version courte (sans explications)

Etape 1 :

			x = (x_pixel / largeur_fenetre - 0.5) * W

			y = (0.5 - y_pixel / hauteur_fenetre) * H

Ou :
- W et H ont ete calcules dans le 1)
- largeur_fenetre et hauteur_fenetre sont le nombre de pixels que fait la fenetre (ex : 800 de large, 600 de haut)
- x_pixel et y_pixel = coordonnees du pixel dans la fenetre (par ex (700,400))

Etape 2 :

			forward = normalize(x_camera, y_camera, z_camera)

			right = normalize((0,1,0) * forward)

			up = forward * right
Ou :
- _camera sont les coordonnees de la camera

Etape 3 :

		P = C + forward * 1 + right * x + up * y
Ou :
- C designe les coordonnees de la camera
