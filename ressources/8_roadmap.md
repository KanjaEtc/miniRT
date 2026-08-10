					/!\ A completer, modifier et ameliorer /!\

**Parsing**

1) Verifier que la map soit valide
2) Stocker les donnees


**Rotation et clavier**

...


**Affichage**

On prend le pixel A :

1) on trouve le point P du plan auquel il correspond (3_representer_plan_en_pixels.md)
2) on en deduit un vecteur_camera qui a pour origine la camera et va vers P
3) on deduit le vecteur_to_light qui a pour origine P et va vers la lampe
4) on cherche une intersection entre vecteur_to_light et tous les objets de la scene (intersection.md)
	a. s'il n'y a pas d'intersection alors P est eclaire
		5) on calcule si le vecteur_camera a un point d'intersection avec l'un des objets de la scene (intersection.md)
		6) on en deduit la couleur du pixel (couleur_et_lumiere.md)
	b. s'il y a au moins une intersection alors P n'est pas eclaire, il prend la couleur de l'ombre

On recommence pour tous les autres pixels

