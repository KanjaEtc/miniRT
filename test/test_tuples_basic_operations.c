#include "../include/header.h"

/* =============================== ADDITION ============================== */

Test(tuples, vectors_addition)
{
	t_tuple *v1 = ft_vector_creator(0, 1, -1.5);
	t_tuple *v2 = ft_vector_creator(2, -0.5, -8);
	t_tuple	*result = ft_vector_creator(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
	cr_assert(ft_vectors_equality(ft_tuples_addition(v1, v2), result));
	cr_assert(ft_vectors_equality(ft_tuples_addition(v2, v1), result));
}

Test(tuples, vector_point_addition)
{
	t_tuple *v = ft_vector_creator(0, 1, -1.5);
	t_tuple *p = ft_point_creator(2, -0.5, -8);
	t_tuple	*result = ft_point_creator(v->x + p->x, v->y + p->y, v->z + p->z);
	cr_assert(ft_points_equality(ft_tuples_addition(v, p), result));
}

Test(tuples, addition_bad_arguments)
{
	t_tuple *v = ft_vector_creator(0, 1, -1.5);
	t_tuple	*p1 = ft_point_creator(0, 1, -1.5);
	t_tuple *p2 = ft_point_creator(2, -0.5, -8);
	
	cr_assert(ft_tuples_addition(p1, p2) == NULL);
	cr_assert(ft_tuples_addition(p1, NULL) == NULL);
	cr_assert(ft_tuples_addition(NULL, p1) == NULL);
	cr_assert(ft_tuples_addition(v, NULL) == NULL);
	cr_assert(ft_tuples_addition(NULL, v) == NULL);
	cr_assert(ft_tuples_addition(NULL, NULL) == NULL);
}


/* =============================== SUBTRACTION ============================== */

Test(tuples, vectors_subtraction)
{
	t_tuple *v1 = ft_vector_creator(0, 1, -1.5);
	t_tuple *v2 = ft_vector_creator(2, -0.5, -8);
	t_tuple	*result = ft_vector_creator(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	cr_assert(ft_vectors_equality(ft_tuples_subtraction(v1, v2), result));
}

Test(tuples, points_subtraction)
{
	t_tuple *v = ft_point_creator(0, 1, -1.5);
	t_tuple *p = ft_point_creator(2, -0.5, -8);
	t_tuple	*result = ft_vector_creator(v->x - p->x, v->y - p->y, v->z - p->z);
	cr_assert(ft_vectors_equality(ft_tuples_subtraction(v, p), result));
}

Test(tuples, point_vector_subtraction)
{
	t_tuple *p = ft_point_creator(2, -0.5, -8);
	t_tuple *v = ft_vector_creator(0, 1, -1.5);
	t_tuple	*result = ft_point_creator(p->x - v->x, p->y - v->y, p->z - v->z);
	cr_assert(ft_points_equality(ft_tuples_subtraction(p, v), result));
}

Test(tuples, subtraction_bad_arguments)
{
	t_tuple *v = ft_vector_creator(0, 1, -1.5);
	t_tuple	*p = ft_point_creator(0, 1, -1.5);
	
	cr_assert(ft_tuples_subtraction(v, p) == NULL);
	cr_assert(ft_tuples_subtraction(p, NULL) == NULL);
	cr_assert(ft_tuples_subtraction(NULL, p) == NULL);
	cr_assert(ft_tuples_subtraction(v, NULL) == NULL);
	cr_assert(ft_tuples_subtraction(NULL, v) == NULL);
	cr_assert(ft_tuples_subtraction(NULL, NULL) == NULL);
}


/* ======================== OPPOSITE ======================= */

Test(tuples, opposite)
{
	t_tuple	*vector = ft_vector_creator(0, 1, -2.8);
	t_tuple *opposite = ft_vector_creator(-vector->x, -vector->y, -vector->z);
	cr_assert(ft_vectors_equality(ft_tuple_opposite(vector), opposite));
}

Test(tuples, opposite_bd_arguments)
{
	cr_assert(ft_tuple_opposite(NULL) == NULL);
}


/* ======================== VECTOR BY SCALAR MULTIPLICATION ======================= */

Test(tuples, vector_by_positive_scalar_multiplication)
{
	t_tuple *v = ft_vector_creator(0, -8, 0.5);
	double scalar = 1.5;
	t_tuple *result = ft_point_creator(v->x * scalar, v->y * scalar, v->z * scalar);
	cr_assert(ft_points_equality(ft_vector_by_scalar_multiplication(v, scalar), result));
}

Test(tuples, vector_by_negative_scalar_multiplication)
{
	t_tuple *v = ft_vector_creator(0, -8, 0.5);
	double scalar = -2;
	t_tuple *result = ft_point_creator(v->x * scalar, v->y * scalar, v->z * scalar);
	cr_assert(ft_points_equality(ft_vector_by_scalar_multiplication(v, scalar), result));
}

Test(tuples, vector_by_scalar_multiplication_bad_arguments)
{
	double scalar = 2;
	t_tuple *point = ft_point_creator(0, 1, 2);

	cr_assert(ft_vector_by_scalar_multiplication(point, scalar) == NULL);
	cr_assert(ft_vector_by_scalar_multiplication(NULL, scalar) == NULL);
}


/* ======================== VECTOR BY SCALAR DIVISION ======================= */

Test(tuples, vector_by_positive_scalar_division)
{
	t_tuple *v = ft_vector_creator(0, -8, 0.5);
	double scalar = 1.5;
	t_tuple *result = ft_point_creator(v->x / scalar, v->y / scalar, v->z / scalar);
	cr_assert(ft_points_equality(ft_vector_by_scalar_division(v, scalar), result));
}

Test(tuples, vector_by_negative_scalar_division)
{
	t_tuple *v = ft_vector_creator(0, -8, 0.5);
	double scalar = -2;
	t_tuple *result = ft_point_creator(v->x / scalar, v->y / scalar, v->z / scalar);
	cr_assert(ft_points_equality(ft_vector_by_scalar_division(v, scalar), result));
}

Test(tuples, vector_by_scalar_division_bad_arguments)
{
	double scalar = 2;
	t_tuple *point = ft_point_creator(0, 1, 2);
	t_tuple *vector = ft_vector_creator(0, 1, 2);

	cr_assert(ft_vector_by_scalar_division(point, scalar) == NULL);
	cr_assert(ft_vector_by_scalar_division(vector, 0) == NULL);
	cr_assert(ft_vector_by_scalar_division(NULL, scalar) == NULL);
}
