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

static t_tuple	*ft_compute_right_vector(t_tuple *camera_normal)
{
	t_tuple	*right;
	t_tuple	*vertical;
	t_tuple	*tmp;
	t_tuple	*null_vector;
	t_tuple	*tmp_cross_forward;

	vertical = ft_vector_creator(0, 1, 0);
	tmp = ft_cross_product(vertical, camera_normal);
	null_vector = ft_vector_creator(0, 0, 0);
	if (ft_vectors_equality(tmp, null_vector))
	{
		free(tmp);
		tmp = ft_vector_creator(0, 0, 1);
	}
	tmp_cross_forward = ft_cross_product(tmp, camera_normal);
	right = ft_normalize(tmp_cross_forward);
	return (free(vertical), free(tmp), free(null_vector),
		free(tmp_cross_forward), right);
}

static double	ft_ypoint_equivalent_to_pixel(t_world *world, t_canvas *canvas,
	t_tuple *pixel)
{
	double	radians_fov;
	double	h;

	radians_fov = world->camera->fov * 3.141592 / 180;
	h = 2 * tan(radians_fov / 2);
	return ((0.5 - (pixel->y + 0.5) / canvas->height) * h);
}

static double	ft_xpoint_equivalent_to_pixel(t_world *world, t_canvas *canvas,
	t_tuple *pixel)
{
	double	radians_fov;
	double	h;
	double	ratio;
	double	w;

	radians_fov = world->camera->fov * 3.141592 / 180;
	h = 2 * tan(radians_fov / 2);
	ratio = canvas->width / canvas->height;
	w = h * ratio;
	return (((pixel->x + 0.5) / canvas->width - 0.5) * w);
}

t_tuple	*ft_from_pixel_to_point(t_world *world, t_canvas *canvas,
	t_tuple *pixel)
{
	t_tuple	*point;
	t_tuple	*right;
	t_tuple	*up;
	double	x;
	double	y;

	if (!world || !pixel)
		return (NULL);
	x = ft_xpoint_equivalent_to_pixel(world, canvas, pixel);
	y = ft_ypoint_equivalent_to_pixel(world, canvas, pixel);
	right = ft_compute_right_vector(world->camera->normal);
	up = ft_cross_product(world->camera->normal, right);
	point = ft_compute_point_first_part(right, up, x, y);
	point = ft_compute_point_second_part(world, point);
	return (free(right), free(up), point);
}
