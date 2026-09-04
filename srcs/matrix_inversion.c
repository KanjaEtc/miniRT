#include "../include/header.h"

int	ft_is_matrix_invertible(t_matrix *m)
{
	return (ft_matrix_determinant(m) != 0);
}

t_matrix	*ft_inverse(t_matrix *m)
{
	t_matrix	*inverse;
	double		det;
	int			row;
	int			col;
	int			sign;

	if (!m || !m->mtx)
		return (NULL);
	det = ft_matrix_determinant(m);
	if (!det)
		return (NULL);
	inverse = ft_matrix_creator(m->n);
	if (!inverse)
		return (NULL);
	sign = 1;
	row = -1;
	while (++row < m->n)
	{
		col = -1;
		while (++col < m->n)
		{
			inverse->mtx[col][row] = sign * (ft_matrix_determinant(ft_submatrix(m, row, col)) / det);
			sign = -sign;
		}
		sign = -sign;
	}
	return (inverse);
}

// int main()
// {
// 	t_matrix *m = ft_matrix_creator(4);
// 	test_fill_m4_inversion(m);

// 	ft_display_matrix(ft_inverse(m));
// }
