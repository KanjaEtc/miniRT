#include "../include/header.h"

t_camera	*ft_fill_C_struct(char *line, int *null_flag)
{
	t_camera	*camera;
	char		**infos;

	if (!line)
		return (*null_flag = 1, NULL);
	camera = ft_init_camera();
	if (!camera)
		return (*null_flag = 1, NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 7)
		return (free(camera), ft_free_array(infos), *null_flag = 1, NULL);
	camera->origin =  ft_point_creator((double)ft_atoi(infos[0]),
		(double)ft_atoi(infos[1]), (double)ft_atoi(infos[2]));
	camera->normal = ft_vector_creator((double)ft_atoi(infos[3]),
		(double)ft_atoi(infos[4]), (double)ft_atoi(infos[5]));
	camera->fov = (double)ft_atoi(infos[6]);
	if (!camera->origin || !camera->normal)
		return (ft_free_camera(camera), *null_flag = 1, NULL);
	return (camera);
}

t_light	*ft_fill_L_struct(char *line, int *null_flag)
{
	t_light	*light;
	char	**infos;

	if (!line)
		return (*null_flag = 1, NULL);
	light = ft_init_lights();
	if (!light)
		return (*null_flag = 1, NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 7)
		return (free(light), ft_free_array(infos), *null_flag = 1, NULL);
	light->origin = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	light->ratio = ft_atoi(infos[3]);
	light->color = ft_color_creator(ft_atoi(infos[4]),
		ft_atoi(infos[5]), ft_atoi(infos[6]));
	if (!light->origin || !light->color)
		return (ft_lights_list_clear(&light), *null_flag = 1, NULL);
	return (light);
}

t_sphere	*ft_fill_sp_struct(char *line, int *null_flag)
{
	t_sphere	*sphere;
	char		**infos;

	if (!line)
		return (*null_flag = 1, NULL);
	sphere = ft_init_spheres();
	if (!sphere)
		return (*null_flag = 1, NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 7)
		return (free(sphere), ft_free_array(infos), *null_flag = 1, NULL);
	sphere->center = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	sphere->diameter = ft_atoi(infos[3]);
	sphere->color = ft_color_creator(ft_atoi(infos[4]),
		ft_atoi(infos[5]), ft_atoi(infos[6]));
	if (!sphere->center || !sphere->color)
		return (ft_spheres_list_clear(&sphere), *null_flag = 1, NULL);
	return (sphere);
}

t_plane	*ft_fill_pl_struct(char *line, int *null_flag)
{
	t_plane		*plane;
	char		**infos;

	if (!line)
		return (*null_flag = 1, NULL);
	plane = ft_init_planes();
	if (!plane)
		return (*null_flag = 1, NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 9)
		return (free(plane), ft_free_array(infos), *null_flag = 1, NULL);
	plane->point = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	plane->normal = ft_vector_creator(ft_atoi(infos[3]),
		ft_atoi(infos[4]), ft_atoi(infos[5]));
	plane->color = ft_color_creator(ft_atoi(infos[6]),
		ft_atoi(infos[7]), ft_atoi(infos[8]));
	if (!plane->point || !plane->normal || !plane->color)
		return (ft_planes_list_clear(&plane), *null_flag = 1, NULL);
	return (plane);
}

t_cylinder	*ft_fill_cy_struct(char *line, int *null_flag)
{
	t_cylinder	*cylinder;
	char		**infos;

	if (!line)
		return (*null_flag = 1, NULL);
	cylinder = ft_init_cylinders();
	if (!cylinder)
		return (*null_flag = 1, NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 11)
		return (free(cylinder), ft_free_array(infos), *null_flag = 1, NULL);
	cylinder->center = ft_point_creator(ft_atoi(infos[0]),
		ft_atoi(infos[1]), ft_atoi(infos[2]));
	cylinder->axis = ft_vector_creator(ft_atoi(infos[3]),
		ft_atoi(infos[4]), ft_atoi(infos[5]));
	cylinder->diameter = ft_atoi(infos[6]);
	cylinder->height = ft_atoi(infos[7]);
	cylinder->color = ft_color_creator(ft_atoi(infos[8]),
		ft_atoi(infos[9]), ft_atoi(infos[10]));
	if (!cylinder->center || !cylinder->axis || !cylinder->color)
		return (ft_cylinders_list_clear(&cylinder), *null_flag = 1, NULL);
	return (cylinder);
}

// t_map	*ft_fill_C_node(t_map *node, char **informations)
// {
// 	double	fov;

// 	if (!node || !informations || ft_array_length(informations) != 7)
// 		return (NULL);
// 	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
// 		(double)ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
// 	node->normalized_orientation = ft_vector_creator((double)ft_atoi(informations[3]),
// 		(double)ft_atoi(informations[4]), (double)ft_atoi(informations[5]));
// 	fov = (double)ft_atoi(informations[6]);
// 	if (fov < 0 || fov > 180)
// 		return (NULL);
// 	node->fov = fov;
// 	node->color = NULL;
// 	node->point = NULL;
// 	return (node);
// }

// t_map	*ft_fill_L_node(t_map *node, char **informations)
// {
// 	double	ratio;

// 	if (!node || !informations || ft_array_length(informations) != 7)
// 		return (NULL);
// 	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
// 		(double)ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
// 	ratio = (double)ft_atoi(informations[3]);
// 	if (ratio < 0 || ratio > 1)
// 		return (NULL);
// 	node->color = ft_color_creator((double)ft_atoi(informations[4]),
// 		(double)ft_atoi(informations[5]), (double)ft_atoi(informations[6]));
// 	node->point = NULL;
// 	node->normalized_orientation = NULL;
// 	return (node);
// }

// t_map	*ft_fill_sp_node(t_map *node, char **informations)
// {
// 	if (!node || !informations || ft_array_length(informations) != 7)
// 		return (NULL);
// 	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
// 		ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
// 	node->diameter = (double)ft_atoi(informations[3]);
// 	node->color = ft_color_creator((double)ft_atoi(informations[4]),
// 		(double)ft_atoi(informations[5]), (double)ft_atoi(informations[6]));
// 	node->normalized_orientation = NULL;
// 	node->point = NULL;
// 	return (node);
// }

// t_map	*ft_fill_pl_node(t_map *node, char **informations)
// {
// 	t_tuple	*vector;

// 	if (!node || !informations || ft_array_length(informations) != 9)
// 		return (NULL);
// 	node->point = ft_point_creator((double)ft_atoi(informations[0]),
// 		(double)ft_atoi(informations[1]),(double)ft_atoi(informations[2]));
// 	vector = ft_vector_creator((double)ft_atoi(informations[3]),
// 		(double)ft_atoi(informations[4]), (double)ft_atoi(informations[5]));
// 	if (!ft_is_a_normalized_vector(vector))
// 		return (free(node->point), free(vector), NULL);
// 	node->normalized_orientation = vector;
// 	node->color = ft_color_creator((double)ft_atoi(informations[6]),
// 		(double)ft_atoi(informations[7]), (double)ft_atoi(informations[8]));
// 	node->origin = NULL;
// 	return (node);
// }

// t_map	*ft_fill_cy_node(t_map *node, char **informations)
// {
// 	t_tuple	*vector;

// 	if (!node || !informations || ft_array_length(informations) != 11)
// 		return (NULL);
// 	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
// 		(double)ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
// 	vector = ft_vector_creator((double)ft_atoi(informations[3]),
// 		(double)ft_atoi(informations[4]), (double)ft_atoi(informations[5]));
// 	if (!ft_is_a_normalized_vector(vector))
// 		return (free(vector), NULL);
// 	node->normalized_orientation = vector;
// 	node->diameter = (double)ft_atoi((informations)[6]);
// 	node->height = (double)ft_atoi((informations)[7]);
// 	node->color = ft_color_creator(ft_atoi(informations[8]),
// 		ft_atoi(informations[9]), ft_atoi(informations[10]));
// 	node->point = NULL;
// 	return (node);
// }
