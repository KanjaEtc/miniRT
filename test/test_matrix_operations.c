#include "../include/header.h"

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

void ft_fill_matrix(t_matrix *matrix, double start)
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

	ft_fill_matrix(a, -2);
	ft_fill_matrix(b, 1);

	t_matrix *product = ft_matrices_multplication(a, b);
	t_matrix *expected = test_expected_matrix(ft_matrix_creator(4));
	cr_assert(ft_matrix_equality(product, expected));

	t_matrix *wrong_product = ft_matrix_creator(4);
	ft_fill_matrix(wrong_product, 0);
	cr_assert(!ft_matrix_equality(ft_matrices_multplication(a, b), wrong_product));
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
