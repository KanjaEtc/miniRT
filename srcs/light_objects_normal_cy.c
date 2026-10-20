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

static t_tuple	*ft_compute_projection(t_intersection *intersection)
{
	t_tuple	*projection;
	t_tuple	*tmp1;
	t_tuple	*tmp2;
	double	scalar;

	tmp1 = ft_tuples_subtraction(intersection->coordinates,
			intersection->object->coordinates);
	scalar = ft_dot_product(tmp1, intersection->object->axis);
	tmp2 = ft_vector_by_scalar_multiplication(intersection->object->axis,
			scalar);
	projection = ft_tuples_addition(intersection->object->coordinates, tmp2);
	free(tmp1);
	free(tmp2);
	return (projection);
}

static t_tuple	*ft_cy_surface_intersection_normal(t_intersection *intersection)
{
	t_tuple	*normal;
	t_tuple	*projection;
	t_tuple	*tmp;

	projection = ft_compute_projection(intersection);
	tmp = ft_tuples_subtraction(intersection->coordinates, projection);
	normal = ft_normalize(tmp);
	free(projection);
	free(tmp);
	return (normal);
}

static t_tuple	*ft_cy_cap_intersection_normal(t_intersection *intersection)
{
	if (intersection->object->bottom_cap)
		return (ft_tuple_opposite(intersection->object->axis));
	return (ft_vector_creator(intersection->object->axis->x,
			intersection->object->axis->y,
			intersection->object->axis->z));
}

static t_tuple	*ft_cylinder_intersection_normal(t_intersection *intersection)
{
	t_tuple	*normal;

	if (intersection->object->upper_cap)
		normal = ft_cy_cap_intersection_normal(intersection);
	else if (intersection->object->bottom_cap)
		normal = ft_cy_surface_intersection_normal(intersection);
	else
		normal = ft_cy_surface_intersection_normal(intersection);
	intersection->object->normal = normal;
	return (normal);
}

t_tuple	*ft_object_intersection_normal(t_intersection *intersection)
{
	if (!intersection)
		return (NULL);
	if (!ft_strncmp(intersection->object->identifier, "pl",
			ft_strlen(intersection->object->identifier)))
		return (intersection->object->normal);
	if (!ft_strncmp(intersection->object->identifier, "sp",
			ft_strlen(intersection->object->identifier)))
		return (ft_sphere_intersection_normal(intersection));
	if (!ft_strncmp(intersection->object->identifier, "cy",
			ft_strlen(intersection->object->identifier)))
		return (ft_cylinder_intersection_normal(intersection));
	return (NULL);
}
