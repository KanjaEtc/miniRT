#include "../include/header.h"

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_vectors_equality(t_tuple *v1, t_tuple *v2)
{
	double	epsilon;

	if (!v1 || !v2 || ft_is_a_point(v1) || ft_is_a_point(v2))
		return (0);
	epsilon = 10e-5;
	return (ft_abs(v1->x - v2->x) <= epsilon
			&& ft_abs(v1->y - v2->y) <= epsilon
			&& ft_abs(v1->z - v2->z) <= epsilon);
}

int	ft_points_equality(t_tuple *v1, t_tuple *v2)
{
	double	epsilon;

	if (!v1 || !v2 || ft_is_a_vector(v1) || ft_is_a_vector(v2))
		return (0);
	epsilon = 10e-5;
	return (ft_abs(v1->x - v2->x) <= epsilon
			&& ft_abs(v1->y - v2->y) <= epsilon
			&& ft_abs(v1->z - v2->z) <= epsilon);
}
