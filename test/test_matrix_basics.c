#include "../include/header.h"


/* =============================== MATRIX CREATION ============================== */

Test(matrix, matrix_creation)
{
	cr_assert_not_null(ft_matrix_creator(4));
	cr_assert_not_null(ft_matrix_creator(3));
	
	cr_assert_null(ft_matrix_creator(0));
	cr_assert_null(ft_matrix_creator(-2));
}


/* =============================== MATRIX COMPARISON ============================== */

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


/* =============================== IDENTITY MATRIX ============================== */

void	test_expected_identity_matrix(t_matrix *m)
{
	m->mtx[0][0] = 1;
	m->mtx[0][1] = 0;
	m->mtx[0][2] = 0;
	m->mtx[0][3] = 0;
	m->mtx[1][0] = 0;
	m->mtx[1][1] = 1;
	m->mtx[1][2] = 0;
	m->mtx[1][3] = 0;
	m->mtx[2][0] = 0;
	m->mtx[2][1] = 0;
	m->mtx[2][2] = 1;
	m->mtx[2][3] = 0;
	m->mtx[3][0] = 0;
	m->mtx[3][1] = 0;
	m->mtx[3][2] = 0;
	m->mtx[3][3] = 1;
}

Test(matrix, identity_matrix_creation)
{
	t_matrix *expected = ft_matrix_creator(4);
	test_expected_identity_matrix(expected);

	cr_assert(ft_matrix_equality(ft_identity_matrix_creator(4), expected));
}

Test(matrix, identity_matrix_creation_bad_arguments)
{
	cr_assert_null(ft_identity_matrix_creator(-1));
	cr_assert_null(ft_identity_matrix_creator(0));
}
