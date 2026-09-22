#include "../include/header.h"

static t_map	*ft_fill_A_node(t_map *node, char **informations)
{
	double	ratio;

	if (!node || !informations || ft_array_length(informations) != 4)
		return (NULL);
	ratio = (double)ft_atoi(informations[0]);
	if (ratio < 0 || ratio > 1)
		return (NULL);
	node->ratio = ratio;
	node->color = ft_color_creator((double)ft_atoi(informations[1]),
		(double)ft_atoi(informations[2]), (double)ft_atoi(informations[3]));
	return (node);
}

static void	ft_fill_nodes(t_map *node, char **informations)
{
	if (!node || !informations)
		return ;
	if (!ft_strncmp(node->identifier, "A", ft_strlen(node->identifier)))
		node = ft_fill_A_node(node, informations);
	else if (!ft_strncmp(node->identifier, "L", ft_strlen(node->identifier)))
		node = ft_fill_L_node(node, informations);
	else if (!ft_strncmp(node->identifier, "C", ft_strlen(node->identifier)))
		node = ft_fill_C_node(node, informations);
	else if (!ft_strncmp(node->identifier, "sp", ft_strlen(node->identifier)))
		node = ft_fill_sp_node(node, informations);
	else if (!ft_strncmp(node->identifier, "pl", ft_strlen(node->identifier)))
		node = ft_fill_pl_node(node, informations);
	else
		node = ft_fill_cy_node(node, informations);
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

t_map	*ft_create_map_list(int fd)
{
	t_map	*map;
	t_map	*node;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_empty_line(line))
		{
			node = ft_new_map_node(line);
			if (!node)
				return (free(line), ft_map_list_clear(map), NULL);
			ft_mapadd_back(&map, node);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
