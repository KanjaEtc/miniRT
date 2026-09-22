#include "../include/header.h"

char	*ft_extract_parameters(char *line, int k)
{
	int	i;

	if (!line)
		return (NULL);
	i = k;
	while (line[i])
		i++;
	return (ft_substr(line, k, i - k));
}

char	*ft_extract_identifier(char *line, int *k)
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

double	**ft_double_params(char *line, int k)
{
	double	*double_array_params;
	char	*single_string_params;
	char	**strings_array_params;
	int		i;
	

	i = -1;
	single_string_params = ft_extract_parameters(line, k);
	strings_array_params = ft_split(single_string_params, "\t\n\v\f\r ,");
	free(single_string_params);
	if (!strings_array_params)
		return (NULL);
	double_array_params = malloc(sizeof(double) * ft_array_length(strings_array_params));
	if (!double_array_params)
		return (ft_free_array(strings_array_params), NULL);
	while (strings_array_params[++i])
		double_array_params[i] = (double)ft_atoi(strings_array_params[i]);
	ft_free_array(strings_array_params);
}

t_map	*ft_create_list(int fd)
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
			node = ft_new_map_list(line);
			ft_mapadd_back(&map, node);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
