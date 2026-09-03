#include "../include/header.h"

t_tuple	*ft_color_creator(double x, double y, double z)
{
	t_tuple	*color;

	if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1)
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
