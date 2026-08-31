#include "../include/header.h"

/* =============================== VECTORS COMPARISON ============================== */

Test(tuples, vectors_are_equal)
{
	t_tuple *v1 = ft_vector_creator(-1, 2.2, 3);
	t_tuple *v2 = ft_vector_creator(-1, 2.2, 3);
	
	cr_assert(ft_vectors_equality(v1, v2));
	cr_assert(ft_vectors_equality(v2, v1));
	
	cr_assert(ft_vectors_equality(v1, v1));
	cr_assert(ft_vectors_equality(v2, v2));
}

Test(tuples, vectors_are_not_equal_1)
{
	t_tuple *v1 = ft_vector_creator(-1, 2.2, 0);
	t_tuple *v2 = ft_vector_creator(-1, 2.2, 0.1);
	cr_assert(!ft_vectors_equality(v1, v2));
	cr_assert(!ft_vectors_equality(v2, v1));
}

Test(tuples, vectors_are_not_equal_2)
{
	t_tuple *v1 = ft_vector_creator(-1, -2.2, 0);
	t_tuple *v2 = ft_vector_creator(-1, 2.2, 0);
	cr_assert(!ft_vectors_equality(v1, v2));
	cr_assert(!ft_vectors_equality(v2, v1));
}


Test(tuples, vectors_are_almost_equal_more_than_epsilon)
{
	t_tuple *v1 = ft_vector_creator(-1, 2.2, -0.0009);
	t_tuple *v2 = ft_vector_creator(-1, 2.2, 0);
	cr_assert(!ft_vectors_equality(v1, v2));
	cr_assert(!ft_vectors_equality(v2, v1));
}

Test(tuples, vectors_are_equal_epsilon)
{
	t_tuple *v1 = ft_vector_creator(-1, 2.2, 0.00001);
	t_tuple *v2 = ft_vector_creator(-1, 2.2, 0);
	cr_assert(ft_vectors_equality(v1, v2));
	cr_assert(ft_vectors_equality(v2, v1));
}

Test(tuples, vectors_are_equal_less_than_epsilon)
{
	t_tuple *v1 = ft_vector_creator(-1, 2.2, 1.000001);
	t_tuple *v2 = ft_vector_creator(-1, 2.2, 1.000001);
	cr_assert(ft_vectors_equality(v1, v2));
	cr_assert(ft_vectors_equality(v2, v1));
}

Test(tuples, vectors_bad_arguments)
{
	t_tuple *p1 = ft_point_creator(-1, -2.2, 0);
	t_tuple *v2 = ft_vector_creator(-1, -2.2, 0);
	
	cr_assert(!ft_vectors_equality(p1, v2));
	cr_assert(!ft_vectors_equality(v2, p1));

	cr_assert(!ft_vectors_equality(p1, p1));

	cr_assert(!ft_vectors_equality(p1, NULL));
	cr_assert(!ft_vectors_equality(NULL, p1));

	cr_assert(!ft_vectors_equality(NULL, v2));
	cr_assert(!ft_vectors_equality(v2, NULL));

	cr_assert(!ft_vectors_equality(NULL, NULL));
}


/* =============================== POINTS COMPARISON ============================== */


Test(tuples, points_are_equal)
{
	t_tuple *p1 = ft_point_creator(-1, 2.2, 3);
	t_tuple *p2 = ft_point_creator(-1, 2.2, 3);
	
	cr_assert(ft_points_equality(p1, p2));
	cr_assert(ft_points_equality(p2, p1));
	
	cr_assert(ft_points_equality(p1, p1));
	cr_assert(ft_points_equality(p2, p2));
}

Test(tuples, points_are_not_equal_1)
{
	t_tuple *p1 = ft_point_creator(-1, 2.2, 0);
	t_tuple *p2 = ft_point_creator(-1, 2.2, 0.1);
	cr_assert(!ft_points_equality(p1, p2));
	cr_assert(!ft_points_equality(p2, p1));
}

Test(tuples, points_are_not_equal_2)
{
	t_tuple *p1 = ft_point_creator(-1, -2.2, 0);
	t_tuple *p2 = ft_point_creator(-1, 2.2, 0);
	cr_assert(!ft_points_equality(p1, p2));
	cr_assert(!ft_points_equality(p2, p1));
}


Test(tuples, points_are_almost_equal_more_than_epsilon)
{
	t_tuple *p1 = ft_point_creator(-1, 2.2, -0.0009);
	t_tuple *p2 = ft_point_creator(-1, 2.2, 0);
	cr_assert(!ft_points_equality(p1, p2));
	cr_assert(!ft_points_equality(p2, p1));
}

Test(tuples, points_are_equal_epsilon)
{
	t_tuple *p1 = ft_point_creator(-1, 2.2, 10e-5);
	t_tuple *p2 = ft_point_creator(-1, 2.2, 0);
	cr_assert(ft_points_equality(p1, p2));
	cr_assert(ft_points_equality(p2, p1));
}

Test(tuples, points_are_equal_less_than_epsilon)
{
	t_tuple *p1 = ft_point_creator(-1, 2.2, 1.000001);
	t_tuple *p2 = ft_point_creator(-1, 2.2, 1.000001);
	cr_assert(ft_points_equality(p1, p2));
	cr_assert(ft_points_equality(p2, p1));
}

Test(tuples, points_bad_arguments)
{
	t_tuple *p = ft_point_creator(-1, -2.2, 0);
	t_tuple *v = ft_vector_creator(-1, -2.2, 0);
	
	cr_assert(!ft_points_equality(p, v));
	cr_assert(!ft_points_equality(v, p));

	cr_assert(!ft_vectors_equality(p, p));

	cr_assert(!ft_points_equality(p, NULL));
	cr_assert(!ft_points_equality(NULL, v));

	cr_assert(!ft_points_equality(NULL, v));
	cr_assert(!ft_points_equality(v, NULL));

	cr_assert(!ft_points_equality(NULL, NULL));
}
