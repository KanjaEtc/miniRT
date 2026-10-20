#include "../include/header.h"
# include <criterion/criterion.h>

Test(canvas, color_creator)
{
	t_tuple *color = ft_color_creator(0, 01, +0.5);
	
	cr_assert_eq(color->x, 0);
	cr_assert_eq(color->y, 1);
	cr_assert_eq(color->z, 0.5);
	cr_assert_eq(color->w, -1);
}

Test(cavas, color_creator_bad_arguments)
{
	cr_assert_null(ft_color_creator(0, 01111, -1.8));
	cr_assert_null(ft_color_creator(0, -1, 0));
	cr_assert_null(ft_color_creator(280, 1, 0));
}
