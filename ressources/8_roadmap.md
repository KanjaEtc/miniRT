					/!\ A completer, modifier et ameliorer /!\

**Parsing**

1) Verifier que la map soit valide
2) Stocker les donnees



**Affichage**

On prend le pixel A :

1) On trouve le point P du plan auquel il correspond
2) On en deduit un vecteur_camera qui a pour origine la camera et va vers P
3) On cherche l'intersection la plus proche de la camera entre ce vecteur et un objet
4) On deduit le vecteur_to_light qui a pour origine l'intersection et va vers la lampe
5) On cherche une intersection entre vecteur_to_light et tous les objets de la scene 
	-> s'il n'y a pas d'intersection alors P est eclaire
		6) On en deduit la couleur du pixel
	-> s'il y a au moins une intersection alors P n'est pas eclaire, il prend la 	
		couleur de l'ombre

On recommence pour tous les autres pixels



**Rotation et clavier**

1) Lier des touches du clavier a la rotation
2) Reafficher toute la scene a partir de Affichage 2)
	- etape 2 : le nouveau vecteur_camera est le produit de l'ancien avec la matrice
	- etape 3 : on recommence
	- etape 4 : on garde l'ancien vecteur_to_light
	- etape 5 : on garde les anciennes donnees
	- etape 6 : on la recommence pour les pixels concernes (en ne recalculant que la 
					lumiere speculaire, cf 5_couleur_et_lumiere.md)
