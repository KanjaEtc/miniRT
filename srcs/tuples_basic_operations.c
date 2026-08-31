#include "../include/header.h"

// proteger contre DOUBLE_MAX

t_tuple	*ft_tuples_addition(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*result;

	if (!t1 || !t2 || (ft_is_a_point(t1) && ft_is_a_point(t2)))
		return (NULL);
	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = t1->x + t2->x;
	result->y = t1->y + t2->y;
	result->z = t1->z + t2->z;
	result->w = t1->w + t2->w;
	return (result);
}

t_tuple	*ft_tuples_subtraction(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*result;

	if (!t1 || !t2 || (ft_is_a_vector(t1) && ft_is_a_point(t2)))
		return (NULL);
	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = t1->x - t2->x;
	result->y = t1->y - t2->y;
	result->z = t1->z - t2->z;
	result->w = t1->w - t2->w;
	return (result);
}

t_tuple	*ft_tuple_opposite(t_tuple *t)
{
	t_tuple	*opposite;

	if (!t || !ft_is_a_vector(t))
		return (NULL);
	opposite = malloc(sizeof(t_tuple));
	if (!opposite)
		return (NULL);
	opposite->x = -t->x;
	opposite->y = -t->y;
	opposite->z = -t->z;
	opposite->w = 0;
	return (opposite);
}


t_tuple	*ft_vector_by_scalar_multiplication(t_tuple *vector, double scalar)
{
	// t_tuple	*result;

	if (!vector || ft_is_a_point(vector))
		return (NULL);
	// result = malloc(sizeof(t_tuple));
	// if (!result)
	// 	return (NULL);
	// result->x = vector->x * scalar;
	// result->y = vector->y * scalar;
	// result->z = vector->z * scalar;
	// result->w = 1;
	return (ft_point_creator(vector->x * scalar, vector->y * scalar, vector->z * scalar));
}

t_tuple	*ft_vector_by_scalar_division(t_tuple *vector, double scalar)
{
	t_tuple	*result;

	if (!vector || ft_is_a_point(vector) || scalar == 0)
		return (NULL);
	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = vector->x / scalar;
	result->y = vector->y / scalar;
	result->z = vector->z / scalar;
	result->w = 1;
	return (result);
}

// int main()
// {
// 	t_tuple *v = ft_vector_creator(0, -8, 0.5);
// 	double scalar = -2;
// 	t_tuple *expected = ft_point_creator(v->x * scalar, v->y * scalar, v->z * scalar);
// 	t_tuple *result = ft_vector_by_scalar_multiplication(v, scalar);
// 	printf("expected : x = %f\ny = %f\nz = %f\nw = %f\n", expected->x, expected->y, expected->z, expected->w);
// 	printf("actual : x = %f\ny = %f\nz = %f\nw = %f\n", result->x, result->y, result->z, result->w);
// 	printf("%d\n", ft_points_equality(result, expected));
// }