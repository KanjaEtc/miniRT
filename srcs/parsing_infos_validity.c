/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_infos_validity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:28:24 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:28:26 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	ft_inter(double min, double max, char **infos, int count)
{
	int	i;
	int	j;
	int	nb;

	i = -1;
	if (!infos)
		return (0);
	while (infos[++i] && i < count)
	{
		j = -1;
		while (infos[i][++j])
		{
			if (!ft_isdigit(infos[i][j]) && infos[i][j] != '.')
				return (0);
		}
		nb = (double)ft_atoi(infos[i]);
		if (nb < min || nb > max)
			return (0);
	}
	return (1);
}

int	ft_check_infos_validity(char **infos, char *identifier)
{
	if (!infos || !*infos || !identifier)
		return (0);
	if (!ft_strncmp(identifier, "A", ft_strlen(identifier)))
		return (ft_inter(0, 1, infos, 1) && ft_inter(0, 255, &infos[1], 3));
	if (!ft_strncmp(identifier, "C", ft_strlen(identifier)))
		return (ft_inter(-1, 1, &infos[3], 3)
			&& ft_inter(0, 180, &infos[6], 1));
	if (!ft_strncmp(identifier, "L", ft_strlen(identifier)))
		return (ft_inter(0, 1, &infos[3], 1) && ft_inter(0, 255, &infos[4], 3));
	if (!ft_strncmp(identifier, "sp", ft_strlen(identifier)))
		return (ft_inter(0, 255, &infos[4], 3));
	if (!ft_strncmp(identifier, "pl", ft_strlen(identifier)))
		return (ft_inter(-1, 1, &infos[3], 3)
			&& ft_inter(0, 255, &infos[6], 3));
	if (!ft_strncmp(identifier, "cy", ft_strlen(identifier)))
		return (ft_inter(-1, 1, &infos[3], 3)
			&& ft_inter(0, 255, &infos[8], 3));
	return (0);
}
