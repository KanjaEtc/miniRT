#include "../include/header.h"

t_ray *create_ray (t_tuple *origin, t_tuple *direction)
{
    t_ray *ray = malloc(sizeof(t_ray));
    if (!ray)
        return (NULL);
    ray->origin = origin;
    ray->direction = direction;
    return (ray);
}

t_sphere *create_sphere (t_tuple *center, double radius)
{
    t_sphere *sphere = malloc(sizeof(t_sphere));
    if (!sphere)
        return (NULL);
    sphere->center = center;
    sphere->radius = radius;
    return (sphere);
}

intersect(sphere, ray)