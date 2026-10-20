#include "../include/header.h"
#include <criterion/criterion.h>

Test(light, reflection)
{
	t_tuple *vector = ft_vector_creator(1, -1, 0);
	t_tuple *normal = ft_vector_creator(0, 1, 0);
	t_tuple	*correct = ft_vector_creator(1, 1, 0);
	
	t_tuple	*incorrect = ft_vector_creator(-1, 1, 0);

	t_tuple *vector2 = ft_vector_creator(0, -1, 0);
	t_tuple *normal2 = ft_vector_creator(sqrt(2) / 2, sqrt(2) / 2, 0);
	t_tuple	*correct2 = ft_vector_creator(1, 0, 0);
	
	t_tuple	*point = ft_point_creator(1, 1, 0);

	cr_assert(ft_vectors_equality(ft_reflect(vector, normal), correct));
	cr_assert(!ft_vectors_equality(ft_reflect(vector, normal), incorrect));
	
	cr_assert(ft_vectors_equality(ft_reflect(vector2, normal2), correct2));
	cr_assert(!ft_vectors_equality(ft_reflect(vector2, normal2), incorrect));
	
	cr_assert_null(ft_reflect(NULL, normal));
	cr_assert_null(ft_reflect(vector, NULL));
	cr_assert_null(ft_reflect(NULL, NULL));
	cr_assert_null(ft_reflect(point, normal));
}
