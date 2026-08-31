#include "../include/header.h"

/* =============================== TUPLE'S IDENTITY ============================== */

Test(tuples, is_a_vector)
{
	t_tuple tuple;

	tuple.x = 2;
	tuple.y = -3;
	tuple.z = 4.4;
	tuple.w = 0;
	cr_assert(ft_is_a_vector(&tuple) == 1);
}

Test(tuples, is_not_a_vector)
{
	t_tuple tuple;

	tuple.x = 2;
	tuple.y = -3;
	tuple.z = 4.4;
	tuple.w = 1;
	cr_assert(ft_is_a_vector(&tuple) == 0);
}

Test(tuples, is_a_point)
{
	t_tuple tuple;

	tuple.x = 2.0;
	tuple.y = -3.009;
	tuple.z = 0;
	tuple.w = 1;
	cr_assert(ft_is_a_point(&tuple) == 1);
}

Test(tuples, is_not_a_point)
{
	t_tuple tuple;

	tuple.x = 2.0;
	tuple.y = -3.009;
	tuple.z = 0;
	tuple.w = 0;
	cr_assert(ft_is_a_point(&tuple) == 0);
}


Test(tuples, tuples_identity_bad_arguments)
{
	t_tuple tuple;

	tuple.x = 2;
	tuple.y = -3;
	tuple.z = 4.4;
	tuple.w = -2;
	cr_assert(ft_is_a_vector(&tuple) == 0);
	cr_assert(ft_is_a_vector(NULL) == 0);
	cr_assert(ft_is_a_point(&tuple) == 0);
	cr_assert(ft_is_a_point(NULL) == 0);
}


/* =============================== TUPLE'S CREATION ============================== */

Test(tuples, create_a_vector)
{
	double x = -1.1;
	double y = 0;
	double z = 0.0008;
	t_tuple *tuple = ft_vector_creator(x, y, z);
	cr_assert(ft_is_a_vector(tuple));
	cr_assert(!ft_is_a_point(tuple));
	cr_assert(tuple->x == x && tuple->y == y && tuple->z == z);
}

Test(tuples, create_a_point)
{
	double x = -1.1;
	double y = 0;
	double z = 0.0008;
	t_tuple *tuple = ft_point_creator(x, y, z);
	cr_assert(ft_is_a_point(tuple));
	cr_assert(!ft_is_a_vector(tuple));
	cr_assert(tuple->x == x && tuple->y == y && tuple->z == z);
}


