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
		ft_free_array((*map)->parameters);
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

t_map	*ft_new_map_list(char *line)
{
	t_map	*new;
	char	*single_string_parameters;
	int		k;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	k = 0;
	new->identifier = ft_extract_identifier(line, &k);
	single_string_parameters = ft_extract_parameters(line, k);
	new->parameters = ft_split(single_string_parameters, "\t\n\v\f\r ");
	free(single_string_parameters);
	new->next = NULL;
	return (new);
}
