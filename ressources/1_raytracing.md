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
- le vecteur d'orientation normalise(*1*) : c'est la direction dans laquelle regarde 
	la camera. S'il est de (0,0,1) alors la camera regarde dans la profondeur (donc 
	le long de l'axe z).Ca a l'air plus complique...

Objet :
- les coordonnees de leur centre (sphere, cylindre)
- les coordonnees d'un point qui en fait partie (plan)
- les eventuels diametres et hauteur
- le vecteur normalise(1) (plan)

Source lumineuse :
N/A



**Le principe**

L'idee est de partir de la camera. Il faut imaginer des rayons qui partent d'elles et qui couvrent tous les points du plan de son champ de vision. Chaque pixel de l'image finale represente ce que "voit" un rayon.

Pour un rayon donne, on regarde s'il percute un objet. Si ce n'est le cas, c'est un pixel qui represente du vide.

Si le rayon trouve un objet sur sa trajectoire, alors la couleur du pixel qui represente ce point d'intersection sera determinee en fonction de la position de la source de lumiere. Si le point d'intersection est illumine, il sera en couleur (donc distinct du background).
