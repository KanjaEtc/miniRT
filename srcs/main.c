#include "../include/header.h"

int	main(int argc, char **argv)
{
	// t_map	*map;
	int	fd;

	if (argc != 2)
		return (1);	
	// return (ft_error("One argument"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	// map = ft_parser(fd);
	// if (!map)
	// 	return (1);
	// ft_map_list_clear(&map);
	// if (!ft_parser(fd))
	// 	return (1);
}
