#include "../include/header.h"

Test(canvas, color_creator)
{
	t_tuple *color = ft_color_creator(0, 1, 0.5);
	
	cr_assert_eq(color->x, 0);
	cr_assert_eq(color->y, 1);
	cr_assert_eq(color->z, 0.5);
	cr_assert_eq(color->w, -1);
}

Test(cavas, color_creator_bad_arguments)
{
	cr_assert_null(ft_color_creator(0, 1, 1.1));
	cr_assert_null(ft_color_creator(0, -1, 0.1));
	cr_assert_null(ft_color_creator(2, 1, 0.1));
}

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

Test(canvas, write_pixel_color_bad_arguments)
{
	int width = 5;
	int height = 4;

	t_canvas *canvas = ft_canvas_creator(width, height);
	t_tuple *color = ft_color_creator(0.02, 0.5, 1);

	ft_write_pixel_color(canvas, 2, -1, color);
	ft_write_pixel_color(canvas, -1, 3, color);
	ft_write_pixel_color(canvas, 5, 3, color);
	ft_write_pixel_color(canvas, 8, 3, color);
	ft_write_pixel_color(canvas, 3, 4, color);
	ft_write_pixel_color(canvas, 8, 3, color);
	
	ft_write_pixel_color(canvas, 0, 3, color);
	ft_write_pixel_color(canvas, 3, 0, color);
	ft_write_pixel_color(canvas, 0, 0, color);

	ft_write_pixel_color(NULL, 1, 1, color);
	ft_write_pixel_color(canvas, 1, 1, NULL);
	ft_write_pixel_color(NULL, 1, 1, NULL);
}

Test(canvas, get_pixel_color)
{
	int width = 5;
	int height = 4;
	
	int w = 3;
	int h = 2;

	t_tuple *color = ft_color_creator(1, 1, 0.2);
	t_canvas *canvas = ft_canvas_creator(width, height);
	
	ft_write_pixel_color(canvas, w, h, color);

	t_tuple *result = ft_get_pixel_color(canvas, w, h);

	cr_assert_eq(color->x, result->x);
	cr_assert_eq(color->y, result->y);
	cr_assert_eq(color->z, result->z);
	cr_assert_eq(color->w, result->w);
}

Test(canvas, get_pixel_color_bad_arguments)
{
	int width = 5;
	int height = 4;
	t_canvas *canvas = ft_canvas_creator(width, height);
	
	cr_assert_null(ft_get_pixel_color(canvas, 0, -1));
	cr_assert_null(ft_get_pixel_color(canvas, -1, 0));
	cr_assert_null(ft_get_pixel_color(canvas, -2, -3));
	
	cr_assert_null(ft_get_pixel_color(NULL, 0, 0));
}
