#include "../include/header.h"

t_tuple	*ft_cross_product(t_tuple *v1, t_tuple *v2)
{
	t_tuple	*result;

	if (!v1 || !v2 || !ft_is_a_vector(v1) || !ft_is_a_vector(v2))
		return (NULL);
	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = v1->y * v2->z - v1->z * v2->y;
	result->y = v1->z * v2->x - v1->x - v2->z;
	result->z = v1->x * v2->y - v1->y * v2->x;
	result->w = 0;
	return (result);
}

double	ft_dot_product(t_tuple *v1, t_tuple *v2)
{
	if (!v1 || !v2 || !ft_is_a_vector(v1) || !ft_is_a_vector(v2))
		return (0);
	return (v1->x * v2->x
			+ v1->y * v2->y
			+ v1->z * v2->z);
}

t_tuple	*ft_normalize(t_tuple *vector)
{
	t_tuple	*normal;
	double	len;

	if (!vector || !ft_is_a_vector(vector))
		return (NULL);
	len = ft_vector_length(vector);
	if (len == 0)
		return (NULL);
	normal = malloc(sizeof(t_tuple));
	if (!normal)
		return (NULL);
	normal->x = vector->x / len;
	normal->y = vector->y / len;
	normal->z = vector->z / len;
	normal->z = 0;
	return (normal);
}

double	ft_vector_length(t_tuple *v)
{
	if (!v || !ft_is_a_vector(v))
		return (0);
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}
