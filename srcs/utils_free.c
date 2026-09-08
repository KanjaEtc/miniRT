/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:45:02 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:45:03 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	*ft_free_tuple_array(t_tuple **array, int index)
{
	int	i;

	i = -1;
	while (array && ++i < index)
		free(array[i]);
	free(array);
	return (NULL);
}

void	*ft_free_double_array(double **array, int index)
{
	int	i;

	i = -1;
	while (array && ++i < index)
		free(array[i]);
	free(array);
	return (NULL);
}

void	*ft_free_matrix(t_matrix *m)
{
	if (!m)
		return (NULL);
	ft_free_double_array(m->mtx, m->n);
	free(m);
	return (NULL);
}
