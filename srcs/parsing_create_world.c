#include "../include/header.h"

static t_ambient	*ft_fill_A_struct(char *line, int *null_flag)
{
	t_ambient	*ambient;
	char		**infos;

	if (!line)
		return (*null_flag = 1, NULL);
	ambient = ft_init_ambient();
	if (!ambient)
		return (*null_flag = 1, NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 4)
		return (ft_free_ambient(ambient), ft_free_array(infos), *null_flag = 1, NULL);
	ambient->ratio = (double)ft_atoi(infos[0]);
	ambient->color = ft_color_creator((double)ft_atoi(infos[1]),
		(double)ft_atoi(infos[2]), (double)ft_atoi(infos[3]));
	ft_free_array(infos);
	if (!ambient->color)
		return (ft_free_ambient(ambient), *null_flag = 1, NULL);
	return (ambient);
}

static char	*ft_extract_identifier(char *line, int *k)
{
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (!ft_isspace(line[j]))
		j++;
	*k = j;
	return (ft_substr(line, i, j - i));
}

static int	ft_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = -1;
	while (line[++i])
	{
		if (!ft_isspace(line[i]))
			return (0);
	}
	return (1);
}

t_world	*ft_create_world(int fd)
{
	t_world	*world;
	char	*identifier;
	char	*line;
	int		k;
	int		null_flag;

	world = ft_init_world();
	if (!world)
		return (NULL);
	k = 0;
	null_flag = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		identifier = ft_extract_identifier(line, &k);
		/* checker que l'identiifer existe */
		if (!ft_strncmp(identifier, "A", ft_strlen(identifier)))
			world->ambient = ft_fill_A_struct(&line[k], &null_flag);
		else if (!ft_strncmp(identifier, "C", ft_strlen(identifier)))
			world->camera = ft_fill_C_struct(&line[k], &null_flag);
		else if (!ft_strncmp(identifier, "L", ft_strlen(identifier)))
			ft_lights_addback(&world->lights,
				ft_fill_L_struct(&line[k], &null_flag));
		else if (!ft_strncmp(identifier, "sp", ft_strlen(identifier)))
			ft_spheres_addback(&world->spheres,
				ft_fill_sp_struct(&line[k], &null_flag));
		else if (!ft_strncmp(identifier, "pl", ft_strlen(identifier)))
			ft_planes_addback(&world->planes,
				ft_fill_pl_struct(&line[k], &null_flag));
		else if (!ft_strncmp(identifier, "cy", ft_strlen(identifier)))
			ft_cylinders_addback(&world->cylinders,
				ft_fill_cy_struct(&line[k], &null_flag));
		else
			return (free(identifier), free(line), ft_free_world(world), NULL);
		free(identifier);
		free(line);
		if (null_flag)
			return (ft_free_world(world), NULL);
		line = get_next_line(fd);
	}
	return (world);
}
