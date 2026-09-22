#include "../include/header.h"

void	ft_map_list_clear(t_map **map)
{
	t_map	*tmp;

	if (!map || !*map)
		return ;
	while (*map)
	{
		tmp = (*map)->next;
		free((*map)->identifier);
		free((*map)->color);
		free((*map)->point);
		free((*map)->normalized_orientation);
		free((*map)->origin);
		free(*map);
		*map = tmp;
	}
	*map = NULL;
}

void	ft_mapadd_back(t_map **map, t_map *new)
{
	t_map	*tmp;

	if (!map || !new)
		return ;
	if (!*map)
	{
		*map = new;
		return ;
	}
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_map	*ft_new_map_node(char *line)
{
	t_map	*node;
	char	**informations;
	char	*subline;
	int		k;

	if (!line)
		return (NULL);
	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->identifier = ft_extract_identifier(line, &k);
	subline = ft_substr(line, k, ft_strlen(line) - k);
	informations = ft_split(subline, "\t\n\v\f\r ,");
	if (!informations)
		return (free(node->identifier), free(node), free(subline), NULL);
	ft_fill_nodes(node, informations);
	return (free(subline), ft_free_array(informations), node);
}
