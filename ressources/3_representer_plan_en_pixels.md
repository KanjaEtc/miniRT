**I - Quel point du plan represente chaque pixel ?**

Les pixels de notre fenetre representent les points du plan dans le champ de 
vision de la camera


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


2) Trouver un point du plan auquel correspond un pixel donne

Exemple : dans une fenetre 800x600, le pixel(a,b) correspond 
	a un point P du plan 3D P(x,y,z) -> on cherche (x,y,z) a partir de (a,b)


D'abord on imagine un point T du plan. Ses coordonnees sont (a,b,z_camera).
(z_camera = la position de la camera selon l'axe z du plan)

Ensuite on suit le rayon qui part de la camera en direciton de T. Si un objet 
se trouve dans la trajectoire de ce rayon, il heurtera un point de la surface de 
cet objet. Ce point P(x,y,z) est celui qui correspond au pixel de depart.

On doit ensuite determiner sa couleur (couleur_et_lumiere.md).
