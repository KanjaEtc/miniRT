#include "../include/header.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (1);	
	// return (ft_error("One argument"), 1);
	
	map = ft_parser(argv[1]);
	if (!map)
		return (1);
	ft_display_map(map);
	ft_map_list_clear(&map);
}
