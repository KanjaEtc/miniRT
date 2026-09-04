#include "../include/header.h"

t_matrix	*ft_translation(double x, double y, double z)
{
	t_matrix	*translation_matrix;

	translation_matrix = ft_identity_matrix_creator(4);
	if (!translation_matrix)
		return (NULL);
	translation_matrix->mtx[0][3] = x;
	translation_matrix->mtx[1][3] = y;
	translation_matrix->mtx[2][3] = z;
	return (translation_matrix);
}

t_matrix	*ft_scaling(double x, double y, double z)
{
	t_matrix	*scaling_matrix;

	scaling_matrix = ft_identity_matrix_creator(4);
	if (!scaling_matrix)
		return (NULL);
	scaling_matrix->mtx[0][0] = x;
	scaling_matrix->mtx[1][1] = y;
	scaling_matrix->mtx[2][2] = z;
	return (scaling_matrix);
}

// int main()
// {
// 	t_matrix *translation_matrix = ft_translation(5, -3, 2);
// 	t_tuple *vector = ft_vector_creator(-3, 4, 5);
// 	t_tuple *product = ft_matrix_by_tuple_multiplication(translation_matrix, vector);
	
// 	ft_display_tuple(product);
// }
