/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_and_pixels.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:42:57 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:43:03 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	**ft_pixel_grid_allocator(int width, int height)
{
	t_tuple		**pixel_grid;
	int			i;

	pixel_grid = malloc(sizeof(t_tuple *) * width);
	if (!pixel_grid)
		return (NULL);
	i = -1;
	while (++i < width)
	{
		pixel_grid[i] = malloc(sizeof(t_tuple) * height);
		if (!pixel_grid[i])
			return (ft_free_tuple_array(pixel_grid, i), NULL);
	}
	return (pixel_grid);
}

t_canvas	*ft_canvas_creator(int width, int height)
{
	t_canvas	*canvas;
	int			i;
	int			j;

	if (width < 0 || height < 0)
		return (NULL);
	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->pixel_grid = ft_pixel_grid_allocator(width, height);
	if (!canvas)
		return (NULL);
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			canvas->pixel_grid[i][j].x = 0;
			canvas->pixel_grid[i][j].y = 0;
			canvas->pixel_grid[i][j].z = 0;
			canvas->pixel_grid[i][j].w = -1;
		}
	}
	return (canvas->width = width, canvas->height = height, canvas);
}
