#include "../include/header.h"

t_matrix	*ft_matrices_multplication(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			i;
	int			j;
	int			k;
	double		sum;

	if (!a || !b || !a->mtx || !b->mtx || a->n != 4 || b->n != 4)
		return (NULL);
	result = ft_matrix_creator(4);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			sum = 0;
			while (++k < 4)
				sum += a->mtx[i][k] * b->mtx[k][j];
			result->mtx[i][j] = sum;
		}
	}
	return (result);
}

static double	ft_one_row_matrix_by_tuple_multiplication(double *matrix_row,
	t_tuple *t)
{
	if (!matrix_row || !t)
		return (0);
	return (t->x * matrix_row[0]
		+ t->y * matrix_row[1]
		+ t->z * matrix_row[2]
		+ t->w * matrix_row[3]);
}

t_tuple	*ft_matrix_by_tuple_multiplication(t_matrix *m, t_tuple *t)
{
	t_tuple	*result;

	if (!m || !t || !m->mtx || !*m->mtx || m->n != 4)
		return (NULL);
	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = ft_one_row_matrix_by_tuple_multiplication(m->mtx[0], t);
	result->y = ft_one_row_matrix_by_tuple_multiplication(m->mtx[1], t);
	result->z = ft_one_row_matrix_by_tuple_multiplication(m->mtx[2], t);
	result->w = ft_one_row_matrix_by_tuple_multiplication(m->mtx[3], t);
	return (result);
}

t_matrix	*ft_transpose_matrix(t_matrix *m)
{
	t_matrix	*new;
	int			i;
	int			j;

	if (!m || !m->mtx)
		return (NULL);
	new = ft_matrix_creator(m->n);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < m->n)
	{
		j = -1;
		while (++j < m->n)
			new->mtx[i][j] = m->mtx[j][i];
	}
	return (new);
}
