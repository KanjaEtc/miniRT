/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:27:01 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:27:04 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// int main()
// {
// 	t_tuple *v_in = ft_vector_creator(1, -1, 0);
// 	if (!v_in)
// 		printf("v_in est NULL\n");
// 	t_tuple *v_normal = ft_vector_creator(0, 1, 0);
// 	if (!v_normal)
// 		printf("v_normal est NULL\n");
// 	t_tuple *reflect_v = ft_reflect(v_in, v_normal);
// 	if (!reflect_v)
// 		return (printf("reflect_v est NULL\n"), 1);
// 	printf("reflect : x=%f y=%f z=%f w=%f", reflect_v->z, reflect_v->y, reflect_v->z, reflect_v->w);
// }

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc != 2)
		return (1);
	world = ft_parser(argv[1]);
	if (!world)
		return (1);
	ft_display_world(world);
	ft_free_world(world);
}
