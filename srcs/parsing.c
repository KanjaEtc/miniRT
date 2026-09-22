#include "../include/header.h"

static int	ft_check_rt_extension(char *file_name)
{
	int	i;

	i = -1;
	while (file_name && file_name[++i])
	{
		if (file_name[i] == '.')
			return (!ft_strncmp(&file_name[i], ".rt", ft_strlen(&file_name)));
	}
	return (0);
}

int	ft_parser(char *file_name)
{
	int		fd;
	t_map	*map;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	if (!ft_check_rt_extension(file_name))
		return (0);
	map = ft_create_list(fd);
	if (!map)
		return (0);
	if (!ft_check_identifiers_validity(map)
		|| !ft_check_mandatory_identifiers(map))
		return (ft_map_list_clear(&map), 0);
	return (0);
	// return (ft_check_parameters(map));
}
