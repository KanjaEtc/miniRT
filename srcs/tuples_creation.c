#include "../include/header.h"

int	ft_is_a_vector(t_tuple *tuple)
{
	return (tuple && tuple->w == 0);
}

int	ft_is_a_point(t_tuple *tuple)
{
	return (tuple && tuple->w == 1);
}

int	ft_vector_creator(double x, double y, double z)
{
	t_tuple	*vector;

	vector = malloc(sizeof(t_tuple));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = 0;
	return (vector);
}

int	ft_point_creator(double x, double y, double z)
{
	t_tuple	*point;

	point = malloc(sizeof(t_tuple));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = 1;
	return (point);
}
