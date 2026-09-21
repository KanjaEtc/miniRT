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