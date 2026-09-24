/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:45:02 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:45:03 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	*ft_free_world(t_world *world)
{
	if (!world)
		return (NULL);
	ft_free_ambient(world->ambient);
	ft_free_camera(world->camera);
	ft_lights_list_clear(&world->lights);
	ft_spheres_list_clear(&world->spheres);
	ft_planes_list_clear(&world->planes);
	ft_cylinders_list_clear(&world->cylinders);
	free(world);
	return (NULL);
}

void	ft_free_ambient(t_ambient *ambient)
{
	if (ambient && ambient->color)
		free(ambient->color);
	free(ambient);
}

void	ft_free_camera(t_camera *camera)
{
	if (!camera)
		return ;
	free(camera->origin);
	free(camera->normal);
	free(camera);
}

