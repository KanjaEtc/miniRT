#include "../include/header.h"

/* =============================== MATRICES MULTIPLICATION ============================== */

t_matrix *test_expected_matrix(t_matrix *expected)
{
	expected->mtx[0][0] = -15;
	expected->mtx[0][1] = -17.5;
	expected->mtx[0][2] = -20;
	expected->mtx[0][3] = -22.5;
	expected->mtx[1][0] = 17;
	expected->mtx[1][1] = 18.5;
	expected->mtx[1][2] = 20;
	expected->mtx[1][3] = 21.5;
	expected->mtx[2][0] = 49;
	expected->mtx[2][1] = 54.5;
	expected->mtx[2][2] = 60;
	expected->mtx[2][3] = 65.5;
	expected->mtx[3][0] = 81;
	expected->mtx[3][1] = 90.5;
	expected->mtx[3][2] = 100;
	expected->mtx[3][3] = 109.5;
	return (expected);
}

void test_fill_matrix(t_matrix *matrix, double start)
{
	int	i = -1;
	int	j;

	while (++i < matrix->n)
	{
		j = -1;
		while (++j < matrix->n)
		{
			matrix->mtx[i][j] = start;
			start += 0.5;
		}
	}
}

Test(matrix, matrix_multiplication)
{
	t_matrix *a = ft_matrix_creator(4);
	t_matrix *b = ft_matrix_creator(4);

	test_fill_matrix(a, -2);
	test_fill_matrix(b, 1);

	t_matrix *product = ft_matrices_multplication(a, b);
	t_matrix *expected = test_expected_matrix(ft_matrix_creator(4));
	cr_assert(ft_matrix_equality(product, expected));

	t_matrix *wrong_product = ft_matrix_creator(4);
	test_fill_matrix(wrong_product, 0);
	cr_assert(!ft_matrix_equality(ft_matrices_multplication(a, b), wrong_product));
}

Test(matrix, identity_matrix_multiplication)
{
	t_matrix *a = ft_matrix_creator(4);
	test_fill_matrix(a, -2);
	
	t_matrix *id = ft_identity_matrix_creator(4);
	
	t_matrix *product = ft_matrices_multplication(a, id);

	cr_assert(ft_matrix_equality(product, a));
}


Test(matrix, matrix_multiplication_bad_arguments)
{
	t_matrix *a = ft_matrix_creator(3);
	t_matrix *b = ft_matrix_creator(4);

	cr_assert_null(ft_matrices_multplication(a, b));
	cr_assert_null(ft_matrices_multplication(b, a));
	
	cr_assert_null(ft_matrices_multplication(NULL, b));
	cr_assert_null(ft_matrices_multplication(b, NULL));
	cr_assert_null(ft_matrices_multplication(NULL, NULL));
}

/* =============================== MATRIX BY TUPLE MULTIPLICATION ============================== */

Test(matrix, matrix_by_tuple_multiplication)
{
	t_matrix *m = ft_matrix_creator(4);
	test_fill_matrix(m, -3);

	t_tuple *t = ft_vector_creator(1, 2, 3);

	t_tuple *result = ft_matrix_by_tuple_multiplication(m, t);

	cr_assert_eq(result->x, -14);
	cr_assert_eq(result->y, -2);
	cr_assert_eq(result->z, 10);
	cr_assert_eq(result->w, 22);
}

Test(matrix, identity_matrix_by_tuple_multiplication)
{
	t_matrix *id = ft_identity_matrix_creator(4);

	t_tuple *t = ft_vector_creator(1, 2, 3);

	t_tuple *result = ft_matrix_by_tuple_multiplication(id, t);

	cr_assert_eq(result->x, t->x);
	cr_assert_eq(result->y, t->y);
	cr_assert_eq(result->z, t->z);
	cr_assert_eq(result->w, t->w);
}

Test(matrix, matrix_by_tuple_multiplication_bad_arguments)
{
	t_matrix *m4 = ft_matrix_creator(4);
	t_matrix *m3 = ft_matrix_creator(3);
	t_tuple *t = ft_vector_creator(1, 2, 3);
	
	cr_assert_null(ft_matrix_by_tuple_multiplication(m3, t));

	cr_assert_null(ft_matrix_by_tuple_multiplication(m4, NULL));
	cr_assert_null(ft_matrix_by_tuple_multiplication(NULL, t));
	cr_assert_null(ft_matrix_by_tuple_multiplication(m3, NULL));
	cr_assert_null(ft_matrix_by_tuple_multiplication(NULL, NULL));
}


/* =============================== MATRIX TRANSPOSITION ============================== */

void	test_expected_matrix_transposition(t_matrix *expected)
{
	expected->mtx[0][0] = 0;
	expected->mtx[0][1] = 2;
	expected->mtx[0][2] = 4;
	expected->mtx[0][3] = 6;
	expected->mtx[1][0] = 0.5;
	expected->mtx[1][1] = 2.5;
	expected->mtx[1][2] = 4.5;
	expected->mtx[1][3] = 6.5;
	expected->mtx[2][0] = 1;
	expected->mtx[2][1] = 3;
	expected->mtx[2][2] = 5;
	expected->mtx[2][3] = 7;
	expected->mtx[3][0] = 1.5;
	expected->mtx[3][1] = 3.5;
	expected->mtx[3][2] = 5.5;
	expected->mtx[3][3] = 7.5;
}

Test(matrix, random_matrix_transposition)
{
	t_matrix	*m = ft_matrix_creator(4);
	test_fill_matrix(m, 0);

	t_matrix	*transposed = ft_transpose_matrix(m);

	t_matrix *expected = ft_matrix_creator(4);
	test_expected_matrix_transposition(expected);

	cr_assert(ft_matrix_equality(transposed, expected));
}

Test(matrix, identity_matrix_transposition)
{
	t_matrix	*id = ft_identity_matrix_creator(4);
	t_matrix	*transposed = ft_transpose_matrix(id);

	cr_assert(ft_matrix_equality(transposed, id));
}

Test(matrix, matrix_transposition_bad_arguments)
{
	cr_assert_null(ft_transpose_matrix(NULL));
}
