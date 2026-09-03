#ifndef HEADER_H
# define HEADER_H
# include <criterion/criterion.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

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

/* =============================== CANVAS ============================== */

/* canvas_and_pixels.c */
t_canvas	*ft_canvas_creator(int width, int height);
t_tuple		**ft_pixel_grid_allocator(int width, int height);
t_tuple		*ft_get_pixel_color(t_canvas *canvas, int w, int h);
void		ft_write_pixel_color(t_canvas *canvas, int w, int h,
				t_tuple *color);
t_tuple		*ft_color_creator(double x, double y, double z);

/* =============================== DISPLAY ETC ============================== */

void		ft_display_matrix(t_matrix *matrix);
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

#endif
