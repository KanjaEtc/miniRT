#include "../include/header.h"

static int	ft_check_rt_extension(char *file_name)
{
	int	i;

	i = -1;
	while (file_name && file_name[++i])
	{
		if (file_name[i] == '.')
			return (!ft_strncmp(&file_name[i], ".rt", ft_strlen(file_name)));
	}
	return (0);
}

t_world	*ft_parser(char *file_name)
{
	int		fd;
	t_world	*world;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!ft_check_rt_extension(file_name))
		return (NULL);
	world = ft_create_world(fd);
	/* checker que tous les identifiers soient la */
	if (!world)
		return (NULL);
	// if (!ft_check_identifiers_validity(wor)
		// || !ft_check_mandatory_identifiers(map)) utile
		// return (ft_map_list_clear(&map), NULL);
	return (world);
	// return (ft_check_parameters(map));
}
