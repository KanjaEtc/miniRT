#include "../include/header.h"

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc != 2)
		return (1);	
	// return (ft_error("One argument"), 1);
	
	world = ft_parser(argv[1]);
	if (!world)
		return (1);
	ft_display_world(world);
	ft_free_world(world);
}
