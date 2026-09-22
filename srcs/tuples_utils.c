#include "../include/header.h"

int	ft_is_a_normalized_vector(t_tuple *vector)
{
	return (vector && ft_is_a_vector(vector)
		&& vector->x >= -1 && vector->x <= 1
		&& vector->y >= -1 && vector->y <= 1
		&& vector->z >= -1 && vector->z <= 1);
}
