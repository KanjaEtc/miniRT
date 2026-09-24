#include "../include/header.h"

t_camera	*ft_fill_C_struct(char *line)
{
	t_camera	*camera;
	char		**infos;

	if (!line)
		return (NULL);
	camera = ft_init_camera();
	if (!camera)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 7)
		return (ft_free_camera(camera), ft_free_array(infos), NULL);
	camera->origin =  ft_point_creator((double)ft_atoi(infos[0]),
		(double)ft_atoi(infos[1]), (double)ft_atoi(infos[2]));
	camera->normal = ft_vector_creator((double)ft_atoi(infos[3]),
		(double)ft_atoi(infos[4]), (double)ft_atoi(infos[5]));
	camera->fov = (double)ft_atoi(infos[6]);
	ft_free_array(infos);
	if (!camera->origin || !camera->normal)
		return (ft_free_camera(camera), NULL);
	return (camera);
}

t_light	*ft_fill_L_struct(char *line)
{
	t_light	*light;
	char	**infos;

	if (!line)
		return (NULL);
	light = ft_init_lights();
	if (!light)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 7)
		return (ft_lights_list_clear(&light), ft_free_array(infos), NULL);
	light->origin = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	light->ratio = ft_atoi(infos[3]);
	light->color = ft_color_creator(ft_atoi(infos[4]),
		ft_atoi(infos[5]), ft_atoi(infos[6]));
	ft_free_array(infos);
	if (!light->origin || !light->color)
		return (ft_lights_list_clear(&light), NULL);
	return (light);
}

t_sphere	*ft_fill_sp_struct(char *line)
{
	t_sphere	*sphere;
	char		**infos;

	if (!line)
		return (NULL);
	sphere = ft_init_spheres();
	if (!sphere)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 7)
		return (ft_spheres_list_clear(&sphere), ft_free_array(infos), NULL);
	sphere->center = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	sphere->diameter = ft_atoi(infos[3]);
	sphere->color = ft_color_creator(ft_atoi(infos[4]),
		ft_atoi(infos[5]), ft_atoi(infos[6]));
	ft_free_array(infos);
	if (!sphere->center || !sphere->color)
		return (ft_spheres_list_clear(&sphere), NULL);
	return (sphere);
}

t_plane	*ft_fill_pl_struct(char *line)
{
	t_plane		*plane;
	char		**infos;

	if (!line)
		return (NULL);
	plane = ft_init_planes();
	if (!plane)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 9)
		return (ft_planes_list_clear(&plane), ft_free_array(infos), NULL);
	plane->point = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	plane->normal = ft_vector_creator(ft_atoi(infos[3]),
		ft_atoi(infos[4]), ft_atoi(infos[5]));
	plane->color = ft_color_creator(ft_atoi(infos[6]),
		ft_atoi(infos[7]), ft_atoi(infos[8]));
	ft_free_array(infos);
	if (!plane->point || !plane->normal || !plane->color)
		return (ft_planes_list_clear(&plane), NULL);
	return (plane);
}

t_cylinder	*ft_fill_cy_struct(char *line)
{
	t_cylinder	*cylinder;
	char		**infos;

	if (!line)
		return (NULL);
	cylinder = ft_init_cylinders();
	if (!cylinder)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 11)
		return (ft_cylinders_list_clear(&cylinder), ft_free_array(infos), NULL);
	cylinder->center = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	cylinder->axis = ft_vector_creator(ft_atoi(infos[3]),
		ft_atoi(infos[4]), ft_atoi(infos[5]));
	cylinder->diameter = ft_atoi(infos[6]);
	cylinder->height = ft_atoi(infos[7]);
	cylinder->color = ft_color_creator(ft_atoi(infos[8]),
		ft_atoi(infos[9]), ft_atoi(infos[10]));
	ft_free_array(infos);
	if (!cylinder->center || !cylinder->axis || !cylinder->color)
		return (ft_cylinders_list_clear(&cylinder), NULL);
	return (cylinder);
}
