/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:29:29 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:29:30 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// t_ray	*ft_ray_creator(t_tuple *origin, t_tuple *direction)
// {
// 	t_ray	*ray;

// 	if (!ft_is_a_point(origin) || !ft_is_a_vector(direction))
// 		return (NULL);
// 	ray = malloc(sizeof(t_ray));
// 	if (!ray)
// 		return (NULL);
// 	ray->origin = origin;
// 	ray->direction = direction;
// 	return (ray);
// }

// t_tuple	*ft_point_position(t_ray *ray, double t)
// {
// 	t_tuple	*point;
// 	t_tuple	*result;

// 	if (!ray)
// 		return (NULL);
// 	point = ft_vector_by_scalar_multiplication(ray->direction, t);
// 	if (!point)
// 		return (NULL);
// 	result = ft_point_creator(ray->origin->x + point->x,
// 		ray->origin->y + point->y, ray->origin->z + point->z);
// 	free(point);
// 	return (result);		
// }
