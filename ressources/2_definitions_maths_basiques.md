**DEFINITIONS ET CALCULS DE BASE**


**Produit scalaire** : multiplication d'un vecteur A avec un vecteur B

Dans un plan en 3 dimensions x, y et z :

		A * B = Ax * Bx + Ay * By + Cx * Cy



**Vecteur normal** : vecteur perpendiculaire a une droite, une surface ou un plan

*Vecteur normal d'un plan* : vecteur perpendiculaire au
plan en un point P

*Vecteur normal d'une sphere* : vecteur qui passe par le centre de la sphere et un point P de la surface de la sphere

*Vecteur normal d'un cylindre* :

	disque du cylindre : vecteur parallele a l'axe (haut du cylindre) ou parallele a -axe (bas)

	cote du cylindre : vecteur perpendiculaire a l'axe du cylindre en un point P
		


Pour calculer la normale d'un vecteur v(x,y,z), on commence par trouver la longueur L du vecteur v :

					L = racine(x² + y² + z²)

Ensuite :
			x_normal = x / L
			y_normal = y / L
			z_normal = z / L

Alors on obtient : normal(x_normal, y_normal, z_normal)

