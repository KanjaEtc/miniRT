/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:44:05 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:44:08 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_matrix	*ft_x_axis_rotation(double radians)
{
	t_matrix	*rotation_matrix;

	rotation_matrix = ft_identity_matrix_creator(4);
	if (!rotation_matrix)
		return (NULL);
	rotation_matrix->mtx[1][1] = cos(radians);
	rotation_matrix->mtx[1][2] = -sin(radians);
	rotation_matrix->mtx[2][1] = sin(radians);
	rotation_matrix->mtx[2][2] = cos(radians);
	return (rotation_matrix);
}

t_matrix	*ft_y_axis_rotation(double radians)
{
	t_matrix	*rotation_matrix;

	rotation_matrix = ft_identity_matrix_creator(4);
	if (!rotation_matrix)
		return (NULL);
	rotation_matrix->mtx[0][0] = cos(radians);
	rotation_matrix->mtx[0][2] = sin(radians);
	rotation_matrix->mtx[2][0] = -sin(radians);
	rotation_matrix->mtx[2][2] = cos(radians);
	return (rotation_matrix);
}

t_matrix	*ft_z_axis_rotation(double radians)
{
	t_matrix	*rotation_matrix;

	rotation_matrix = ft_identity_matrix_creator(4);
	if (!rotation_matrix)
		return (NULL);
	rotation_matrix->mtx[0][0] = cos(radians);
	rotation_matrix->mtx[0][1] = -sin(radians);
	rotation_matrix->mtx[1][0] = sin(radians);
	rotation_matrix->mtx[1][1] = cos(radians);
	return (rotation_matrix);
}
