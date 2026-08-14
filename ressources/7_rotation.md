**ROTATION**

Une matrice de rotation permet de faire tourner une camera autour de la scene ou de la faire tourner sur elle-meme. 
Ci-dessous la methode pour la faire tourner sur elle-meme, de preference autour de l'axe vertical.

L'axe vertical (ou horizontal ou de la profondeur) ici ne se refere pas necessairement a l'axe vertical y du plan. Il s'agit de l'axe vertical dans le referentiel de la camera. Pour le trouver, voir 3_representer_plan_en_pixels.md, 2) a., calcul du vecteur up.

Pour appliquer une rotation donnee on multiplie les vecteurs ayant pour origine la camera (c'est-a-dire les rayons de la camera) par une matrice de rotation.

L'angle depend de l'utilisateur : rotation d'un quart de cercle = angle de 90 degres, un demi tour = 180 degres, etc. L'idee pour etre de determiner un petit angle (ex : 20 degres) et d'appliquer la rotation correspondante chaque fois que l'utilisateur utilise une touche du clavier.

Soit A l'angle de rotation :

Rotation autour de l'axe horizontal :
| 1 0      0       |
| 0 cos(A) -sin(A) |
| 0 sin(A) cos(A)  |

Rotation autour de l'axe de la profondeur :
| cos(A) -sin(A) 0 |
| sin(A) cos(A)  0 |
| 0      0       1 |

Rotation autour de l'axe vertical :
| cos(A)  0  -sin(A) |
| 0       1  0       |
| sin(A) 0  cos(A)   |

On s'interesse a la rotation autour de l'axe vertical :

Soit le vecteur (x,y,z). Si on applique la rotation verticale d'angle A a ce vecteur, on obtient sa nouvelle valeur comme suit :

			new_x = cos(A) * x + -sin(A) * z
			
			new_y = y
			
			new_z = sin(A) * x + cos(A) * z

Pour chaque rotation on recalcule chaque rayon de la camera en le multipliant par la matrice pour reafficher la scene apres rotation de la camera. 
