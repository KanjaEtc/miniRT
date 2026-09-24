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

void	ft_lights_list_clear(t_light **lights)
{
	t_light	*tmp;

	if (!lights || !*lights)
		return ;
	while (*lights)
	{
		tmp = (*lights)->next;
		free((*lights)->origin);
		free((*lights)->color);
		free(*lights);
		*lights = tmp;
	}
	*lights = NULL;
}

void	ft_spheres_list_clear(t_sphere **spheres)
{
	t_sphere	*tmp;

	if (!spheres || !*spheres)
		return ;
	while (*spheres)
	{
		tmp = (*spheres)->next;
		free((*spheres)->center);
		free((*spheres)->color);
		free(*spheres);
		*spheres = tmp;
	}
	*spheres = NULL;
}

void	ft_planes_list_clear(t_plane **planes)
{
	t_plane	*tmp;

	if (!planes || !*planes)
		return ;
	while (*planes)
	{
		tmp = (*planes)->next;
		free((*planes)->point);
		free((*planes)->normal);
		free((*planes)->color);
		free(*planes);
		*planes = tmp;
	}
	*planes = NULL;
}

void	ft_cylinders_list_clear(t_cylinder **cylinders)
{
	t_cylinder	*tmp;

	if (!cylinders || !*cylinders)
		return ;
	while (*cylinders)
	{
		tmp = (*cylinders)->next;
		free((*cylinders)->center);
		free((*cylinders)->axis);
		free((*cylinders)->color);
		free(*cylinders);
		*cylinders = tmp;
	}
	*cylinders = NULL;
}
