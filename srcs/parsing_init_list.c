#include "../include/header.h"

t_light	*ft_init_lights(void)
{
	t_light	*lights;

	lights = malloc(sizeof(t_light));
	if (!lights)
		return (NULL);
	lights->origin = NULL;
	lights->color = NULL;
	lights->next = NULL;
	return (lights);
}

t_sphere	*ft_init_spheres(void)
{
	t_sphere	*spheres;

	spheres = malloc(sizeof(t_sphere));
	if (!spheres)
		return (NULL);
	spheres->center = NULL;
	spheres->color = NULL;
	spheres->next = NULL;
	return (spheres);
}

t_plane	*ft_init_planes(void)
{
	t_plane	*planes;

	planes = malloc(sizeof(t_plane));
	if (!planes)
		return (NULL);
	planes->point = NULL;
	planes->color = NULL;
	planes->normal = NULL;
	planes->next = NULL;
	return (planes);
}

t_cylinder	*ft_init_cylinders(void)
{
	t_cylinder	*cylinders;

	cylinders = malloc(sizeof(t_cylinder));
	if (!cylinders)
		return (NULL);
	cylinders->center = NULL;
	cylinders->color = NULL;
	cylinders->axis = NULL;
	cylinders->next = NULL;
	return (cylinders);
}
