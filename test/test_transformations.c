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

// Test(transformations, scaling)
// {
// 	t_tuple *point = ft_point_creator(-4, 6, 8);
// 	t_tuple *rotated_point = ft_scaling(point, 2, 3, 4);
// 	t_tuple *expected_point = ft_point_creator(-8, 18, 32);
	
// 	cr_assert(ft_points_equality(rotated_point, expected_point));


// 	t_tuple *vector = ft_vector_creator(-4, 6, 8);
// 	t_tuple *rotated_vector = ft_scaling(vector, 2, 3, 4);
// 	t_tuple *expected_vector = ft_vector_creator(-8, 18, 32);
	
// 	cr_assert(ft_vectors_equality(rotated_vector, expected_vector));
// }

// Test(transformations, inverse_scaling)
// {
// 	t_tuple *point = ft_point_creator(-4, 6, 8);
// 	t_tuple *rotated_point = ft_scaling(point, 2, 3, 4);
// 	t_tuple *expected_point = ft_point_creator(-8, 18, 32);
	
// 	cr_assert(ft_points_equality(rotated_point, expected_point));


// 	t_tuple *vector = ft_vector_creator(-4, 6, 8);
// 	t_tuple *rotated_vector = ft_scaling(vector, 2, 3, 4);
// 	t_tuple *expected_vector = ft_vector_creator(-8, 18, 32);
	
// 	cr_assert(ft_vectors_equality(rotated_vector, expected_vector));
// }

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


/* =============================== ROTATION ============================== */

Test(transformations, x_rotation)
{
	double pi = 3.1415926535;
	t_tuple *p = ft_point_creator(0, 1, 0);

	t_matrix *quarter = ft_x_axis_rotation(pi / 2);
	t_matrix *half_quarter = ft_x_axis_rotation(pi / 4);

	t_tuple *right_quarter_point = ft_point_creator(0, 0, 1);
	t_tuple *right_half_quarter_point = ft_point_creator(0, sqrt(2) / 2, sqrt(2) / 2);

	t_tuple *tested_quarter_point = ft_matrix_by_tuple_multiplication(quarter, p);
	t_tuple *tested_half_quarter_point = ft_matrix_by_tuple_multiplication(half_quarter, p);

	cr_assert(ft_points_equality(right_quarter_point, tested_quarter_point));
	cr_assert(ft_points_equality(right_half_quarter_point, tested_half_quarter_point));
}

Test(transformations, y_rotation)
{
	double pi = 3.1415926535;
	t_tuple *p = ft_point_creator(0, 0, 1);

	t_matrix *quarter = ft_y_axis_rotation(pi / 2);
	t_matrix *half_quarter = ft_y_axis_rotation(pi / 4);

	t_tuple *right_quarter_point = ft_point_creator(1, 0, 0);
	t_tuple *right_half_quarter_point = ft_point_creator(sqrt(2) / 2, 0, sqrt(2) / 2);

	t_tuple *tested_quarter_point = ft_matrix_by_tuple_multiplication(quarter, p);
	t_tuple *tested_half_quarter_point = ft_matrix_by_tuple_multiplication(half_quarter, p);

	cr_assert(ft_points_equality(right_quarter_point, tested_quarter_point));
	cr_assert(ft_points_equality(right_half_quarter_point, tested_half_quarter_point));
}

Test(transformations, z_rotation)
{
	double pi = 3.1415926535;
	t_tuple *p = ft_point_creator(0, 1, 0);

	t_matrix *quarter = ft_z_axis_rotation(pi / 2);
	t_matrix *half_quarter = ft_z_axis_rotation(pi / 4);

	t_tuple *right_quarter_point = ft_point_creator(-1, 0, 0);
	t_tuple *right_half_quarter_point = ft_point_creator(-(sqrt(2) / 2), sqrt(2) / 2, 0);

	t_tuple *tested_quarter_point = ft_matrix_by_tuple_multiplication(quarter, p);
	t_tuple *tested_half_quarter_point = ft_matrix_by_tuple_multiplication(half_quarter, p);

	cr_assert(ft_points_equality(right_quarter_point, tested_quarter_point));
	cr_assert(ft_points_equality(right_half_quarter_point, tested_half_quarter_point));
}

