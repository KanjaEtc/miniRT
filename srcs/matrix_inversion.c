#include "../include/header.h"

double	ft_matrix2_determinant(t_matrix *m)
{
	if (!m || !m->mtx || m->n != 2)
		return (0);
	return (m->mtx[0][0] * m->mtx[1][1] - m->mtx[0][1] * m->mtx[1][0]);
}

t_matrix	*ft_submatrix(t_matrix *m, int row, int col)
{
	t_matrix	*sub;
	int			i;
	int			j;
	int			r;
	int			c;

	if (!m || !m->mtx || row < 0 || row >= m->n || col < 0 || col >= m->n)
		return (NULL);
	sub = ft_matrix_creator(m->n - 1);
	if (!sub)
		return (NULL);
	i = -1;
	r = 0;
	while (++i < m->n)
	{
		j = -1;
		c = 0;
		while (++j < m->n)
		{
			if (i != row && j != col)
				sub->mtx[r][c++] = m->mtx[i][j];
		}
		if (c)
			r++;
	}
	return (sub);
}

double	ft_minor(t_matrix *m, int row, int col)
{
	t_matrix	*sub;
	double		minor;

	if (!m || !m->mtx || m->n != 3 || row < 0
		|| row >= m->n || col < 0 || col >= m->n)
		return (0);
	sub = ft_submatrix(m, row, col);
	minor = ft_matrix2_determinant(sub);
	ft_free_matrix(sub);
	return (minor);
}

double	ft_cofactor(t_matrix *m, int row, int col)
{
	double	minor;
	
	if (!m || !m->mtx || m->n != 3 || row < 0
		|| row >= m->n || col < 0 || col >= m->n)
	minor = ft_minor(m, row, col);
	if ((row + col) % 2)
		minor = -minor;
	return (minor);
}

// void test_fill_matrix(t_matrix *matrix, double start)
// {
// 	int	i = -1;
// 	int	j;

// 	while (++i < matrix->n)
// 	{
// 		j = -1;
// 		while (++j < matrix->n)
// 		{
// 			matrix->mtx[i][j] = start;
// 			start += 0.5;
// 		}
// 	}
// }

// int main()
// {
// 	t_matrix *m3 = ft_matrix_creator(3);
// 	test_fill_matrix(m3, 0);

// 	ft_cofactor(m3, 0, 1);
// 	ft_cofactor(m3, 0, 0);
// }
