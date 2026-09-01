#include "../include/header.h"

// void ft_fill_matrix(t_matrix *matrix, double start)
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
