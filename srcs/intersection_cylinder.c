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

// - a = D.D - (D.A)²
// - b = 2[(O - Q).D - ((O - Q).A)(D.A)]
// - c = (O - Q).(O - Q) - ((O - Q).A)² - R²

t_intersection	*ft_check_cylinder_intersection(t_world *world, t_ray *ray,
	t_cylinder *cylinder)
{
	t_tuple	*tmp_vector;
	double	a;
	double	b;
	double	c;
	double	t;

	a = ft_dot_product(ray->direction, ray->direction)
		- pow(ft_dot_product(ray->direction, cylinder->axis), 2);
	if (!a)
		return (NULL); //0 ou une infinite de solutions
	tmp_vector = ft_tuples_subtraction(ray->origin, cylinder->center);
	b = ft_dot_product(tmp_vector, ray->direction)
		- ft_dot_product(tmp_vector, cylinder->axis)
		* ft_dot_product(ray->direction, cylinder->axis);
	b *= 2;
	c = ft_dot_product(tmp_vector, tmp_vector)
		- pow(ft_dot_product(tmp_vector, cylinder->axis), 2)
		- pow(cylinder->diameter / 2, 2);
	free(tmp_vector);
	t = ft_solve_quadratic_equation(a, b, c);
	if (t < 0)
		return (NULL);
	return (ft_finite_cylinder_intersection(world, ray, cylinder, t));
}

t_intersection	*ft_ray_cylinder_intersection(t_world *world, t_ray *ray)
{
	t_cylinder		*tmp_cylinder;
	t_intersection	*intersection;
	t_intersection	*tmp_intersection;
	double			min_distance;

	intersection = NULL;
	min_distance = -1;
	tmp_cylinder = world->cylinders;
	while (tmp_cylinder)
	{
		tmp_intersection = ft_check_cylinder_intersection(world, ray,
			tmp_cylinder);
		if (tmp_intersection && tmp_intersection->distance_to_camera < min_distance)
		{
			min_distance = tmp_intersection->distance_to_camera;
			ft_free_intersection(intersection);
			intersection = tmp_intersection;
		}
		free(tmp_intersection);
		tmp_cylinder = tmp_cylinder->next;
	}
}
