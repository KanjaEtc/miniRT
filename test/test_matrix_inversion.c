#include "../include/header.h"

/* =============================== TESTING INVERTIBILITY ============================== */

void test_fill_m4_not_invertible(t_matrix *m)
{
	m->mtx[0][0] = -4;
	m->mtx[0][1] = 2;
	m->mtx[0][2] = -2;
	m->mtx[0][3] = -3;
	m->mtx[1][0] = 9;
	m->mtx[1][1] = 6;
	m->mtx[1][2] = 2;
	m->mtx[1][3] = 6;
	m->mtx[2][0] = 0;
	m->mtx[2][1] = -5;
	m->mtx[2][2] = 1;
	m->mtx[2][3] = -5;
	m->mtx[3][0] = 0;
	m->mtx[3][1] = 0;
	m->mtx[3][2] = 0;
	m->mtx[3][3] = 0;
}

Test(matrix, is_not_invertible)
{
	t_matrix *m = ft_matrix_creator(4);
	test_fill_m4_not_invertible(m);
	cr_assert(!ft_is_matrix_invertible(m));
}

void test_fill_m4_is_invertible(t_matrix *m)
{
	m->mtx[0][0] = 6;
	m->mtx[0][1] = 4;
	m->mtx[0][2] = 4;
	m->mtx[0][3] = 4;
	m->mtx[1][0] = 5;
	m->mtx[1][1] = 5;
	m->mtx[1][2] = 7;
	m->mtx[1][3] = 6;
	m->mtx[2][0] = 4;
	m->mtx[2][1] = -9;
	m->mtx[2][2] = 3;
	m->mtx[2][3] = -7;
	m->mtx[3][0] = 9;
	m->mtx[3][1] = 1;
	m->mtx[3][2] = 7;
	m->mtx[3][3] = -6;
}

Test(matrix, is_invertible)
{
	t_matrix *m = ft_matrix_creator(4);
	test_fill_m4_is_invertible(m);
	cr_assert(ft_is_matrix_invertible(m));
}

Test(matrix, is_it_invertible_bad_arguments)
{
	cr_assert(!ft_is_matrix_invertible(NULL));
}


/* =============================== INVERSION ============================== */

void test_fill_m4_inversion_1(t_matrix *m)
{
	m->mtx[0][0] = -5;
	m->mtx[0][1] = 2;
	m->mtx[0][2] = 6;
	m->mtx[0][3] = -8;
	m->mtx[1][0] = 1;
	m->mtx[1][1] = -5;
	m->mtx[1][2] = 1;
	m->mtx[1][3] = 8;
	m->mtx[2][0] = 7;
	m->mtx[2][1] = 7;
	m->mtx[2][2] = -6;
	m->mtx[2][3] = -7;
	m->mtx[3][0] = 1;
	m->mtx[3][1] = -3;
	m->mtx[3][2] = 7;
	m->mtx[3][3] = 4;
}

void test_fill_m4_inversion_2(t_matrix *m)
{
	m->mtx[0][0] = 8;
	m->mtx[0][1] = -5;
	m->mtx[0][2] = 9;
	m->mtx[0][3] = 2;
	m->mtx[1][0] = 7;
	m->mtx[1][1] = 5;
	m->mtx[1][2] = 6;
	m->mtx[1][3] = 1;
	m->mtx[2][0] = -6;
	m->mtx[2][1] = 0;
	m->mtx[2][2] = 9;
	m->mtx[2][3] = 6;
	m->mtx[3][0] = -3;
	m->mtx[3][1] = 0;
	m->mtx[3][2] = -9;
	m->mtx[3][3] = -4;
}

void test_fill_m4_inversion_3(t_matrix *m)
{
	m->mtx[0][0] = 9;
	m->mtx[0][1] = 3;
	m->mtx[0][2] = 0;
	m->mtx[0][3] = 9;
	m->mtx[1][0] = -5;
	m->mtx[1][1] = -2;
	m->mtx[1][2] = -6;
	m->mtx[1][3] = -3;
	m->mtx[2][0] = -4;
	m->mtx[2][1] = 9;
	m->mtx[2][2] = 6;
	m->mtx[2][3] = 4;
	m->mtx[3][0] = -7;
	m->mtx[3][1] = 6;
	m->mtx[3][2] = 6;
	m->mtx[3][3] = 2;
}

void test_fill_expected_inverted_1(t_matrix *m)
{
	m->mtx[0][0] = 0.21805;
	m->mtx[0][1] = 0.45113;
	m->mtx[0][2] = 0.24060;
	m->mtx[0][3] = -0.04511;
	m->mtx[1][0] = -0.80827;
	m->mtx[1][1] = -1.45677;
	m->mtx[1][2] = -0.44361;
	m->mtx[1][3] = 0.52068;
	m->mtx[2][0] = -0.07895;
	m->mtx[2][1] = -0.22368;
	m->mtx[2][2] = -0.05263;
	m->mtx[2][3] = 0.19737;
	m->mtx[3][0] = -0.52256;
	m->mtx[3][1] = -0.81391;
	m->mtx[3][2] = -0.30075;
	m->mtx[3][3] = 0.30639;
}

void test_fill_expected_inverted_2(t_matrix *m)
{
	m->mtx[0][0] = -0.15385;
	m->mtx[0][1] = -0.15385;
	m->mtx[0][2] = -0.28205;
	m->mtx[0][3] = -0.53846;
	m->mtx[1][0] = -0.07692;
	m->mtx[1][1] = 0.12308;
	m->mtx[1][2] = 0.02564;
	m->mtx[1][3] = 0.03077;
	m->mtx[2][0] = 0.35897;
	m->mtx[2][1] = 0.35897;
	m->mtx[2][2] = 0.43590;
	m->mtx[2][3] = 0.92308;
	m->mtx[3][0] = -0.69231;
	m->mtx[3][1] = -0.69231;
	m->mtx[3][2] = -0.76923;
	m->mtx[3][3] = -1.92308;
}

void test_fill_expected_inverted_3(t_matrix *m)
{
	m->mtx[0][0] = -0.04074;
	m->mtx[0][1] = -0.07778;
	m->mtx[0][2] = 0.14444;
	m->mtx[0][3] = -0.22222;
	m->mtx[1][0] = -0.07778;
	m->mtx[1][1] = 0.03333;
	m->mtx[1][2] = 0.36667;
	m->mtx[1][3] = -0.33333;
	m->mtx[2][0] = -0.02901;
	m->mtx[2][1] = -0.14630;
	m->mtx[2][2] = -0.10926;
	m->mtx[2][3] = 0.12963;
	m->mtx[3][0] = 0.17778;
	m->mtx[3][1] = 0.06667;
	m->mtx[3][2] = -0.26667;
	m->mtx[3][3] = 0.33333;
}

Test(matrix, inversion)
{
	t_matrix *m_1 = ft_matrix_creator(4);
	t_matrix *exp_1 = ft_matrix_creator(4);

	test_fill_m4_inversion_1(m_1);
	test_fill_expected_inverted_1(exp_1);
	cr_assert(ft_matrix_equality(ft_inverse(m_1), exp_1));

	t_matrix *m_2 = ft_matrix_creator(4);
	t_matrix *exp_2 = ft_matrix_creator(4);

	test_fill_m4_inversion_2(m_2);
	test_fill_expected_inverted_2(exp_2);
	cr_assert(ft_matrix_equality(ft_inverse(m_2), exp_2));

	t_matrix *m_3 = ft_matrix_creator(4);
	t_matrix *exp_3 = ft_matrix_creator(4);

	test_fill_m4_inversion_3(m_3);
	test_fill_expected_inverted_3(exp_3);
	cr_assert(ft_matrix_equality(ft_inverse(m_3), exp_3));
}

Test(matrix, inversion_bad_arguments)
{
	t_matrix *not_invertible = ft_matrix_creator(4);
	test_fill_m4_not_invertible(not_invertible);

	cr_assert_null(ft_inverse(not_invertible));
	cr_assert_null(ft_inverse(NULL));
}


/* =============================== INVERSION AND MULTIPLICATION ============================== */

Test(matrix, inversion_and_multiplication)
{
	t_matrix *m_1 = ft_matrix_creator(4);
	t_matrix *m_2 = ft_matrix_creator(4);
	test_fill_m4_inversion_1(m_1);
	test_fill_m4_inversion_2(m_2);

	t_matrix *product = ft_matrices_multplication(m_1, m_2);

	t_matrix *inverse_m_2 = ft_inverse(m_2);

	cr_assert(ft_matrix_equality(m_1, ft_matrices_multplication(product, inverse_m_2)));
}
