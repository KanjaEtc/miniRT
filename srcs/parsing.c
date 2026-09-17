// #include "../include/header.h"

// char	*ft_extract_parameters(char *line, int k)
// {
// 	int	i;

// 	if (!line)
// 		return (NULL);
// 	i = k;
// 	while (line[i])
// 		i++;
// 	return (ft_substr(line, k, i - k));
// }

// char	*ft_extract_identifier(char *line, int *k)
// {
// 	int		i;
// 	int		j;

// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (ft_isspace(line[i]))
// 		i++;
// 	j = i;
// 	while (!ft_isspace(line[j]))
// 		j++;
// 	*k = j;
// 	return (ft_substr(line, i, j - i));
// }

// static int	ft_empty_line(char *line)
// {
// 	int	i;

// 	if (!line)
// 		return (1);
// 	i = -1;
// 	while (line[++i])
// 	{
// 		if (!ft_isspace(line[i]))
// 			return (0);
// 	}
// 	return (1);
// }

// t_map	*ft_parser(int fd)
// {
// 	t_map	*map;
// 	t_map	*node;
// 	char	*line;

// 	map = NULL;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (!ft_empty_line(line))
// 		{
// 			node = ft_new_map_list(line);
// 			ft_mapadd_back(&map, node);
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (map);
// }
