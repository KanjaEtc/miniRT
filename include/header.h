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

typedef struct s_sphere
{
	t_tuple			*center;
	t_tuple			*color;
	double			diameter;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_tuple			*point;
	t_tuple			*normal;
	t_tuple			*color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple				*center;
	t_tuple				*axis;
	t_tuple				*color;
	double				diameter;
	double				height;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_light
{
	t_tuple			*origin;
	t_tuple			*color;
	double			ratio;
	struct s_light	*next;
}	t_light;

typedef struct s_camera
{
	t_tuple		*origin;
	t_tuple		*normal;
	double		fov;
}	t_camera;

typedef struct s_ambient
{
	double		ratio;
	t_tuple		*color;
}	t_ambient;

typedef struct s_canvas
{
	int		width;
	int		height;
	t_tuple	**pixel_grid;
}	t_canvas;

typedef struct s_world
{
	t_canvas	*canvas;

	t_ambient	*ambient;
	t_camera	*camera;

	t_light		*lights;

	t_sphere	*spheres;
	t_cylinder	*cylinders;
	t_plane		*planes;

}	t_world;

typedef struct s_matrix
{
	double	**mtx;
	int		n;
}	t_matrix;

/* =============================== PARSER ============================== */

/* parsing.c */
t_world		*ft_parser(char *file_name);

/* parsing_create_world.c */
t_world		*ft_create_world(int fd);

/* parsing_fill_world.c */
t_camera	*ft_fill_C_struct(char *line, int *null_flag);
t_light		*ft_fill_L_struct(char *line, int *null_flag);
t_sphere	*ft_fill_sp_struct(char *line, int *null_flag);
t_plane		*ft_fill_pl_struct(char *line, int *null_flag);
t_cylinder	*ft_fill_cy_struct(char *line, int *null_flag);

/* parsing_check_identifiers.c */
// int			ft_check_identifiers_validity(t_map *map);
// int			ft_check_mandatory_identifiers(t_map *map);

/* parsing_check_parameters.c */
// int			ft_check_parameters(t_map *map);

/* parsing_init_struct */
t_world		*ft_init_world(void);
t_ambient	*ft_init_ambient(void);
t_camera	*ft_init_camera(void);

/* parsing_init_list */
t_light		*ft_init_lights(void);
t_sphere	*ft_init_spheres(void);
t_plane		*ft_init_planes(void);
t_cylinder	*ft_init_cylinders(void);

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
void		ft_display_world(t_world *world);
void		ft_display_tuple(t_tuple *t);
void		test_fill_matrix(t_matrix *matrix, double start);
// void		ft_display_map(t_map *map);

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

/* tuples_utils.c */
int			ft_is_a_normalized_vector(t_tuple *vector);

/* =============================== UTILS ============================== */

/* utils_list_addback.c */
void		ft_lights_addback(t_light **lights, t_light *new);
void		ft_spheres_addback(t_sphere **spheres, t_sphere *new);
void		ft_planes_addback(t_plane **planes, t_plane *new);
void		ft_cylinders_addback(t_cylinder **cylinders, t_cylinder *new);

/* utils_list_clear.c */
void		ft_lights_list_clear(t_light **lights);
void		ft_spheres_list_clear(t_sphere **spheres);
void		ft_planes_list_clear(t_plane **planes);
void		ft_cylinders_list_clear(t_cylinder **cylinders);

/* utils_free.c */
void		*ft_free_tuple_array(t_tuple **array, int index);
void		*ft_free_double_array(double **array, int index);
void		*ft_free_matrix(t_matrix *m);

/* utils_free_struct.c */
void		ft_free_world(t_world *world);
void		ft_free_ambient(t_ambient *ambient);
void		ft_free_camera(t_camera *camera);

/* utils_array.c */
int			ft_array_length(char **array);

#endif
