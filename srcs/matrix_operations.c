#include "../include/header.h"

t_matrix	*ft_matrices_multplication(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			i;
	int			j;
	int			k;
	double		sum;

	if (!a || !b || !a->mtx || !b->mtx || !*a->mtx || !*b->mtx)
		return (NULL);
	if (a->n != 4 || b->n != 4)
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

// int main()
// {
// 	t_matrix *a = ft_matrix_creator(4);
// 	t_matrix *b = ft_matrix_creator(4);

// 	ft_fill_matrix(a, -2);
// 	ft_fill_matrix(b, 1);

// 	t_matrix *product = ft_matrices_multplication(a, b);
// 	ft_display_matrix(product);
// }
