**COULEUR D'UN PIXEL**

- La luminosite ambiante eclaire indifferemment tous les endroits et objets.
- La luminosite diffuse provient de la lampe. Elle eclaire les endroits que ses rayons lumineux atteignent et projete des ombres. Une surface face a la lumiere sera plus eclairee qu'une surface de bais.
- La lumunosite speculaire (spot brightness) cree un disque de lumiere sur l'objet la ou la lampe l'eclaire le plus.

La couleur d'un pixel qui represente un objet depend de la lumiere ambiante, de la lumiere diffuse, de la lumiere speculaire et de la couleur de l'objet.

Chacune des formules permettant de calculer les trois types de luminosite donnent 
comme resultat un vecteur(x,y,z) qu'on transforme en couleur(x,y,z) ou x, y et z 
representent respectivement les R, G, et B d'une couleur.

1) Luminosite ambiante

Couleur_ambiante_pixel = 

					Couleur de l'objet * Couleur de la lumiere ambiante * Intensite 
						de la lumiere ambiante


2) Luminosite diffuse

Couleur_diffuse_pixel =
			
			Couleur de l'objet * Couleur de la lumiere * Intensite de la lumiere

Ou la lumiere designe la source de lumiere (et non la lumiere ambiante).

La couleur de l'objet est donnee par la map. La lumiere est toujours blanche. L'intensite de la lumiere, elle, depend de la position des rayons lumineux par rapport a chaque point.

Pour calculer l'intensite en un point P on a besoin de :
a. vecteur normal du rayon lumineux en P
b. le vecteur normal de la surface de l'objet en P


a. Vecteur normal du rayon lumineux en P : 
											normal_lumiere = normalize(lumiere - P)
	

b. Calcul du vecteur normal de la suface d'un objet un point P :
- plan : normal_plan = vecteur perpendiculaire au plan ((1,0,0) ou (0,1,0) ou (0,0,1))
- sphere : normal_sphere = (P - C) / rayon (ou C = centre de la sphere)
- cylindre (extremite) : axe (extremite du haut) ou -axe (extemite du bas)
- cylindre (cote) : 
					projection = centre + axe.((P - centre) . axe)
					normal_cylindre = normalize(P - projection)

On peut alors calculer l'intensite lumineuse I :

					I = max(0, N.L) * light_brightness

Ou :
- max = une fonction qui revoie le plus grand de ses arguments
- N = normal_surface (cad normal_plan, normal_sphere ou normal_cylindre)
- L = normal_lumiere
- light_brightness est donne dans la map


3) Luminosite speculaire

couleur_speculaire = 
						indice_speculaire * intensite_speculaire * couleur_lampe

Ou :
- l'indice est une valeur choisie entre 0 et 1 : plus elle s'approche 
	de 1, plus le disque sera petit et lumineux
- l'intensite speculaire determine le niveau de luminosite percu par la camera, selon l'indice 
	et sa position par rapport a l'objet

L'intensite speculaire se calcule comme suit :

			intensite_speculaire = pow(max(normal_camera . vecteur_reflexion, 0), 32)
	
Ou :
- pow est une fonction qui eleve son premier argument a la puissance [second argument]
- normal_camera est le vecteur normal de la camera en un point P
- vecteur_reflexion caracterise la reflexion d'un rayon de lumiere en un point P

normal_camera = 
					normalize(position_camera - position_P)

vecteur_reflexion =
					-normal_lumiere - 2(-normal_lumiere . normal_surface) * normal_surface
					

Ou :
- -normal_lumiere va de la lampe vers l'objet (contrairement a normal_lumiere)
- normal_surface a ete calcule en 2)



4) Couleur finale du pixel

Une fois prises en compte les 3 types de luminosite la couleur finale s'obtient par :

couleur_finale_du_pixel = 
		
		couleur_ambiante + couleur_diffuse + couleur_speculaire


