#include "../include/header.h"

// static t_map	*ft_fill_A_node(t_map *node, char **informations)
// {
// 	double	ratio;

// 	if (!node || !informations || ft_array_length(informations) != 4)
// 		return (NULL);
// 	ratio = (double)ft_atoi(informations[0]);
// 	if (ratio < 0 || ratio > 1)
// 		return (NULL);
// 	node->ratio = ratio;
// 	node->color = ft_color_creator((double)ft_atoi(informations[1]),
// 		(double)ft_atoi(informations[2]), (double)ft_atoi(informations[3]));
// 	return (node);
// }

// void	ft_fill_nodes(t_map *node, char **informations)
// {
// 	if (!node || !informations)
// 		return ;
// 	if (!ft_strncmp(node->identifier, "A", ft_strlen(node->identifier)))
// 		node = ft_fill_A_node(node, informations);
// 	else if (!ft_strncmp(node->identifier, "L", ft_strlen(node->identifier)))
// 		node = ft_fill_L_node(node, informations);
// 	else if (!ft_strncmp(node->identifier, "C", ft_strlen(node->identifier)))
// 		node = ft_fill_C_node(node, informations);
// 	else if (!ft_strncmp(node->identifier, "sp", ft_strlen(node->identifier)))
// 		node = ft_fill_sp_node(node, informations);
// 	else if (!ft_strncmp(node->identifier, "pl", ft_strlen(node->identifier)))
// 		node = ft_fill_pl_node(node, informations);
// 	else
// 		node = ft_fill_cy_node(node, informations);
// }

static t_ambient	*ft_fill_A_struct(char *line)
{
	t_ambient	*ambient;
	char		**infos;

	if (!line)
		return (NULL);
	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 4)
		return (free(ambient), ft_free_array(infos), NULL);
	ambient->ratio = (double)ft_atoi(infos[0]);
	ambient->color = ft_color_creator((double)ft_atoi(infos[1]),
		(double)ft_atoi(infos[2]), (double)ft_atoi(infos[3]));
	if (!ambient->color)
		return (ft_free_ambient(ambient), NULL);
	return (ambient);
}

static char	*ft_extract_identifier(char *line, int *k)
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
	*k = j;
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

t_world	*ft_create_world(int fd)
{
	t_world	*world;
	char	*identifier;
	char	*line;
	int		k;

	world = ft_init_world();
	if (!world)
		return (NULL);
	k = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_empty_line(line))
			continue ;
		identifier = ft_extract_identifier(line, &k);
		if (!ft_strncmp(identifier, "A", ft_strlen(identifier)))
			world->ambient = ft_fill_A_struct(&line[k]);
		else if (!ft_strncmp(identifier, "C", ft_strlen(identifier)))
			world->camera = ft_fill_C_struct(world, &line[k]);
		else if (!ft_strncmp(identifier, "L", ft_strlen(identifier)))
			ft_fill_L_struct(world, &line[k]);
		else if (!ft_strncmp(identifier, "sp", ft_strlen(identifier)))
			ft_fill_sp_struct(world, &line[k]);
		else if (!ft_strncmp(identifier, "pl", ft_strlen(identifier)))
			ft_fill_pl_struct(world, &line[k]);
		else if (!ft_strncmp(identifier, "cy", ft_strlen(identifier)))
			ft_fill_cy_struct(world, &line[k]);
		free(line);
		if (!world)
			return (NULL);
		line = get_next_line(fd);
	}
	return (world);
}
