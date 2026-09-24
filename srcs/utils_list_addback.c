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

void	ft_lights_addback(t_light **lights, t_light *new)
{
	t_light	*tmp;

	if (!lights || !new)
		return ;
	if (!*lights)
	{
		*lights = new;
		return ;
	}
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_spheres_addback(t_sphere **spheres, t_sphere *new)
{
	t_sphere	*tmp;

	if (!spheres || !new)
		return ;
	if (!*spheres)
	{
		*spheres = new;
		return ;
	}
	tmp = *spheres;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_planes_addback(t_plane **planes, t_plane *new)
{
	t_plane	*tmp;

	if (!planes || !new)
		return ;
	if (!*planes)
	{
		*planes = new;
		return ;
	}
	tmp = *planes;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_cylinders_addback(t_cylinder **cylinders, t_cylinder *new)
{
	t_cylinder	*tmp;

	if (!cylinders || !new)
		return ;
	if (!*cylinders)
	{
		*cylinders = new;
		return ;
	}
	tmp = *cylinders;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
