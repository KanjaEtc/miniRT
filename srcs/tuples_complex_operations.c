/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_complex_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:44:38 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:44:39 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

double	ft_dot_product(t_tuple *v1, t_tuple *v2)
{
	if (!v1 || !v2 || !ft_is_a_vector(v1) || !ft_is_a_vector(v2))
		return (0);
	return (v1->x * v2->x
		+ v1->y * v2->y
		+ v1->z * v2->z);
}

t_tuple	*ft_normalize(t_tuple *vector)
{
	t_tuple	*normal;
	double	len;

	if (!vector || !ft_is_a_vector(vector))
		return (NULL);
	len = ft_vector_length(vector);
	if (len == 0)
		return (NULL);
	normal = malloc(sizeof(t_tuple));
	if (!normal)
		return (NULL);
	normal->x = vector->x / len;
	normal->y = vector->y / len;
	normal->z = vector->z / len;
	normal->w = 0;
	return (normal);
}

/* Not tested */
t_tuple	*ft_points_subtraction_normal(t_tuple *p1, t_tuple *p2)
{
	t_tuple	*normal;
	t_tuple	*not_normalized;

	if (!p1 || !p2 || !ft_is_a_point(p1) || !ft_is_a_point(p2))
		return (NULL);
	not_normalized = ft_tuples_subtraction(p1, p2);
	normal = ft_normalize(not_normalized);
	free(not_normalized);
	return (normal);
}

double	ft_vector_length(t_tuple *v)
{
	if (!v || !ft_is_a_vector(v))
		return (0);
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}

t_tuple	*ft_cross_product(t_tuple *v1, t_tuple *v2)
{
	t_tuple	*result;

	if (!v1 || !v2 || !ft_is_a_vector(v1) || !ft_is_a_vector(v2))
		return (NULL);
	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	result->x = v1->y * v2->z - v1->z * v2->y;
	result->y = v1->z * v2->x - v1->x * v2->z;
	result->z = v1->x * v2->y - v1->y * v2->x;
	result->w = 0;
	return (result);
}
