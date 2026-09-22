#include "../include/header.h"

t_map	*ft_fill_C_node(t_map *node, char **informations)
{
	double	fov;

	if (!node || !informations || ft_array_length(informations) != 7)
		return (NULL);
	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
		(double)ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
	node->normalized_orientation = ft_vector_creator((double)ft_atoi(informations[3]),
		(double)ft_atoi(informations[4]), (double)ft_atoi(informations[5]));
	fov = (double)ft_atoi(informations[6]);
	if (fov < 0 || fov > 180)
		return (NULL);
	node->fov = fov;
	node->color = NULL;
	node->point = NULL;
	return (node);
}

t_map	*ft_fill_L_node(t_map *node, char **informations)
{
	double	ratio;

	if (!node || !informations || ft_array_length(informations) != 7)
		return (NULL);
	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
		(double)ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
	ratio = (double)ft_atoi(informations[3]);
	if (ratio < 0 || ratio > 1)
		return (NULL);
	node->color = ft_color_creator((double)ft_atoi(informations[4]),
		(double)ft_atoi(informations[5]), (double)ft_atoi(informations[6]));
	node->point = NULL;
	node->normalized_orientation = NULL;
	return (node);
}

t_map	*ft_fill_sp_node(t_map *node, char **informations)
{
	if (!node || !informations || ft_array_length(informations) != 7)
		return (NULL);
	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
		ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
	node->diameter = (double)ft_atoi(informations[3]);
	node->color = ft_color_creator((double)ft_atoi(informations[4]),
		(double)ft_atoi(informations[5]), (double)ft_atoi(informations[6]));
	node->normalized_orientation = NULL;
	node->point = NULL;
	return (node);
}

t_map	*ft_fill_pl_node(t_map *node, char **informations)
{
	t_tuple	*vector;

	if (!node || !informations || ft_array_length(informations) != 9)
		return (NULL);
	node->point = ft_point_creator((double)ft_atoi(informations[0]),
		(double)ft_atoi(informations[1]),(double)ft_atoi(informations[2]));
	vector = ft_vector_creator((double)ft_atoi(informations[3]),
		(double)ft_atoi(informations[4]), (double)ft_atoi(informations[5]));
	if (!ft_is_a_normalized_vector(vector))
		return (free(node->point), free(vector), NULL);
	node->normalized_orientation = vector;
	node->color = ft_color_creator((double)ft_atoi(informations[6]),
		(double)ft_atoi(informations[7]), (double)ft_atoi(informations[8]));
	node->origin = NULL;
	return (node);
}

t_map	*ft_fill_cy_node(t_map *node, char **informations)
{
	t_tuple	*vector;

	if (!node || !informations || ft_array_length(informations) != 11)
		return (NULL);
	node->origin = ft_point_creator((double)ft_atoi(informations[0]),
		(double)ft_atoi(informations[1]), (double)ft_atoi(informations[2]));
	vector = ft_vector_creator((double)ft_atoi(informations[3]),
		(double)ft_atoi(informations[4]), (double)ft_atoi(informations[5]));
	if (!ft_is_a_normalized_vector(vector))
		return (free(vector), NULL);
	node->normalized_orientation = vector;
	node->diameter = (double)ft_atoi((informations)[6]);
	node->height = (double)ft_atoi((informations)[7]);
	node->color = ft_color_creator(ft_atoi(informations[8]),
		ft_atoi(informations[9]), ft_atoi(informations[10]));
	node->point = NULL;
	return (node);
}
