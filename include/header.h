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

/* tuples_creation.c */
int		ft_is_a_vector(t_tuple *tuple);
int		ft_is_a_point(t_tuple *tuple);
t_tuple	*ft_vector_creator(double x, double y, double z);
t_tuple	*ft_point_creator(double x, double y, double z);

/* tuples_comparison.c */
int		ft_vectors_equality(t_tuple *v1, t_tuple *v2);
int		ft_points_equality(t_tuple *p1, t_tuple *p2);
double	ft_abs(double n);

/* tuples_basic_operations.c */
t_tuple	*ft_tuples_addition(t_tuple *t1, t_tuple *t2);
t_tuple	*ft_tuples_subtraction(t_tuple *t1, t_tuple *t2);
t_tuple	*ft_tuple_opposite(t_tuple *t);
t_tuple	*ft_vector_by_scalar_multiplication(t_tuple *vector, double scalar);
t_tuple	*ft_vector_by_scalar_division(t_tuple *vector, double scalar);

/* tuples_complex_operations */
double	ft_vector_length(t_tuple *v);
t_tuple	*ft_normalize(t_tuple *vector);
double	ft_dot_product(t_tuple *v1, t_tuple *v2);
t_tuple	*ft_cross_product(t_tuple *v1, t_tuple *v2);

#endif
