/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:27:01 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:27:04 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc != 2)
		return (1);
	world = ft_parser(argv[1]);
	if (!world)
		return (1);
	ft_display_world(world);
	ft_free_world(world);
}
