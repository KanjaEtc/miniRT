**COULEUR D'UN PIXEL**

La luminosite ambiante eclaire indifferemment tous les endroits et objets.
La luminosite diffuse provient de la lampe. Elle eclaire les endroits que ses 
	rayons lumineux atteignent et projete des ombres. Une surface face a la lumiere 
	sera plus eclairee qu'une surface de bais.

La couleur d'un pixel depend de la lumiere ambiante, de la lumiere diffuse et 
de la couleur de l'objet le cas echeant.

1) Luminosite ambiante

Couleur du pixel = 

					Couleur de l'objet x Couleur de la lumiere ambiante x Intensite 
						de la lumiere ambiante


2) Luminosite diffuse

La couleur d'un pixel se calcule avec la formule :
Couleur du pixel =
			Couleur de l'objet x Couleur de la lumiere x Intensite de la lumiere

Ou la lumiere designe la source de lumiere (et non la lumiere ambiante).

La couleur de l'objet est donnee par la map. La lumiere est toujours blanche. L'intensite de la lumiere, elle, depend de la position des rayons lumineux par rapport a chaque point.

Pour calculer l'intensite on a besoin de :
a. vecteur normal du rayon lumineux en P
b. le vecteur normal de la surface de l'objet en P


a. Vecteur normal du rayon lumineux en P : 
											normal_lumiere = normalize(lumiere - P)
	

b. Calcul du vecteur normal de la suface d'un objet un point P :
- plan : normal_plan = vecteur perpendiculaire au plan ((1,0,0) ou (0,1,0) ou (0,0,1))
- sphere : normal_sphere = (P - C) / rayon (ou C = centre de la sphere)
- cylindre (extremite) : axe (extremite du haut) ou -axe (extemite du bas)
- cylindre (cote) : 
					projection = centre + axe x ((P - centre) x axe)
					normal_cylindre = normalize(P - projection)

On peut alors calculer l'intensite lumineuse I :

					I = max(0, N x L)

Ou :
- max = une fonction qui revoie le plus grand de ses arguments
- N = normal_surface (cad normal_plan, normal_sphere ou normal_cylindre)
- L = normal_lumiere
