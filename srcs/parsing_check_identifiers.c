#include "../include/header.h"

// int	ft_check_mandatory_identifiers(t_map *map)
// {
// 	t_map	*tmp;
// 	int		A;
// 	int		L;
// 	int		C;

// 	if (!map)
// 		return (0);
// 	A = 0;
// 	L = 0;
// 	C = 0;
// 	tmp = map;
// 	while (tmp)
// 	{
// 		if (!ft_strncmp(tmp->identifier, "A", ft_strlen(tmp->identifier)))
// 			A++;
// 		else if (!ft_strncmp(tmp->identifier, "L", ft_strlen(tmp->identifier)))
// 			L++;
// 		else if (!ft_strncmp(tmp->identifier, "C", ft_strlen(tmp->identifier)))
// 			C++;
// 		tmp = tmp->next;
// 	}
// 	return (A == 1 && L == 1 && C == 1);
// }

// int	ft_check_identifiers_validity(t_map *map)
// {
// 	t_map	*tmp;

// 	if (!map)
// 		return (0);
// 	tmp = map;
// 	while (tmp)
// 	{
// 		if (ft_strncmp(tmp->identifier, "A", ft_strlen(tmp->identifier))
// 			&& ft_strncmp(tmp->identifier, "L", ft_strlen(tmp->identifier))
// 			&& ft_strncmp(tmp->identifier, "C", ft_strlen(tmp->identifier))
// 			&& ft_strncmp(tmp->identifier, "sp", ft_strlen(tmp->identifier))
// 			&& ft_strncmp(tmp->identifier, "pl", ft_strlen(tmp->identifier))
// 			&& ft_strncmp(tmp->identifier, "cy", ft_strlen(tmp->identifier)))
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }
