/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:43:45 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:43:47 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	det = ft_matrix_determinant(m);
	if (!det)
		return (NULL);
	inverse = ft_matrix_creator(m->n);
	sign = 1;
	row = -1;
	while (inverse && ++row < m->n)
	{
		col = -1;
		while (++col < m->n)
		{
			inverse->mtx[col][row] = sign * (ft_matrix_determinant(
						ft_submatrix(m, row, col)) / det);
			sign = -sign;
		}
		sign = -sign;
	}
	return (inverse);
}
