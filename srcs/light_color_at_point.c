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

/* No function tested */

static t_tuple	*ft_color_at_object_point(t_world *world,
	t_intersection *intersection)
{
	t_tuple	*amb;
	t_tuple	*diff;
	t_tuple	*spec;
	t_tuple	*amb_and_diff;
	t_tuple	*color_at_point;

	amb = ft_compute_amb(world, intersection->object);
	diff = ft_compute_diff(world, intersection);
	spec = ft_compute_spec(world, intersection->object);
	amb_and_diff = ft_colors_addition(amb, diff);
	color_at_point = ft_colors_addition(amb_and_diff, spec);
	free(amb);
	free(diff);
	free(spec);
	free(amb_and_diff);
	return (color_at_point);
}

t_tuple	*ft_color_at_a_point(t_world *world, t_intersection *intersection)
{
	if (!world || !intersection)
		return (NULL);
	if (intersection->object)
		return (ft_color_at_object_point(world, intersection));
	return (ft_color_by_ratio_multiplication(world->ambient->color,
			world->ambient->ratio));
	return (ft_color_at_background_point(world, intersection));
}
