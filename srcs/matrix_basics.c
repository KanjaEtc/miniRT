#include "../include/header.h"

t_matrix	*ft_matrix_creator(int n)
{
	t_matrix	*matrix;
	double		**mtx;
	int			i;

	if (n <= 0)
		return (NULL);
	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	mtx = malloc(sizeof(double *) * n);
	if (!mtx)
		return (free(matrix), NULL);
	i = -1;
	while (++i < n)
	{
		mtx[i] = malloc(sizeof(double) * n);
		if (!mtx[i])
			return (free(matrix), ft_free_double_array(mtx, n));
	}
	matrix->mtx = mtx;
	matrix->n = n;
	return (matrix);
}

int	ft_matrix_equality(t_matrix *a, t_matrix *b)
{
	int		i;
	int		j;
	double	epsilon;

	if (!a || !b || !a->mtx || !b->mtx || !*a->mtx || !*b->mtx || a->n != b->n)
		return (0);
	epsilon = 10e-5;
	i = -1;
	while (++i < a->n)
	{
		j = -1;
		while (++j < a->n)
		{
			if (ft_abs(a->mtx[i][j] - b->mtx[i][j]) > epsilon)
				return (0);
		}
	}
	return (1);
}
