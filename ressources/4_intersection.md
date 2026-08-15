**INTERSECTION**

On cherche a determiner si un rayon a un point d'intersection avec un objet et, si oui, les coordonnees de ce point.


1) Plan

Soit un point P dans l'espace. P fait partie d'un plan si :

					N.(P - Q) = 0
Ou :
- N est le vecteur normal du plan (donne dans la map)
- Q est un point dans le plan (donne dans la map)

Pour trouver le point d'intersection P(t) :

					t = (Q - O).N / D.N
Ou :
- Q est un point appartenant au plan (donne dans la map)
- O = coordonnees de l'origine du rayon
- n = vecteur normal du plan (donne dans la map)
- D = vecteur directeur du rayon

A noter : si D.N donne un tout petit nombre (ex : 1e-6) alors le rayon est parallele au plan. L'equation a alors 0 (si (Q - O).N =/= 0) ou une infinite (si (Q - O).N = 0) de solutions.


2) Sphere

Un point P(x,y,z) appartient a une sphere de centre C(x₀,y₀,z₀) si :

					(x - x₀)² + (y - y₀)² + (z - z₀)² = R²
Ou :
- R est le rayon de la sphere (le diametre est donne dans la map)

Pour trouver le point d'intersection t :

Un rayon peut etre represente sous la forme :

					P(t) = O + tD
Ou :
- O = origine du rayon
- D = direction du rayon (vecteur normalise)
- t = variable qui definit une position (point) precise le long du rayon

Chaque point d'une sphere peut etre represente sous la forme :

					|P - C|² - R² = 0
Ou :
- P = un point(x,y,z) de la sphere
- C = centre de la sphere
- R = rayon de la sphere

Il existe un point le long du rayon qui appartient aussi a la sphere. Des lors on peut remplacer P dans l'equation de la sphere par O + tD, ou t est l'inconnue :

					|O + tD - C|² - R² = 0

Apres le developpement de l'identite remarquable :

					t²D² + 2tD.(O - C) + |O - C|² - R² = 0

C'est une equation de type ax² + bx + c = 0 (equation du second degre), ou :
- a = D²
- b = 2D.(O - C)
- c = |O - C|² - R²

Si D (vecteur directeur de l'origine du rayon) est bien normalise, alors par definition :

					D² = 1

Pour resoudre cette equation du second degre on calcule le discriminant Δ :

					Δ = b² - 4ac

Si Δ > 0 alors l'equation a deux solutions (et il existe deux points d'intersection potentiels) :

					(-b + √Δ) / 2a
					(-b - √Δ) / 2a

Si Δ = 0 alors l'equation a une solution (et il existe un point d'intersection potentiel) :

					(-b) / 2a

Si Δ < 0 alors l'equation n'admet pas de solution (et il n'y a pas de point d'intersection)

La solution t peut etre :
- positive : le rayon a un ou deux points d'intersection avec la sphere
- negative : la sphere est derriere l'origine du rayon : on peut considerer qu'il n'y a pas d'intersection
- une positive, une negative : l'origine du rayon est a l'interieur de la sphere

3) Cylindre

On doit calcule la position du ou des points d'intersection du rayon avec la surface du cylindre (a.) et avec les disques des extremites (b.).

a. Surface du cylindre

Soient :
- Q un point sur l'axe du cylindre (donne dans la map)
- A le vecteur normalise de l'axe (donne dans la map)
- R le rayon du cylindre (deduisible du diametre donne dans la map)
- O l'origine du rayon
- D sa direction

Et sachant que :
- P(t) = O + tD

On doit avoir :
On verifie que h se trouve 
					|(P(t) - Q) - ((P(t) - Q).A)A| = R

On eleve au carre :
[(P(t) - Q) - ((P(t) - Q).A)A]² = R²

On retranche R² :
[(P(t) - Q) - ((P(t) - Q).A)A]² - R² = 0

On remplace P(t) par O + tD :
[(O + tD - Q) - ((O + tD - Q).A)A]² - R² = 0

On developpe les identites remarquables :
t²(D.D) + 2t[(O - Q).D - ((O - Q).A)(D.A)] + |(O - Q)|² - ((O - Q).A)² - R² = 0

On obtient donc l'equation du second degre ax² + bx + c = 0 ou :
- a = D.D - (D.A)²
- b = 2[(O - Q).D - ((O - Q).A)(D.A)]
- c = (O - Q).(O - Q) - ((O - Q).A)² - R²

On la resoud comme expliqu) Sphe dans 2) Sphere.

S'il existe au moins une solution t, on verifie qu'elle est bien la range definie par la hauteur du cylindre. Si elle est est positive alors il y a intersection.

P(t) = O + tD
Soient :
- C le centre du cylindre (donne dans la map)
- H sa hauteur (donnee dans la map)
- h la coordonnee du point P(t) le long de l'axe A

					h = (P - C).A
Ou :
- P = O + tD, on teste le ou les t obtenus au-dessus

Si -H/2 <= h <= H/2 alors le t teste est bien un point d'intersection entre le rayon et le cylindre.


b. Disques du cylindre

On commence par verifier que le point P(t) appartient au plan du premier disque. On verifie ensuite qu'il se trouve a une distance du centre du disque inferieure ou egale au rayon R du cylindre. Puis on recommence avec le second disque.

Soit C₁ le centre du premier disque :

					C₁ = C - (H / 2)A
Ou :
- le vecteur A est multiplie coordonnee a coordonnee par H/2

L'axe A du cylindre est egalement la normale du plan du disque C₁. Pour que P(t) appartienne a ce plan il faut donc que :

					(P(t) - C₁).A = 0

On remplace P(t) :
(O + tD - C₁).A = 0

Qui s'ecrit aussi :
(O - C₁).A + t(D.A) = 0

On isole t :
t = - (O - C₁).A / D.A

Et si t >= 0 alors il y a intersection.

On retrouve P (avec P = O + tD)

(Si D.A = 0 alors le rayon est parallele au disque. Si (O - C₁).A = 0 alors le rayon est dans le plan du disque : s'il est aussi dans le disque, alors il y a une infinite de solutions, Sinon, il n'y a pas de point d'intersection. Verifier ca avant de chercher t pour eviter de diviser par 0);

Le point P(t) appartient au plan du disque. Il appartient au disque lui-meme si, et seulement si :

					|P - C₁| <= R

Si oui, P(t) est un point d'intresection du rayon et du premier disque du cylindre.

Pour le second disque C₂ :

					C₂ = C + (H/2)A

Et continue on continue comme avec le premier disque.
