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

t_tuple	*ft_color_creator(double x, double y, double z)
{
	t_tuple	*color;

	if (x < 0 || x > 255 || y < 0 || y > 255 || z < 0 || z > 255)
		return (NULL);
	color = malloc(sizeof(t_tuple));
	if (!color)
		return (NULL);
	color->x = x;
	color->y = y;
	color->z = z;
	color->w = -1;
	return (color);
}

t_tuple	*ft_get_pixel_color(t_canvas *canvas, int w, int h)
{
	if (!canvas || !canvas->pixel_grid || !*canvas->pixel_grid)
		return (NULL);
	if (w >= canvas->width || w < 0 || h >= canvas->height || h < 0)
		return (NULL);
	return (ft_color_creator(canvas->pixel_grid[w][h].x,
		canvas->pixel_grid[w][h].y,
		canvas->pixel_grid[w][h].z));
}

void	ft_write_pixel_color(t_canvas *canvas, int w, int h, t_tuple *color)
{
	if (!canvas || !canvas->pixel_grid || !*canvas->pixel_grid || !color)
		return ;
	if (w >= canvas->width || w < 0 || h >= canvas->height || h < 0)
		return ;
	canvas->pixel_grid[w][h].x = color->x;
	canvas->pixel_grid[w][h].y = color->y;
	canvas->pixel_grid[w][h].z = color->z;
	canvas->pixel_grid[w][h].w = color->w;
}
