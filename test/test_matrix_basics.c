#include "../include/header.h"

Test(matrix, matrix_creation)
{
	cr_assert_not_null(ft_matrix_creator(4));
	cr_assert_not_null(ft_matrix_creator(3));
	
	cr_assert_null(ft_matrix_creator(0));
	cr_assert_null(ft_matrix_creator(-2));
}

Test(matrix, matrices_are_equal)
{
	t_matrix  *a = ft_matrix_creator(2);
	t_matrix *b = ft_matrix_creator(2);
	a->mtx[0][0] = b->mtx[0][0] = 0;
	a->mtx[0][1] = b->mtx[0][1] = 1;
	a->mtx[1][0] = b->mtx[1][0] = 2.9;
	a->mtx[1][1] = b->mtx[1][1] = -3;

	cr_assert(ft_matrix_equality(a, b));
}

Test(matrix, matrices_are_not_equal)
{
	t_matrix  *a = ft_matrix_creator(2);
	t_matrix *b = ft_matrix_creator(2);
	a->mtx[0][0] = b->mtx[0][0] = 0;
	a->mtx[0][1] = 1;
	b->mtx[0][1] = -1;
	a->mtx[1][0] = b->mtx[1][0] = 2.9;
	a->mtx[1][1] = b->mtx[1][1] = -3;

	cr_assert(ft_matrix_equality(a, b) == 0);
}

Test(matrix, matrices_are_equal_epsilon)
{
	t_matrix  *a = ft_matrix_creator(2);
	t_matrix *b = ft_matrix_creator(2);
	a->mtx[0][0] = b->mtx[0][0] = 0;
	a->mtx[0][1] = 1;
	b->mtx[0][1] = 1.00001;
	a->mtx[1][0] = b->mtx[1][0] = 2.9;
	a->mtx[1][1] = b->mtx[1][1] = -3;

	cr_assert(ft_matrix_equality(a, b));
}

Test(matrix, matrices_are_almost_equal_greater_than_epsilon)
{
	t_matrix  *a = ft_matrix_creator(2);
	t_matrix *b = ft_matrix_creator(2);
	a->mtx[0][0] = b->mtx[0][0] = 0;
	a->mtx[0][1] = 1;
	b->mtx[0][1] = 0.0001;
	a->mtx[1][0] = b->mtx[1][0] = 2.9;
	a->mtx[1][1] = b->mtx[1][1] = -3;

	cr_assert(ft_matrix_equality(a, b) == 0);
}

Test(matrix, matrices_are_equal_less_than_epsilon)
{
	t_matrix  *a = ft_matrix_creator(2);
	t_matrix *b = ft_matrix_creator(2);
	a->mtx[0][0] = b->mtx[0][0] = 0;
	a->mtx[0][1] = 1;
	b->mtx[0][1] = 1.000001;
	a->mtx[1][0] = b->mtx[1][0] = 2.9;
	a->mtx[1][1] = b->mtx[1][1] = -3;

	cr_assert(ft_matrix_equality(a, b));
}

Test(matrix, different_size_matrices)
{
	t_matrix  *a = ft_matrix_creator(2);
	t_matrix *b = ft_matrix_creator(3);
	a->mtx[0][0] = b->mtx[0][0] = 0;
	a->mtx[0][1] = b->mtx[0][1] = 1;
	a->mtx[1][0] = b->mtx[1][0] = 2.9;
	a->mtx[1][1] = b->mtx[1][1] = -3;

	cr_assert(ft_matrix_equality(a, b) == 0);
}

Test(matrix, matrix_basics_bad_arguments)
{
	t_matrix  *a = ft_matrix_creator(2);
	t_matrix *b = ft_matrix_creator(3);
	a->mtx[0][0] = b->mtx[0][0] = 0;
	a->mtx[0][1] = b->mtx[0][1] = 1;
	a->mtx[1][0] = b->mtx[1][0] = 2.9;
	a->mtx[1][1] = b->mtx[1][1] = -3;

	cr_assert(ft_matrix_equality(NULL, b) == 0);
	cr_assert(ft_matrix_equality(a, NULL) == 0);
	cr_assert(ft_matrix_equality(NULL, NULL) == 0);
}
