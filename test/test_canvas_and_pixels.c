#include "../include/header.h"
# include <criterion/criterion.h>

Test(canvas, canvas_creation)
{
	int width = 5;
	int height = 4;
	t_canvas *canvas = ft_canvas_creator(width, height);
	
	cr_assert_eq(canvas->width, width);
	cr_assert_eq(canvas->height, height);
	
	for (int i = 0 ; i < width ; i++)
	{
		for (int j = 0 ; j < height ; j++)
		{
			cr_assert_eq(canvas->pixel_grid[i][j].x, 0);
			cr_assert_eq(canvas->pixel_grid[i][j].y, 0);
			cr_assert_eq(canvas->pixel_grid[i][j].z, 0);
			cr_assert_eq(canvas->pixel_grid[i][j].w, -1);
		}
	}
}

Test(canvas, canvas_creation_bad_arguments)
{
	int width = -1;
	int height = 0;
	cr_assert_null(ft_canvas_creator(width, height));
}

Test(canvas, write_pixel_color)
{
	int width = 5;
	int height = 4;
	int w = 3;
	int h = 1;
	t_canvas *canvas = ft_canvas_creator(width, height);
	t_tuple *color = ft_color_creator(0.02, 0.5, 1);

	ft_write_pixel_color(canvas, w, h, color);
	cr_assert_eq(canvas->pixel_grid[w][h].x, 0.02);
	cr_assert_eq(canvas->pixel_grid[w][h].y, 0.5);
	cr_assert_eq(canvas->pixel_grid[w][h].z, 1);
	cr_assert_eq(canvas->pixel_grid[w][h].w, -1);
}
