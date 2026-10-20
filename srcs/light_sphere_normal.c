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

/* Which of these two functions should we use ? */
/* None of them have been tested*/

t_tuple	*ft_normal_at_sphere_point(t_sphere *sphere, t_matrix *transform,
	t_tuple *world_point)
{
	t_tuple	*world_vector;
	t_tuple	*object_point;
	t_tuple	*object_normal;
	t_tuple	*world_normal;

	if (!ft_is_matrix_invertible(transform))
		return (NULL);
	object_point = ft_matrix_by_tuple_multiplication(
			ft_inverse(transform), world_point);
	object_point->w = 1;
	object_normal = ft_tuples_subtraction(object_point, sphere->center);
	world_vector = ft_matrix_by_tuple_multiplication(ft_transpose_matrix(
				ft_inverse(transform)), object_normal);
	world_vector->w = 0;
	world_normal = ft_normalize(world_vector);
	return (free(object_point), free(object_normal), free(world_vector),
		world_normal);
}

t_tuple	*ft_sphere_intersection_normal(t_intersection *intersection)
{
	t_tuple	*normal;
	t_tuple	*tmp1;
	t_tuple	*tmp2;

	tmp1 = ft_tuples_subtraction(intersection->coordinates,
			intersection->object->coordinates);
	tmp2 = ft_vector_by_scalar_division(tmp1, intersection->object->radius);
	normal = ft_normalize(tmp2);
	intersection->object->normal = normal;
	free(tmp1);
	free(tmp2);
	return (normal);
}
