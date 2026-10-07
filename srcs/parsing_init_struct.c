/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:29:00 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:29:02 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_world	*ft_init_world(void)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	world->canvas = NULL;
	world->ambient = NULL;
	world->camera = NULL;
	world->lights = NULL;
	world->spheres = NULL;
	world->planes = NULL;
	world->cylinders = NULL;
	return (world);
}

t_ambient	*ft_init_ambient(void)
{
	t_ambient	*ambient;

	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	ambient->color = NULL;
	return (ambient);
}

t_camera	*ft_init_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->origin = NULL;
	camera->normal = NULL;
	return (camera);
}
