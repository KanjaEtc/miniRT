#include "../include/header.h"

/* =============================== VECTOR'S LENGTH ============================== */

Test(tuples, vectors_length)
{
	t_tuple *v1 = ft_vector_creator(1, 2, 3);
	t_tuple *v2 = ft_vector_creator(-1, -2, -3);
	t_tuple *v3 = ft_vector_creator(1, 0, 0);

	cr_assert(ft_vector_length(v1) == sqrt(14));
	cr_assert(ft_vector_length(v2) == sqrt(14));
	cr_assert(ft_vector_length(v3) == 1);
}

Test(tuples, vectors_length_bad_arguments)
{
	cr_assert(ft_vector_length(ft_point_creator(1, 2, 3)) == 0);
	cr_assert(ft_vector_length(NULL) == 0);
}


/* =============================== NORMALIZATION ============================== */

Test(tuples, normalization)
{
	t_tuple *v1 = ft_vector_creator(1, 2, 3);
	t_tuple *v2 = ft_vector_creator(1, 0, 0);
	t_tuple *v3 = ft_vector_creator(0, 4, 0);

	t_tuple *r1 = ft_vector_creator(1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));
	t_tuple *r2 = ft_vector_creator(1, 0, 0);
	t_tuple *r3 = ft_vector_creator(0, 1, 0);

	cr_assert(ft_vectors_equality(ft_normalize(v1), r1));
	cr_assert(ft_vectors_equality(ft_normalize(v2), r2));
	cr_assert(ft_vectors_equality(ft_normalize(v3), r3));

}

Test(tuples, normalization_bad_arguments)
{
	cr_assert(ft_normalize(ft_point_creator(1, 2, 3)) == NULL);
	cr_assert(ft_normalize(ft_vector_creator(0, 0, 0)) == NULL);
	cr_assert(ft_normalize(NULL) == NULL);
}


/* =============================== DOT PRODUCT ============================== */

Test(tuples, dot_product)
{
	t_tuple *v1 = ft_vector_creator(1.5, 2, -3);
	t_tuple *v2 = ft_vector_creator(0, 1, 0);
	t_tuple *v3 = ft_vector_creator(3, -0.1, -30);
	
	double product_v1v2 = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	double product_v1v3 = v1->x * v3->x + v1->y * v3->y + v1->z * v3->z;
	double product_v2v3 = v2->x * v3->x + v2->y * v3->y + v2->z * v3->z;
	double product_v1v1 = v1->x * v1->x + v1->y * v1->y + v1->z * v1->z;

	cr_assert(ft_dot_product(v1, v1) == product_v1v1);
	cr_assert(ft_dot_product(v1, v2) == product_v1v2);
	cr_assert(ft_dot_product(v1, v3) == product_v1v3);
	cr_assert(ft_dot_product(v2, v3) == product_v2v3);

	cr_assert(ft_dot_product(v2, v1) == product_v1v2);
	cr_assert(ft_dot_product(v3, v1) == product_v1v3);
	cr_assert(ft_dot_product(v3, v2) == product_v2v3);
}

Test(tuples, dot_product_bad_arguments)
{
	t_tuple *vector = ft_vector_creator(1.5, 2, -3);
	t_tuple *point = ft_point_creator(0, 1, 0);
	
	cr_assert(ft_dot_product(vector, point) == 0);
	cr_assert(ft_dot_product(point, vector) == 0);
	cr_assert(ft_dot_product(point, point) == 0);
	
	cr_assert(ft_dot_product(vector, NULL) == 0);
	cr_assert(ft_dot_product(NULL, vector) == 0);
	cr_assert(ft_dot_product(NULL, point) == 0);
	cr_assert(ft_dot_product(point, NULL) == 0);
	cr_assert(ft_dot_product(NULL, NULL) == 0);
}


/* =============================== CROSS PRODUCT ============================== */

Test(tuple, cross_product)
{
	t_tuple *v1 = ft_vector_creator(0, 0, 0);
	t_tuple *v2 = ft_vector_creator(1, -2, 1.5);
	t_tuple *v3 = ft_vector_creator(-1, -0.5, -4);

	t_tuple *product_v1v2 = ft_vector_creator(v1->y * v2->z - v1->z * v2->y,
		v1->z * v2->x - v1->x * v2->z, v1->x * v2->y - v1->y * v2->x);
	t_tuple *product_v1v3 = ft_vector_creator(v1->y * v3->z - v1->z * v3->y,
		v1->z * v3->x - v1->x * v3->z, v1->x * v3->y - v1->y * v3->x);
	t_tuple *product_v2v3 = ft_vector_creator(v2->y * v3->z - v2->z * v3->y,
		v2->z * v3->x - v2->x * v3->z, v2->x * v3->y - v2->y * v3->x);

	cr_assert(ft_vectors_equality(ft_cross_product(v1, v2), product_v1v2));
	cr_assert(ft_vectors_equality(ft_cross_product(v1, v3), product_v1v3));
	cr_assert(ft_vectors_equality(ft_cross_product(v2, v3), product_v2v3));
}

Test(tuple, cross_product_non_commutative)
{
	t_tuple *v1 = ft_vector_creator(4, 4, 0);
	t_tuple *v2 = ft_vector_creator(1, -2, 1.5);

	cr_assert(ft_vectors_equality(ft_cross_product(v1, v2), ft_cross_product(v2, v1)) == 0);
}

Test(tuple, cross_product_bad_arguments)
{
	t_tuple *vector = ft_vector_creator(1, 0, 0);
	t_tuple *point = ft_point_creator(1, -2, 1.5);

	cr_assert(ft_cross_product(vector, point) == NULL);
	cr_assert(ft_cross_product(point, vector) == NULL);
	cr_assert(ft_cross_product(point, point) == NULL);
	
	cr_assert(ft_cross_product(vector, NULL) == NULL);
	cr_assert(ft_cross_product(NULL, vector) == NULL);
	cr_assert(ft_cross_product(point, NULL) == NULL);
	cr_assert(ft_cross_product(NULL, point) == NULL);
	cr_assert(ft_cross_product(NULL, NULL) == NULL);
}
