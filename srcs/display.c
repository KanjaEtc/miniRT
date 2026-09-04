#include "../include/header.h"

void	ft_display_matrix(t_matrix *matrix)
{
	int	i = -1;
	int	j;

	while (++i < matrix->n)
	{
		j = -1;
		while (++j < matrix->n)
			printf("%f ", matrix->mtx[i][j]);
		printf("\n");
	}
}

void	ft_display_tuple(t_tuple *t)
{
	if (!t)
		return ;
	printf("%f %f %f %f\n", t->x, t->y, t->z, t->w);
}
