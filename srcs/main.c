#include "../include/header.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);	
	// return (ft_error("One argument"), 1);
	
	if (!ft_parser(argv[1]))
		return (1);
	// ft_map_list_clear(&map);
}
