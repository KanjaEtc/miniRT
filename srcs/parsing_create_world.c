#include "../include/header.h"

static t_ambient	*ft_fill_A_struct(char *line)
{
	t_ambient	*ambient;
	char		**infos;

	if (!line)
		return (NULL);
	ambient = ft_init_ambient();
	if (!ambient)
		return (NULL);
	infos = ft_split(line, "\t\n\v\f\r ,");
	if (!infos || !*infos || ft_array_length(infos) != 4)
		return (ft_free_ambient(ambient), ft_free_array(infos), NULL);
	ambient->ratio = (double)ft_atoi(infos[0]);
	ambient->color = ft_color_creator((double)ft_atoi(infos[1]),
		(double)ft_atoi(infos[2]), (double)ft_atoi(infos[3]));
	ft_free_array(infos);
	if (!ambient->color)
		return (ft_free_ambient(ambient), NULL);
	return (ambient);
}

static char	*ft_extract_identifier(char *line)
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

static int	ft_fill_world(t_world *world, char *line, char *identifier)
{
	int	start;

	start = (int)ft_strlen(identifier);
	if (!ft_strncmp(identifier, "A", ft_strlen(identifier)))
		return (world->ambient = ft_fill_A_struct(&line[start]),
			world->ambient != NULL);
	if (!ft_strncmp(identifier, "C", ft_strlen(identifier)))
		return (world->camera = ft_fill_C_struct(&line[start]),
			world->camera != NULL);
	if (!ft_strncmp(identifier, "L", ft_strlen(identifier)))
		return (world->lights = ft_fill_L_struct(&line[start]),
			world->lights != NULL);
	if (!ft_strncmp(identifier, "sp", ft_strlen(identifier)))
		return (world->spheres = ft_fill_sp_struct(&line[start]),
			world->spheres != NULL);
	if (!ft_strncmp(identifier, "pl", ft_strlen(identifier)))
		return (world->planes = ft_fill_pl_struct(&line[start]),
			world->planes != NULL);
	if (!ft_strncmp(identifier, "cy", ft_strlen(identifier)))
		return (world->cylinders = ft_fill_cy_struct(&line[start]),
			world->cylinders != NULL);
	return (printf("Error: bad identifier\n"), 0); // REMPLACER PAR FT_PRINTF
}

t_world	*ft_create_world(int fd)
{
	t_world	*world;
	char	*line;
	char	*identifier;

	world = ft_init_world();
	if (!world)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_empty_line(line))
		{
			identifier = ft_extract_identifier(line);
			if (!identifier)
				return (free(identifier), free(line), ft_free_world(world));
			if (!ft_fill_world(world, line, identifier))
				return (free(line), free(identifier), ft_free_world(world));
			free(identifier);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!ft_check_mandatory_identifiers(world))
		return (printf("Error: identifiers missing\n"), ft_free_world(world));
	return (world);
}

// t_world	*ft_create_world(int fd)
// {
// 	t_world	*world;
// 	char	*identifier;
// 	char	*line;
// 	int		k;
// 	int		null_flag;

// 	world = ft_init_world();
// 	if (!world)
// 		return (NULL);
// 	k = 0;
// 	null_flag = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (ft_empty_line(line))
// 		{
// 			free(line);
// 			line = get_next_line(fd);
// 			continue ;
// 		}
// 		identifier = ft_extract_identifier(line, &k);
// 		/* checker que l'identiifer existe */
// 		if (!ft_strncmp(identifier, "A", ft_strlen(identifier)))
// 			world->ambient = ft_fill_A_struct(&line[k], &null_flag);
// 		else if (!ft_strncmp(identifier, "C", ft_strlen(identifier)))
// 			world->camera = ft_fill_C_struct(&line[k], &null_flag);
// 		else if (!ft_strncmp(identifier, "L", ft_strlen(identifier)))
// 			ft_lights_addback(&world->lights,
// 				ft_fill_L_struct(&line[k], &null_flag));
// 		else if (!ft_strncmp(identifier, "sp", ft_strlen(identifier)))
// 			ft_spheres_addback(&world->spheres,
// 				ft_fill_sp_struct(&line[k], &null_flag));
// 		else if (!ft_strncmp(identifier, "pl", ft_strlen(identifier)))
// 			ft_planes_addback(&world->planes,
// 				ft_fill_pl_struct(&line[k], &null_flag));
// 		else if (!ft_strncmp(identifier, "cy", ft_strlen(identifier)))
// 			ft_cylinders_addback(&world->cylinders,
// 				ft_fill_cy_struct(&line[k], &null_flag));
// 		else
// 			return (free(identifier), free(line), ft_free_world(world), NULL);
// 		free(identifier);
// 		free(line);
// 		if (null_flag)
// 			return (ft_free_world(world), NULL);
// 		line = get_next_line(fd);
// 	}
// 	return (world);
// }
