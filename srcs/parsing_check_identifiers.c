/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_identifiers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:27:36 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:27:38 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_check_mandatory_identifiers(t_world *world)
{
	if (!world)
		return (0);
	return (world->ambient != NULL
		&& world->camera != NULL
		&& world->lights != NULL);
}
