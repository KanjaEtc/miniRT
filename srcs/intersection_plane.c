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

	// 	Pour trouver le point d'intersection P(t) :

	// 					t = (Q - O).N / D.N
	// Ou :
	// - Q est un point appartenant au plan (donne dans la map)
	// - O = coordonnees de l'origine du rayon
	// - n = vecteur normal du plan (donne dans la map)
	// - D = vecteur directeur du rayon

t_tuple	*ft_find_point_coordinates(t_ray *ray, double distance)
{
	t_tuple	*tmp_vector;
	t_tuple	*point;

	tmp_vector = ft_vector_by_scalar_multiplication(ray->direction, distance);
	point = ft_tuples_addition(ray->origin, tmp_vector);
	free(tmp_vector);
	return (point);
}

t_intersection	*ft_check_plane_intersection(t_world *world, t_ray *ray,
	t_plane *plane)
{
	t_intersection	*intersection;
	t_tuple	*point;
	t_tuple	*plane_random_vector;
	double	scalar;
	double	distance;

	scalar = ft_dot_product(ray->direction, plane->next);
	if (!scalar)
		return (NULL);
	plane_random_vector = ft_tuples_subtraction(plane->point, ray->origin);
	distance = ft_dot_product(plane_random_vector, plane->normal) / scalar;
	free(plane_random_vector);
	if (distance < 0)
		return (NULL);
	if (distance == 0) //epsilon
		return (ft_handle_null_distance());
	point = ft_find_point_coordinates(ray, distance);
	intersection = ft_from_point_to_intersection(ray, point);
	return (intersection);
}

t_intersection	*ft_ray_planes_intersection(t_world *world, t_ray *ray)
{
	t_intersection	*intersection;
	t_intersection	*tmp_intersection;
	t_plane	*tmp_plane;
	double	min_distance;

	intersection = NULL;
	min_distance = -1;
	tmp_plane = world->planes;
	while (tmp_plane)
	{
		tmp_intersection = ft_check_plane_intersection(world, ray, tmp_plane);
		if (tmp_intersection && tmp_intersection->distance_to_camera < min_distance)
		{
			min_distance = tmp_intersection->distance_to_camera;
			ft_free_intersection(intersection);
			intersection = tmp_intersection;
		}
		free(tmp_intersection);
		tmp_plane = tmp_plane->next;
	}
	return (intersection);
}
