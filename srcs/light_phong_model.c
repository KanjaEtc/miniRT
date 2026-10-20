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

t_tuple	*ft_compute_spec(t_world *world, t_intersection *intersection)
{
	t_tuple	*light_object_normal;
	t_tuple	*camera_object_normal;
	t_tuple	*reflect_v;
	double	factor;

	light_object_normal = ft_points_subtraction_normal(
			intersection->coordinates, world->lights->origin);
	reflect_v = ft_reflect(light_object_normal,
			intersection->object->normal);
	camera_object_normal = ft_points_subtraction_normal(
			world->camera->origin, intersection->coordinates);
	factor = ft_dot_product(camera_object_normal, reflect_v);
	if (!factor <= 0)
		return (ft_color_creator(0, 0, 0));
	factor = pow(factor, 32);
	factor *= world->lights->ratio;
	free(light_object_normal);
	free(camera_object_normal);
	free(reflect_v);
	return (ft_vector_by_scalar_multiplication(world->lights->color, factor));
}

t_tuple	*ft_compute_diff(t_world *world, t_intersection *intersection)
{
	t_tuple	*diff;
	t_tuple	*tmp;
	t_tuple	*light_normal_at_intersection;
	t_tuple	*object_normal_at_intersection;
	double	intensity;

	light_normal_at_intersection = ft_tuples_subtraction(
			world->lights->origin, intersection->coordinates);
	object_normal_at_intersection = ft_object_intersection_normal(
			intersection);
	intensity = max(0, ft_dot_product(intersection->object->normal,
				object_normal_at_intersection)) * world->lights->ratio;
	tmp = ft_colors_multiplication(intersection->color, world->lights->color);
	diff = ft_color_by_ratio_multiplication(tmp, intensity);
	free(light_normal_at_intersection);
	free(object_normal_at_intersection);
	free(tmp);
	return (diff);
}

t_tuple	*ft_compute_amb(t_world *world, t_object *object)
{
	t_tuple	*amb;
	t_tuple	*tmp;

	tmp = ft_colors_multiplication(world->ambient->color, object->color);
	amb = ft_color_by_ratio_multiplication(tmp, world->ambient->ratio);
	free(tmp);
	return (amb);
}
