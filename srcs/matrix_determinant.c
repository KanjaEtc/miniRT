#include "../include/header.h"

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
	minor = ft_matrix_determinant(sub);
	ft_free_matrix(sub);
	return (minor);
}

double	ft_cofactor(t_matrix *m, int row, int col)
{
	double	minor;
	
	if (!m || !m->mtx || m->n != 3 || row < 0
		|| row >= m->n || col < 0 || col >= m->n)
		return (0);
	minor = ft_minor(m, row, col);
	if ((row + col) % 2)
		minor = -minor;
	return (minor);
}

double	ft_matrix_determinant(t_matrix *m)
{
	if (!m || !m->mtx)
		return (0);
	if (m->n == 2)
		return (m->mtx[0][0] * m->mtx[1][1] - m->mtx[0][1] * m->mtx[1][0]);
	if (m->n == 3)
	{
		return (m->mtx[0][0] * ft_cofactor(m, 0, 0)
			+ m->mtx[0][1] * ft_cofactor(m, 0, 1)
			+ m->mtx[0][2] * ft_cofactor(m, 0, 2));
	}
	if (m->n == 4)
	{
		return (m->mtx[0][0] * ft_matrix_determinant(ft_submatrix(m, 0, 0))
			- m->mtx[0][1] * ft_matrix_determinant(ft_submatrix(m, 0, 1))
			+ m->mtx[0][2] * ft_matrix_determinant(ft_submatrix(m, 0, 2))
			- m->mtx[0][3] * ft_matrix_determinant(ft_submatrix(m, 0, 3)));
	}
	return (0);
}


