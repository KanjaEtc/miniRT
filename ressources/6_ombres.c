Pour chaque pixel on regarde s'il peut atteindre la source de lumiere sans
rencontrer d'intersection. S'il en recontre, alors le pixel fait partie d'une ombre. 
S'il n'en rencontre pas, soit il est lui-meme une intersection, et alors on calcule 
sa couleur comme decrit dans couleur_et_lumiere.md ; soit il n'en est pas et alors 
il represente du vide eclaire par la lumiere ambiante.
