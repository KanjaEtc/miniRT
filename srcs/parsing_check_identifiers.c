#include "../include/header.h"

int	ft_check_mandatory_identifiers(t_world *world)
{
	if (!world)
		return (0);
	return (world->ambient != NULL
		&& world->camera != NULL
		&& world->lights != NULL);
}
