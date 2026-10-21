/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:43:09 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:43:13 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	*ft_compute_point_second_part(t_world *world, t_tuple *first_part)
{
	t_tuple	*point;
	t_tuple	*tmp;

	tmp = ft_tuples_addition(first_part, world->camera->normal);
	point = ft_tuples_addition(world->camera->origin, tmp);
	free(first_part);
	free(tmp);
	return (point);
}

t_tuple	*ft_compute_point_first_part(t_tuple *right, t_tuple *up,
	double x, double y)
{
	t_tuple	*first_part;
	t_tuple	*right_by_x;
	t_tuple	*up_by_y;

	right_by_x = ft_vector_by_scalar_multiplication(right, x);
	up_by_y = ft_vector_by_scalar_multiplication(up, y);
	first_part = ft_tuples_addition(right_by_x, up_by_y);
	return (free(right_by_x), free(up_by_y), first_part);
}
