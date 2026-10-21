/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:43:56 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:43:58 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// int	ft_minirt(t_world *world, t_canvas *canvas)
// {
// 	t_tuple		*point;
// 	t_ray		*ray;
// 	t_tuple		*color;
// 	int			i;
// 	int			j;

// 	i = -1;
// 	while (++i < canvas->width)
// 	{
// 		j = -1;
// 		while (++j < canvas->height)
// 		{
// 			point = ft_from_pixel_to_point(world, canvas,
// 				&canvas->pixel_grid[i][j]);
// 			ray = ft_create_ray(world->camera->origin,
// 				ft_points_subtraction_normal(point, world->camera->normal));
				//dupliquer le 1er ?
// 			color = ft_get_color(world, ray);
// 			ft_write_pixel_color(canvas, i, j, color);
// 			free(point);
// 			free(ray);
// 			free(color);
// 		}
// 	}
// 	return (1);
// }
