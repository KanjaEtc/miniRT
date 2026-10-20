/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:43:09 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/08 11:43:13 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	*ft_reflect(t_tuple *v_in, t_tuple *v_normal)
{
	t_tuple	*tmp_v1;
	t_tuple	*tmp_v2;
	t_tuple	*reflect_v;

	if (!v_in || !ft_is_a_vector(v_in)
		|| !v_normal || !ft_is_a_vector(v_normal))
		return (NULL);
	tmp_v1 = ft_vector_by_scalar_multiplication(v_normal, 2);
	tmp_v2 = ft_vector_by_scalar_multiplication(tmp_v1,
			ft_dot_product(v_in, v_normal));
	reflect_v = ft_tuples_subtraction(v_in, tmp_v2);
	return (free(tmp_v1), free(tmp_v2), reflect_v);
}

// int main()
// {
// 	t_tuple *v_in = ft_vector_creator(1, -1, 0);
// 	t_tuple *v_normal = ft_vector_creator(0, 1, 0);
// 	t_tuple *reflect_v = ft_reflect(v_in, v_normal);
// 	printf("reflect : x=%f y=%f z=%f w=%f", reflect_v->z,
//	reflect_v->y, reflect_v->z, reflect_v->w);
// }
