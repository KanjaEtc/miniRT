/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:50:00 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:50:03 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
// # include <criterion/criterion.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <float.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_map
{
	char			*identifier;
	double			ratio;
	double			diameter;
	double			height;
	double			fov;
	t_tuple			*color;
	t_tuple			*origin;
	t_tuple			*normalized_orientation;
	t_tuple			*point;
	struct s_map	*next;
}	t_map;

typedef struct s_sphere
{
	t_tuple			*center;
	double			diameter;
	t_tuple			*color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_tuple			*random_point;
	t_tuple			*normal_vector;
	t_tuple			*color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple				*center;
	t_tuple				*axis;
	double				diameter;
	double				height;
	t_tuple				*color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_world
{
	int			*window_width;
	int			*window_height;

	double		ambient_ratio;
	t_tuple		*ambient_color;

	t_tuple		*camera_coordinates;
	t_tuple		*camera_normal;
	double		camera_fov;

	t_sphere	*spheres;
	t_cylinder	*cylinders;
	t_plane		*planes;

}	t_world;

typedef struct s_canvas
{
	int		width;
	int		height;
	t_tuple	**pixel_grid;
}	t_canvas;

typedef struct s_matrix
{
	double	**mtx;
	int		n;
}	t_matrix;

/* =============================== PARSER ============================== */

/* parsing.c */
int			ft_parser(char *file_name);

/* parsing_create_list.c */
t_map		*ft_create_map_list(int fd);

/* parsing_fill_list.c */
t_map		*ft_fill_C_node(t_map *node, char **informations);
t_map		*ft_fill_L_node(t_map *node, char **informations);
t_map		*ft_fill_sp_node(t_map *node, char **informations);
t_map		*ft_fill_pl_node(t_map *node, char **informations);
t_map		*ft_fill_cy_node(t_map *node, char **informations);

/* parsing_list_utils.c */
t_map		*ft_new_map_node(char *line);
void		ft_mapadd_back(t_map **map, t_map *new);
void		ft_map_list_clear(t_map **map);

/* parsing_check_identifiers.c */
int			ft_check_identifiers_validity(t_map *map);
int			ft_check_mandatory_identifiers(t_map *map);

/* parsing_check_parameters.c */
int			ft_check_parameters(t_map *map);

/* =============================== CANVAS ============================== */

/* canvas_and_pixels.c */
t_canvas	*ft_canvas_creator(int width, int height);
t_tuple		**ft_pixel_grid_allocator(int width, int height);

/* =============================== COLORS ============================== */

t_tuple		*ft_get_pixel_color(t_canvas *canvas, int w, int h);
void		ft_write_pixel_color(t_canvas *canvas, int w, int h,
				t_tuple *color);
t_tuple		*ft_color_creator(double x, double y, double z);

/* =============================== DISPLAY ETC ============================== */

void		ft_display_matrix(t_matrix *matrix);
void		ft_display_tuple(t_tuple *t);
void		test_fill_matrix(t_matrix *matrix, double start);

/* =============================== MATRICES ============================== */

/* matrix_creation.c */
t_matrix	*ft_matrix_creator(int n);
int			ft_matrix_equality(t_matrix *a, t_matrix *b);
t_matrix	*ft_identity_matrix_creator(int n);
t_matrix	*ft_identity_matrix_creator(int n);

/* matrix_operations.c */
t_matrix	*ft_matrices_multplication(t_matrix *a, t_matrix *b);
t_tuple		*ft_matrix_by_tuple_multiplication(t_matrix *m, t_tuple *t);
t_matrix	*ft_transpose_matrix(t_matrix *m);

/* matrix_determinant.c */
t_matrix	*ft_submatrix(t_matrix *m, int row, int col);
double		ft_minor(t_matrix *m, int row, int col);
double		ft_cofactor(t_matrix *m, int row, int col);
double		ft_matrix_determinant(t_matrix *m);

/* matrix_inversion.c */
int			ft_is_matrix_invertible(t_matrix *m);
t_matrix	*ft_inverse(t_matrix *m);

/* ============================ TRANSFORMATIONS =========================== */

/* transformations.c */
t_matrix	*ft_translation(double x, double y, double z);
t_matrix	*ft_scaling(double x, double y, double z);
t_matrix	*ft_x_axis_rotation(double radians);
t_matrix	*ft_y_axis_rotation(double radians);
t_matrix	*ft_z_axis_rotation(double radians);

/* =============================== TUPLES ============================== */

/* tuples_creation.c */
int			ft_is_a_vector(t_tuple *tuple);
int			ft_is_a_point(t_tuple *tuple);
t_tuple		*ft_vector_creator(double x, double y, double z);
t_tuple		*ft_point_creator(double x, double y, double z);

/* tuples_comparison.c */
int			ft_vectors_equality(t_tuple *v1, t_tuple *v2);
int			ft_points_equality(t_tuple *p1, t_tuple *p2);
double		ft_abs(double n);

/* tuples_basic_operations.c */
t_tuple		*ft_tuples_addition(t_tuple *t1, t_tuple *t2);
t_tuple		*ft_tuples_subtraction(t_tuple *t1, t_tuple *t2);
t_tuple		*ft_tuple_opposite(t_tuple *t);
t_tuple		*ft_vector_by_scalar_multiplication(t_tuple *vector, double scalar);
t_tuple		*ft_vector_by_scalar_division(t_tuple *vector, double scalar);

/* tuples_complex_operations */
double		ft_vector_length(t_tuple *v);
t_tuple		*ft_normalize(t_tuple *vector);
double		ft_dot_product(t_tuple *v1, t_tuple *v2);
t_tuple		*ft_cross_product(t_tuple *v1, t_tuple *v2);

/* =============================== UTILS ============================== */

/* utils_free.c */
void		*ft_free_tuple_array(t_tuple **array, int index);
void		*ft_free_double_array(double **array, int index);
void		*ft_free_matrix(t_matrix *m);

/* utils_array */
int			ft_array_length(char **array);

#endif
