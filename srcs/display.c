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

static void	ft_display_cylinders(t_cylinder *cylinder)
{
	t_cylinder	*tmp;

	tmp = cylinder;
	printf("CYLINDER:\n");
	while (tmp)
	{
		if (!tmp->axis)
		{
			printf("cylinder : axis est NULL\n\n");
			return ;
		}
		if (!tmp->center)
		{
			printf("cylinder : center est NULL\n\n");
			return ;
		}
		if (!tmp->color)
		{
			printf("cylinder : color est NULL\n\n");
			return ;
		}
		printf("center = %.1f, %.1f, %.1f\n", tmp->center->x, tmp->center->y,
			tmp->center->z);
		printf("axis = %.1f, %.1f, %.1f\n", tmp->axis->x,
			tmp->axis->y, tmp->axis->z);
			printf("diameter = %.1f\n", tmp->diameter);
		printf("height = %.1f\n", tmp->height);
		printf("color = %.1f, %.1f, %.1f\n\n", tmp->color->x,
			tmp->color->y, tmp->color->z);
		tmp = tmp->next;
	}
}

static void	ft_display_planes(t_plane *planes)
{
	t_plane	*tmp;

	tmp = planes;
	printf("PLANE:\n");
	while (tmp)
	{
		if (!tmp->point)
		{
			printf("plane : point est NULL\n\n");
			return ;
		}
		if (!tmp->normal)
		{
			printf("plane : normal est NULL\n\n");
			return ;
		}
		if (!tmp->color)
		{
			printf("plane : color est NULL\n\n");
			return ;
		}
		printf("point = %.1f, %.1f, %.1f\n", tmp->point->x,
			tmp->point->y, tmp->point->z);
		printf("normal = %.1f, %.1f, %.1f\n", tmp->normal->x,
			tmp->normal->y, tmp->normal->z);
		printf("color = %.1f, %.1f, %.1f\n\n", tmp->color->x,
			tmp->color->y, tmp->color->z);
		tmp = tmp->next;
	}
}

static void	ft_display_spheres(t_sphere *spheres)
{
	t_sphere	*tmp;

	tmp = spheres;
	printf("SPHERE:\n");
	if (!tmp->center)
	{
		printf("sphere : center est NULL\n\n");
		return ;
	}
	if (!tmp->color)
	{
		printf("sphere : color est NULL\n\n");
		return ;
	}
	while (tmp)
	{
		printf("center = %.1f, %.1f, %.1f\n", tmp->center->x, tmp->center->y,
			tmp->center->z);
		printf("diameter = %.1f\n", tmp->diameter);
		printf("color = %.1f, %.1f, %.1f\n\n", tmp->color->x,
			tmp->color->y, tmp->color->z);
		tmp = tmp->next;
	}
}

static void	ft_display_lights(t_light *lights)
{
	t_light	*tmp;

	tmp = lights;
	printf("LIGHT:\n");
	if (!tmp->origin)
	{
		printf("light : origin est NULL\n\n");
		return ;
	}
	if (!tmp->color)
	{
		printf("light : color est NULL\n\n");
		return ;
	}
	while (tmp)
	{
		printf("origin = %.1f, %.1f, %.1f\n", tmp->origin->x,
			tmp->origin->y, tmp->origin->z);
		printf("ratio = %.1f\n", tmp->ratio);
		printf("color = %.1f, %.1f, %.1f\n\n", tmp->color->x,
			tmp->color->y, tmp->color->z);
		tmp = tmp->next;
	}
}

static void	ft_display_camera(t_camera *camera)
{
	printf("CAMERA:\n");
	if (!camera->origin)
	{
		printf("camera : origin est NULL\n\n");
		return ;
	}
	if (!camera->normal)
	{
		printf("camera : normal est NULL\n\n");
		return ;
	}
	printf("origin = %.1f, %.1f, %.1f\n", camera->origin->x, camera->origin->y,
		camera->origin->z);
	printf("normal = %.1f, %.1f, %.1f\n", camera->normal->x,
		camera->normal->y, camera->normal->z);
	printf("fov = %.1f\n\n", camera->fov);
}

static void	ft_display_ambient(t_ambient *ambient)
{
	printf("AMBIENT:\n");
	if (!ambient->color)
	{
		printf("ambient : color est null\n\n");
		return ;
	}
	printf("ratio = %.1f\n", ambient->ratio);
	printf("color = %.1f, %.1f, %.1f\n\n", ambient->color->x,
		ambient->color->y, ambient->color->z);
}

void	ft_display_world(t_world *world)
{
	if (!world)
	{
		printf("world est null\n");
		return ;
	}
	if (world->ambient)
		ft_display_ambient(world->ambient);
	if (world->camera)
		ft_display_camera(world->camera);
	if (world->lights)
		ft_display_lights(world->lights);
	if (world->spheres)
		ft_display_spheres(world->spheres);
	if (world->planes)
		ft_display_planes(world->planes);
	if (world->cylinders)
		ft_display_cylinders(world->cylinders);
}
