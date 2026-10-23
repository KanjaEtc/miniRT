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

static t_intersection	*ft_closer_intersection(t_intersection *i1, t_intersection *i2,
	t_intersection *i3)
{
	double	min;
	int		closer;

	min = -1;
	closer = 1;
	if (i1)
		min = i1->distance_to_camera;
	if (i2 && i2->distance_to_camera < min)
	{
		min = i2->distance_to_camera;
		closer = 2;
	}
	if (i3 && i3->distance_to_camera < min)
	{
		min = i3->distance_to_camera;
		closer = 3;
	}
	if (min < 0)
		return (NULL);
	if (closer == 1)
		return (ft_free_intersection(i2), ft_free_intersection(i3), i1);
	if (closer == 2)
		return (ft_free_intersection(i1), ft_free_intersection(i3), i2);
	return (ft_free_intersection(i1), ft_free_intersection(i1), i3);
}

t_intersection	*ft_intersection(t_world *world, t_ray *ray)
{
	t_intersection	*pl_intersection;
	t_intersection	*sp_intersection;
	t_intersection	*cy_intersection;
	double			distance;
	double			min;

	if (!world || !ray)
		return (NULL);
	pl_intersection = ft_ray_plane_intersection(world, ray);
	sp_intersection = ft_ray_sphere_intersection(world, ray);
	cy_intersection = ft_ray_cylinder_intersection(world, ray);
	return (ft_closer_intersection(pl_intersection, sp_intersection,
		cy_intersection));
}
