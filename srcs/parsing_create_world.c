/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_create_world.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:27:53 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:27:55 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_ambient	*ft_fill_a_struct(char *line)
{
	t_ambient	*ambient;
	char		**infos;

	if (!line)
		return (NULL);
	ambient = ft_init_ambient();
	if (!ambient)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 4
		|| !ft_check_infos_validity(infos, "A"))
		return (ft_free_ambient(ambient), ft_free_array(infos), NULL);
	ambient->ratio = ft_atoi(infos[0]);
	ambient->color = ft_color_creator(ft_atoi(infos[1]),
			ft_atoi(infos[2]), ft_atoi(infos[3]));
	ft_free_array(infos);
	if (!ambient->color)
		return (ft_free_ambient(ambient), NULL);
	return (ambient);
}

static char	*ft_extract_identifier(char *line)
{
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (!ft_isspace(line[j]))
		j++;
	return (ft_substr(line, i, j - i));
}

static int	ft_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = -1;
	while (line[++i])
	{
		if (!ft_isspace(line[i]))
			return (0);
	}
	return (1);
}

static int	ft_fill_world(t_world *world, char *line, char *identifier)
{
	int	start;

	start = (int)ft_strlen(identifier);
	if (!ft_strncmp(identifier, "A", ft_strlen(identifier))
		&& !world->ambient)
		return (world->ambient = ft_fill_a_struct(&line[start]),
			world->ambient != NULL);
	if (!ft_strncmp(identifier, "C", ft_strlen(identifier))
		&& !world->camera)
		return (world->camera = ft_fill_c_struct(&line[start]),
			world->camera != NULL);
	if (!ft_strncmp(identifier, "L", ft_strlen(identifier)))
		return (ft_l_addback(&world->lights, ft_fill_l_struct(&line[start])),
			world->lights != NULL);
	if (!ft_strncmp(identifier, "sp", ft_strlen(identifier)))
		return (ft_sp_addback(&world->spheres, ft_fill_sp_struct(&line[start])),
			world->spheres != NULL);
	if (!ft_strncmp(identifier, "pl", ft_strlen(identifier)))
		return (ft_pl_addback(&world->planes, ft_fill_pl_struct(&line[start])),
			world->planes != NULL);
	if (!ft_strncmp(identifier, "cy", ft_strlen(identifier)))
		return (ft_cy_addback(&world->cylinders,
				ft_fill_cy_struct(&line[start])), world->cylinders != NULL);
	return (printf("Error: bad identifier\n"), 0);
}

t_world	*ft_create_world(int fd)
{
	t_world	*world;
	char	*line;
	char	*identifier;

	world = ft_init_world();
	if (!world)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_empty_line(line))
		{
			identifier = ft_extract_identifier(line);
			if (!ft_fill_world(world, line, identifier))
				return (free(line), free(identifier), ft_clean_gnl(fd),
					ft_free_world(world));
			free(identifier);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!ft_check_mandatory_identifiers(world))
		return (printf("Error: identifiers missing\n"), ft_free_world(world));
	return (world);
}
