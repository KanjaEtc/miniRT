/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <adbarth@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:29:29 by adbarth           #+#    #+#             */
/*   Updated: 2026/09/28 12:29:30 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_ray *ft_create_ray (t_tuple *origin, t_tuple *direction)
{
    t_ray *ray = malloc(sizeof(t_ray));
    if (!ray)
        return (NULL);
    ray->origin = origin;
    ray->direction = direction;
    return (ray);
}

// t_sphere *create_sphere (t_tuple *center, double radius)
// {
//     t_sphere *sphere = malloc(sizeof(t_sphere));
//     if (!sphere)
//         return (NULL);
//     sphere->center = center;
//     sphere->radius = radius;
//     return (sphere);
// }

// intersect(sphere, ray)
