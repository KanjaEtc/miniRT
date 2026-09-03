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

	cr_assert_eq(ft_matrix2_determinant(m1), -0.5);
	cr_assert_eq(ft_matrix2_determinant(m2), -0.5);
	cr_assert_eq(ft_matrix2_determinant(m3), -0.5);
}

Test(matrix, matrix2_determinant_bad_arguments)
{
	t_matrix *m = ft_matrix_creator(3);
	test_fill_matrix(m, 0);

	cr_assert_eq(ft_matrix2_determinant(m), 0);
	cr_assert_eq(ft_matrix2_determinant(NULL), 0);
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

// Test(matrix, cofactor)
// {
// 	t_matrix *m3 = ft_matrix_creator(3);
// 	test_fill_matrix(m3, 0);

// 	cr_assert_eq(ft_cofactor(m3, 0, 1), 1.5);
// 	cr_assert_eq(ft_cofactor(m3, 0, 0), -0.75);
// }
