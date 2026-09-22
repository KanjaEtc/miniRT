#include "../include/header.h"

static int	ft_check_ambient_informations(t_map *node)
{
	if (!node || !node->parameters)
		return (0);
	return (ft_atoi(node->parameters[0]) >= 0 && ft_atoi(node->parameters[0]) <= 1
		&& node->parameters[1]);
}

int	ft_check_parameters(t_map *map)
{
	t_map	*tmp;
	int		is_valid;

	tmp = map;
	is_valid = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->identifier, "A", ft_strlen(tmp->identifier)))
			is_valid = ft_check_ambient_informations(tmp);			
		else if (!ft_strncmp(tmp->identifier, "L", ft_strlen(tmp->identifier)))
			is_valid = ft_check_ambient_informations(tmp);
		else if (!ft_strncmp(tmp->identifier, "C", ft_strlen(tmp->identifier)))
			is_valid = ft_check_ambient_informations(tmp);
		else if (!ft_strncmp(tmp->identifier, "sp", ft_strlen(tmp->identifier)))
			is_valid = ft_check_ambient_informations(tmp);
		else if (!ft_strncmp(tmp->identifier, "pl", ft_strlen(tmp->identifier)))
			is_valid = ft_check_ambient_informations(tmp);
		else if (!ft_strncmp(tmp->identifier, "cy", ft_strlen(tmp->identifier)))
			is_valid = ft_check_ambient_informations(tmp);
		if (!is_valid)
			return (0);
		tmp = tmp->next;
	}
	return (map != NULL);
}
