/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:38:10 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 20:38:10 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	reverse_equation(t_ray ray, t_vec3 point)
{
	double	t;
	double	v;

	t = 0;
	v = 0;
	t += (point.x - ray.origin.x) * ray.direction.x;
	t += (point.y - ray.origin.y) * ray.direction.y;
	t += (point.z - ray.origin.z) * ray.direction.z;
	v += ray.direction.x * ray.direction.x;
	v += ray.direction.y * ray.direction.y;
	v += ray.direction.z * ray.direction.z;
	return (t / v);
}

void	each_intersection(t_gen gen, t_hit *hit, double *tmin, t_ray ray)
{
	int	i;

	i = 0;
	while (i < gen.scene->object.mesh->size)
	{
		if (dot(gen.scene->object.mesh->triangles[i].normal,
				sub(ray.origin, ray.direction)) < 0.0)
		{
			i++;
			continue ;
		}
		if (call_back(ray,
				gen.scene->object.mesh->triangles[i], &(hit->t)))
		{
			if (*tmin == -1 || (hit->t < *tmin && hit->t > 0.0))
			{
				*tmin = hit->t;
				hit->normal = gen.scene->object.mesh->triangles[i].normal;
				hit->obj = &(gen.scene->object);
				hit->color = gen.scene->object.color;
			}
		}
		i++;
	}
}

int	check_intersections(t_gen gen, t_ray ray, t_hit *hit)
{
	double	tmin;

	tmin = -1;
	while (gen.scene)
	{
		each_intersection(gen, hit, &tmin, ray);
		gen.scene = gen.scene->next;
	}
	if (tmin != -1)
	{
		hit->p = ray_on_at(ray, tmin);
		return (1);
	}
	return (0);
}

int	shadow_ray(t_gen gen, t_ray ray, void *not)
{
	t_hit	hit;
	t_scene	*temp;
	int		i;

	temp = gen.scene;
	hit.t = -1;
	while (temp)
	{
		i = -1;
		while (!(&(temp->object) == not) && ++i < temp->object.mesh->size)
		{
			if (call_back(ray,
					temp->object.mesh->triangles[i], &(hit.t)))
			{
				if (hit.t > 0.0)
				{
					if (reverse_equation(ray, gen.light.center) > hit.t)
						return (1);
				}
			}
		}
		temp = temp->next;
	}
	return (0);
}
