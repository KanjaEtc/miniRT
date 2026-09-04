#include "../include/header.h"

/* =============================== 2x2 MATRIX DETERMINANT ============================== */

Test(matrix, matrix2_determinant)
{
	t_matrix *m1 = ft_matrix_creator(2);
	t_matrix *m2 = ft_matrix_creator(2);
	t_matrix *m3 = ft_matrix_creator(2);
	
	test_fill_matrix(m1, -1);
	test_fill_matrix(m2, -0.5);
	test_fill_matrix(m3, 2);

	cr_assert_eq(ft_matrix_determinant(m1), -0.5);
	cr_assert_eq(ft_matrix_determinant(m2), -0.5);
	cr_assert_eq(ft_matrix_determinant(m3), -0.5);
}


/* =============================== SUBMATRIX ============================== */

void test_expected4_submatrix(t_matrix *exp)
{
	exp->mtx[0][0] = 0;
	exp->mtx[0][1] = 0.5;
	exp->mtx[0][2] = 1;
	exp->mtx[1][0] = 2;
	exp->mtx[1][1] = 2.5;
	exp->mtx[1][2] = 3;
	exp->mtx[2][0] = 4;
	exp->mtx[2][1] = 4.5;
	exp->mtx[2][2] = 5;
}

void test_expected3_submatrix(t_matrix *exp)
{
	exp->mtx[0][0] = 1.5;
	exp->mtx[0][1] = 2.5;
	exp->mtx[1][0] = 3;
	exp->mtx[1][1] = 4;
}

Test(matrix, submatrix)
{
	t_matrix *m3 = ft_matrix_creator(3);
	t_matrix *m4 = ft_matrix_creator(4);
	test_fill_matrix(m3, 0);
	test_fill_matrix(m4, 0);

	t_matrix *expected3 = ft_matrix_creator(2);
	t_matrix *expected4 = ft_matrix_creator(3);
	test_expected3_submatrix(expected3);
	test_expected4_submatrix(expected4);

	cr_assert(ft_matrix_equality(ft_submatrix(m3, 0, 1), expected3));
	cr_assert(ft_matrix_equality(ft_submatrix(m4, 3, 3), expected4));
}

Test(matrix, submatrix_bad_arguments)
{
	t_matrix *m = ft_matrix_creator(4);
	test_fill_matrix(m, 0);
	
	cr_assert_null(ft_submatrix(m, -1, 0));
	cr_assert_null(ft_submatrix(m, 0, 10));
	cr_assert_null(ft_submatrix(m, 42, -2));
	
	cr_assert_null(ft_submatrix(NULL, 0, 0));
}


/* =============================== MINOR ============================== */

Test(matrix, minor)
{
	t_matrix *m3 = ft_matrix_creator(3);
	test_fill_matrix(m3, 0);

	cr_assert_eq(ft_minor(m3, 0, 1), -1.5);
	cr_assert_eq(ft_minor(m3, 0, 0), -0.75);
}

Test(matrix, minor_bad_arguments)
{
	t_matrix *m = ft_matrix_creator(4);
	test_fill_matrix(m, 0);

	cr_assert_eq(ft_minor(m, 0, 2), 0);
	cr_assert_eq(ft_minor(m, -1, 0), 0);
	cr_assert_eq(ft_minor(m, 0, -0.1), 0);
	cr_assert_eq(ft_minor(m, -100, 10), 0);
	
	cr_assert_eq(ft_minor(NULL, -2, 2), 0);
}


/* =============================== MINOR ============================== */

Test(matrix, cofactor)
{
	t_matrix *m3 = ft_matrix_creator(3);
	test_fill_matrix(m3, 0);

	cr_assert_eq(ft_cofactor(m3, 0, 1), 1.5);
	cr_assert_eq(ft_cofactor(m3, 0, 0), -0.75);
}

Test(matrix, cofactor_bad_arguments)
{
	t_matrix *m4 = ft_matrix_creator(4);
	test_fill_matrix(m4, 0);

	cr_assert_eq(ft_cofactor(m4, 0, 1), 0);
	cr_assert_eq(ft_cofactor(m4, -2, 1), 0);
	cr_assert_eq(ft_cofactor(m4, 0, 20), 0);
	cr_assert_eq(ft_cofactor(m4, 42, -2), 0);
	cr_assert_eq(ft_cofactor(NULL, 0, 0), 0);
}


/* =============================== LARGE MATRICES DETERMINANT ============================== */

void test_fill_m3_for_determinant_1(t_matrix *m)
{
	m->mtx[0][0] = 1;
	m->mtx[0][1] = 2;
	m->mtx[0][2] = 6;
	m->mtx[1][0] = -5;
	m->mtx[1][1] = 8;
	m->mtx[1][2] = -4;
	m->mtx[2][0] = 2;
	m->mtx[2][1] = 6;
	m->mtx[2][2] = 4;
}

void test_fill_m3_for_determinant_2(t_matrix *m)
{
	m->mtx[0][0] = -1;
	m->mtx[0][1] = 2;
	m->mtx[0][2] = 5;
	m->mtx[1][0] = 1;
	m->mtx[1][1] = 2;
	m->mtx[1][2] = 3;
	m->mtx[2][0] = -2;
	m->mtx[2][1] = 8;
	m->mtx[2][2] = 10;
}

Test(matrix, determinant_3x3)
{
	t_matrix *m = ft_matrix_creator(3);
	
	test_fill_m3_for_determinant_1(m);
	cr_assert_eq(ft_matrix_determinant(m), -196);

	test_fill_m3_for_determinant_2(m);
	cr_assert_eq(ft_matrix_determinant(m), 32);
}

void test_fill_m4_for_determinant_1(t_matrix *m)
{
	m->mtx[0][0] = -2;
	m->mtx[0][1] = -8;
	m->mtx[0][2] = 3;
	m->mtx[0][3] = 5;
	m->mtx[1][0] = -3;
	m->mtx[1][1] = 1;
	m->mtx[1][2] = 7;
	m->mtx[1][3] = 3;
	m->mtx[2][0] = 1;
	m->mtx[2][1] = 2;
	m->mtx[2][2] = -9;
	m->mtx[2][3] = 6;
	m->mtx[3][0] = -6;
	m->mtx[3][1] = 7;
	m->mtx[3][2] = 7;
	m->mtx[3][3] = -9;
}

void test_fill_m4_for_determinant_2(t_matrix *m)
{
	m->mtx[0][0] = 1;
	m->mtx[0][1] = 0;
	m->mtx[0][2] = 2;
	m->mtx[0][3] = 0;
	m->mtx[1][0] = 3;
	m->mtx[1][1] = 1;
	m->mtx[1][2] = 0;
	m->mtx[1][3] = 0;
	m->mtx[2][0] = 0;
	m->mtx[2][1] = 0;
	m->mtx[2][2] = 4;
	m->mtx[2][3] = 1;
	m->mtx[3][0] = 2;
	m->mtx[3][1] = 0;
	m->mtx[3][2] = 1;
	m->mtx[3][3] = 3;
}

Test(matrix, determinant_4x4)
{
	t_matrix *m = ft_matrix_creator(4);
	
	test_fill_m4_for_determinant_1(m);
	cr_assert_eq(ft_matrix_determinant(m), -4071);

	test_fill_m4_for_determinant_2(m);
	cr_assert_eq(ft_matrix_determinant(m), 15);
}

Test(matrix, matrix_determinant_bad_argments)
{
	t_matrix *m = ft_matrix_creator(3);
	test_fill_matrix(m, 0);

	cr_assert_eq(ft_matrix_determinant(m), 0);
	cr_assert_eq(ft_matrix_determinant(NULL), 0);
}
