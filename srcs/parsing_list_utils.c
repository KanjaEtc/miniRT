#include "../include/header.h"

void	ft_lights_list_clear(t_light **lights)
{
	t_light	*tmp;

	if (!lights || !*lights)
		return ;
	while (*lights)
	{
		tmp = (*lights)->next;
		free((*lights)->origin);
		free((*lights)->color);
		free(*lights);
		*lights = tmp;
	}
	*lights = NULL;
}

void	ft_spheres_list_clear(t_sphere **spheres)
{
	t_sphere	*tmp;

	if (!spheres || !*spheres)
		return ;
	while (*spheres)
	{
		tmp = (*spheres)->next;
		free((*spheres)->center);
		free((*spheres)->color);
		free(*spheres);
		*spheres = tmp;
	}
	*spheres = NULL;
}

void	ft_planes_list_clear(t_plane **planes)
{
	t_plane	*tmp;

	if (!planes || !*planes)
		return ;
	while (*planes)
	{
		tmp = (*planes)->next;
		free((*planes)->point);
		free((*planes)->normal);
		free((*planes)->color);
		free(*planes);
		*planes = tmp;
	}
	*planes = NULL;
}

void	ft_cylinders_list_clear(t_cylinder **cylinders)
{
	t_cylinder	*tmp;

	if (!cylinders || !*cylinders)
		return ;
	while (*cylinders)
	{
		tmp = (*cylinders)->next;
		free((*cylinders)->center);
		free((*cylinders)->axis);
		free((*cylinders)->color);
		free(*cylinders);
		*cylinders = tmp;
	}
	*cylinders = NULL;
}

void	ft_lights_addback(t_light **lights, t_light *new)
{
	t_light	*tmp;

	if (!lights || !new)
		return ;
	if (!*lights)
	{
		*lights = new;
		return ;
	}
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_spheres_addback(t_sphere **spheres, t_sphere *new)
{
	t_sphere	*tmp;

	if (!spheres || !new)
		return ;
	if (!*spheres)
	{
		*spheres = new;
		return ;
	}
	tmp = *spheres;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_planes_addback(t_plane **planes, t_plane *new)
{
	t_plane	*tmp;

	if (!planes || !new)
		return ;
	if (!*planes)
	{
		*planes = new;
		return ;
	}
	tmp = *planes;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_cylinders_addback(t_cylinder **cylinders, t_cylinder *new)
{
	t_cylinder	*tmp;

	if (!cylinders || !new)
		return ;
	if (!*cylinders)
	{
		*cylinders = new;
		return ;
	}
	tmp = *cylinders;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}



// t_map	*ft_new_map_node(char *line)
// {
// 	t_map	*node;
// 	char	**informations;
// 	char	*subline;
// 	int		k;

// 	if (!line)
// 		return (NULL);
// 	node = malloc(sizeof(t_map));
// 	if (!node)
// 		return (NULL);
// 	node->next = NULL;
// 	node->identifier = ft_extract_identifier(line, &k);
// 	subline = ft_substr(line, k, ft_strlen(line) - k);
// 	informations = ft_split(subline, "\t\n\v\f\r ,");
// 	if (!informations)
// 		return (free(node->identifier), free(node), free(subline), NULL);
// 	ft_fill_nodes(node, informations);
// 	return (free(subline), ft_free_array(informations), node);
// }
