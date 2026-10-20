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

/* Not tested */
bool	ft_is_a_color(t_tuple *color)
{
	return (color && color->w == -1);
}

/* Not tested */
t_tuple	*ft_colors_addition(t_tuple *c1, t_tuple *c2)
{
	if (!ft_is_a_color(c1) || !ft_is_a_color(c2))
		return (NULL);
	return (ft_color_creator(c1->x + c2->x, c1->y + c2->y, c1->z + c2->z));
}

/* Not tested */
t_tuple	*ft_colors_multiplication(t_tuple *c1, t_tuple *c2)
{
	if (!ft_is_a_color(c1) || !ft_is_a_color(c2))
		return (NULL);
	return (ft_color_creator(c1->x * c2->x, c1->y * c2->y, c1->z * c2->z));
}

/* Not tested */
t_tuple	*ft_color_by_ratio_multiplication(t_tuple *color, double ratio)
{
	if (!ft_is_a_color(color) || ratio < 0 || ratio > 1)
		return (NULL);
	return (ft_color_creator(color->x * ratio,
			color->y * ratio,
			color->z * ratio));
}
