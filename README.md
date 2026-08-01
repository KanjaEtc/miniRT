**RAYTRACING**


**Les elements de depart**

Le but est de representer un objet en trois dimensions. Pour ca on a besoin 
de trois elements :
- le point de vue : c'est l'endroit depuis lequel on regarde. Dans miniRT c'est la 
	camera
- un objet : dans miniRT ce sont des plams, des spheres et des cylindres
- la source de lumiere : c'est la d'ou provient la lumiere qui eclaire les objets

Ces trois elements sont situes dans un plan en trois dimensions, ou la position 
horizontale est donnee par x, la position verticale par y, la position dans la 
profondeux par z. La camera se situe en (x,y,z), idem pour le centre des objets et pour la source de lumiere.

En plus de leurs coordonnees, ces trois elements ont les caracteristiques suivantes (donnees en argument a miniRT) :

Camera :
- FOV : c'est un angle exprime en degres, qui determine le champ de vision de 
	la camera. Plus le FOV est petit (ex : 20 degres), plus l'image parait zoomee. 
	C'est du au fait que, la camera ne voyant qu'une petite partie du plan, chaque 
	pixel de l'image finale ne represente qu'une petite partie de ce plan. Un meme 
	objet necessite donc plus de pixels pour etre represente et il apparait donc 
	plus gros.
- le vecteur d'orientation normalise(*1*) : c'est la direction dans laquelle regarde la 
	camera. S'il est de (0,0,1) alors la camera regarde dans la profondeur (donc 
	le long de l'axe z).

Objet :
- les coordonnees de leur centre (sphere, cylindre)
- les coordonnees d'un point qui en fait partie (plan)
- les eventuels diametres et hauteur
- le vecteur normalise(1) (plan)

Source lumineuse :
N/A


(*1*) Vecteur normalise = axe perpendiculaire a un plan 2D. Exemples :
- vecteur normalise (0,0,1) : l'axe z de la profondeur est perpendicalire au plan :
	le plan et donc defini selon les axes x et y (il est "de face")
- vecteur normalise (0, 1, 0) : l'axe y de la hauteur est perpendiculaire au plan : 
	le plan est donc defini selon les axes x et z (il est "a plat")
- ...



**Le principe**

L'idee est de partir de la camera. Il faut imaginer des rayons qui partent d'elles 
et qui couvrent tous les points du plan de son champ de vision. Chaque pixel de l'image finale represente ce que "voit" un rayon.

Pour un rayon donne, on regarde s'il percute un objet. Si ce n'est le cas, le pixel qui correspond a ce rayon sera de la couleur du background. C'est un pixel qui represente du vide.

Si le rayon trouve un objet sur sa trajectoire, alors la couleur du pixel qui represente ce point d'intersection sera determinee en fonction de la position de la source de lumiere. Si le point d'intersection est illumine, il sera en couleur (donc 
distinct du background).



**Les grandes etapes**

1. Calculer la taille en unites de l'ecran

L'ecran est la portion du plan 3D que la camera voit, etant donne son FOV. C'est ce 
qu'on doit voir sur le PC quand on lance miniRT. Cet ecran occupe toujours la totalite de la fenetre. Plus il est petit, plus l'image parait zoomee. C'est ce qui apparaitra sur notre fenetre, il est donc par definition en deux dimensions.

Contrairement a la taille de la fenetre qui est fixe et s'exprime en pixels, la taille 
de l'ecran depend du FOV et est exprimee en unites. Une meme fenetre peux representer 
des ecrans de tailles differentes.

Calculer la taille de l'ecran revient a determiner quelle partie du plan 3D sera 
visible dans le rendu final.


2. Convertir chaque pixel en point du plan 3D

Ca revient a determiner ce que representera chaque pixel : un point du background ou 
un point d'un objet.


3. Determiner la couleur de chaque pixel

Les pixels representant un partie d'un objet ont une couleur qui depend de s'ils sont 
eclaires par la source de lumiere et des caracteristiques de cette derniere (couleur, 
intensite).

...




**Les maths**


*I - Calculer la taille en unite de l'ecran :*

A. Hauteur H de l'ecran :
							H = 2 x tan(FOV / 2)

Dans cette formule, FOV est exprime en radians.
Pour convertir les degres en radians :
										FOVradians = FOVdegres x pi / 180

B. Largeur W de l'ecran :
							W = H x ratio

Ou ratio = nombre de pixels dans la largeur de la fenetre / nombre de pixels
	dans la hauteur de l'ecran
	Exemple : si la fenetre fait 800 pixels de large et 600 pixels de haut (800x600)
	alors le ration est de 800 / 600.



*II - Convertir un pixel donne en un point dans le plan de l'espace 3D*

Exemple : dans la fenetre 800x600, le pixel(200,150) correspond 
	au point P du plan 3D P(x,y,z) -> on cherche (x,y,z) a partir de (200,150)

A. Selon l'axe horizontal :
							Xplan = (Xpixel / nb_pixels_largeur - 0.5) x W

Dans notre exemple on a :
- Xpixels = 200 (cf exemple ci-dessus)
- nb_pixels_largeur = 800 (idem)
- W represente la largeur de l'ecran calculee plus haut

B. Selon l'axe vertical :
							Yplan = (0.5 - Ypixel / nb_pixels_hauteur) x H

Dans notre exemple on a :
- Ypixels = 150
- nb_pixels_hauteur = 600
- H represente la hauteur de l'ecran calculee plus haut

Donc : le pixel(200,150) correpond au point(x,y) sur le plan.


...


