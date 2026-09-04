#include "../include/header.h"

/* =============================== TRANSLATION ============================== */

Test(transformations, point_translation)
{
	t_matrix *translation_matrix = ft_translation(5, -3, 2);
	t_tuple *point = ft_point_creator(-3, 4, 5);
	t_tuple *product = ft_matrix_by_tuple_multiplication(translation_matrix, point);
	t_tuple *expected = ft_point_creator(2, 1, 7);
	
	cr_assert(ft_points_equality(product, expected));

	translation_matrix = ft_translation(0, 0, 0);
	product = ft_matrix_by_tuple_multiplication(translation_matrix, point);

	cr_assert(ft_points_equality(product, point));
}

Test(transformations, vector_translation)
{
	t_matrix *translation_matrix = ft_translation(5, -3, 2);
	t_tuple *vector = ft_vector_creator(-3, 4, 5);
	t_tuple *product = ft_matrix_by_tuple_multiplication(translation_matrix, vector);
	
	cr_assert(ft_vectors_equality(product, vector));

	translation_matrix = ft_translation(0, 0, 0);
	product = ft_matrix_by_tuple_multiplication(translation_matrix, vector);

	cr_assert(ft_vectors_equality(product, vector));
}


/* =============================== SCALING ============================== */

Test(transformations, scaling)
{
	t_matrix *scaling_matrix = ft_scaling(2, 3, 4);
	t_tuple *point = ft_point_creator(-4, 6, 8);
	t_tuple *product = ft_matrix_by_tuple_multiplication(scaling_matrix, point);
	t_tuple *expected = ft_point_creator(-8, 18, 32);
	
	cr_assert(ft_points_equality(product, expected));

	t_tuple *vector = ft_vector_creator(-4, 6, 8);
	t_tuple *product_2 = ft_matrix_by_tuple_multiplication(scaling_matrix, vector);
	t_tuple *expected_2 = ft_vector_creator(-8, 18, 32);
	
	cr_assert(ft_vectors_equality(product_2, expected_2));
}

Test(transformations, inverse_scaling)
{
	t_matrix *scaling_matrix = ft_scaling(2, 3, 4);
	t_matrix *inverse_scaling_matrix = ft_inverse(scaling_matrix);
	t_tuple *vector = ft_vector_creator(-4, 6, 8);
	t_tuple *product = ft_matrix_by_tuple_multiplication(inverse_scaling_matrix, vector);
	t_tuple *expected = ft_vector_creator(-2, 2, 2);
	
	cr_assert(ft_vectors_equality(product, expected));
}

Test(transformations, negative_scaling_aka_reflection)
{
	t_matrix *scaling_matrix = ft_scaling(-1, 1, 1);
	t_tuple *point = ft_point_creator(2, 3, 4);
	t_tuple *product = ft_matrix_by_tuple_multiplication(scaling_matrix, point);
	t_tuple *expected = ft_point_creator(-2, 3, 4);
	
	cr_assert(ft_points_equality(product, expected));
}
