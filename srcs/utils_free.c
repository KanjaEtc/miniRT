#include "../include/header.h"

void	*ft_free_tuple_array(t_tuple **array, int index)
{
	int	i;

	i = -1;
	while (array && ++i < index)
		free(array[i]);
	free(array);
	return (NULL);
}

void	*ft_free_double_array(double **array, int index)
{
	int	i;

	i = -1;
	while (array && ++i < index)
		free(array[i]);
	free(array);
	return (NULL);
}
