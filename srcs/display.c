/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:48:55 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:48:57 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// void	ft_display_matrix(t_matrix *matrix)
// {
// 	int	i = -1;
// 	int	j;

// 	while (++i < matrix->n)
// 	{
// 		j = -1;
// 		while (++j < matrix->n)
// 			printf("%f ", matrix->mtx[i][j]);
// 		printf("\n");
// 	}
// }

// void	ft_display_tuple(t_tuple *t)
// {
// 	if (!t)
// 		return ;
// 	printf("%f %f %f %f\n", t->x, t->y, t->z, t->w);
// }

static void	ft_display_cylinder(t_map *node)
{
	printf("CYLINDER:\n");
	if (!node->color)
	{
		printf("cylinder : color est NULL\n");
		return ;
	}
	printf("origin = %.1f, %.1f, %.1f\n", node->origin->x, node->origin->y,
		node->origin->z);
	printf("orientation = %.1f, %.1f, %.1f\n", node->normalized_orientation->x,
		node->normalized_orientation->y, node->normalized_orientation->z);
	printf("diameter = %.1f\n", node->diameter);
	printf("height = %.1f\n", node->height);
	printf("color = %.1f, %.1f, %.1f\n\n", node->color->x, node->color->y, node->color->z);
}

static void	ft_display_plane(t_map *node)
{
	printf("PLANE:\n");
	printf("orientation = %.1f, %.1f, %.1f\n", node->point->x,
		node->point->y, node->point->z);
	printf("orientation = %.1f, %.1f, %.1f\n", node->normalized_orientation->x,
		node->normalized_orientation->y, node->normalized_orientation->z);
	printf("color = %.1f, %.1f, %.1f\n\n", node->color->x, node->color->y, node->color->z);
}

static void	ft_display_sphere(t_map *node)
{
	printf("SPHERE:\n");
	printf("origin = %.1f, %.1f, %.1f\n", node->origin->x, node->origin->y,
		node->origin->z);
	printf("diameter = %.1f\n", node->diameter);
	printf("color = %.1f, %.1f, %.1f\n\n", node->color->x, node->color->y, node->color->z);
}

static void	ft_display_light(t_map *node)
{
	printf("LIGHT:\n");
	printf("origin = %.1f, %.1f, %.1f\n", node->origin->x, node->origin->y,
		node->origin->z);
	printf("lighting ratio = %.1f\n", node->ratio);
	printf("color = %.1f, %.1f, %.1f\n\n", node->color->x, node->color->y, node->color->z);
}

static void	ft_display_camera(t_map *node)
{
	printf("CAMERA:\n");
	printf("origin = %.1f, %.1f, %.1f\n", node->origin->x, node->origin->y,
		node->origin->z);
	printf("orientation = %.1f, %.1f, %.1f\n", node->normalized_orientation->x,
		node->normalized_orientation->y, node->normalized_orientation->z);
	printf("fov = %.1f\n\n", node->fov);
}

static void	ft_display_ambient(t_map *node)
{
	printf("AMBIENT:\n");
	printf("lighting ratio = %.1f\n", node->ratio);
	printf("color = %.1f, %.1f, %.1f\n\n", node->color->x, node->color->y, node->color->z);
}

void	ft_display_map(t_map *map)
{
	t_map	*tmp;

	if (!map)
	{
		printf("map est NULL\n");
		return ;
	}
	tmp = map;
	while (tmp)
	{
		if (!ft_strncmp(tmp->identifier, "A", ft_strlen(tmp->identifier)))
			ft_display_ambient(tmp);
		else if (!ft_strncmp(tmp->identifier, "C", ft_strlen(tmp->identifier)))
			ft_display_camera(tmp);
		else if (!ft_strncmp(tmp->identifier, "L", ft_strlen(tmp->identifier)))
			ft_display_light(tmp);
		else if (!ft_strncmp(tmp->identifier, "sp", ft_strlen(tmp->identifier)))
			ft_display_sphere(tmp);
		else if (!ft_strncmp(tmp->identifier, "pl", ft_strlen(tmp->identifier)))
			ft_display_plane(tmp);
		else if (!ft_strncmp(tmp->identifier, "cy", ft_strlen(tmp->identifier)))
			ft_display_cylinder(tmp);
		tmp = tmp->next;
	}
}
