/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:44:20 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:44:21 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	reverse_equation(t_ray ray, t_vec3 point)
{
	double	t;
	double	p;

	t = (point.x - ray.origin.x) * ray.direction.x
		+ (point.y - ray.origin.y) * ray.direction.y
		+ (point.z - ray.origin.z) * ray.direction.z;
	p = ray.direction.x * ray.direction.x
		+ ray.direction.y * ray.direction.y
		+ ray.direction.z * ray.direction.z;
	return (t / p);
}

void	put_info(double *tmin, t_hit *hit, t_scene *temp, int i)
{
	if (*tmin == -1 || (hit->t < *tmin && hit->t > 0.0))
	{
		*tmin = hit->t;
		hit->normal = temp->object.mesh->triangles[i].normal;
		hit->obj = &(temp->object);
		hit->color = temp->object.color;
	}
}

int	check_intersections(t_scene *temp, t_ray ray, t_hit *hit)
{
	double	tmin;
	int		i;

	tmin = -1;
	while (temp)
	{
		i = -1;
		while (++i < temp->object.mesh->size)
		{
			if (dot(temp->object.mesh->triangles[i].normal, sub(ray.origin,
						ray.direction)) < 0.0)
				continue ;
			if (call_back(ray, temp->object.mesh->triangles[i], &hit->t))
				put_info(&tmin, hit, temp, i);
		}
		temp = temp->next;
	}
	if (tmin != -1)
	{
		hit->p = ray_on_at(ray, tmin);
		return (1);
	}
	return (0);
}

int	shadow_ray(t_vec3 l, t_scene *temp, t_ray ray, void *not)
{
	t_hit	hit;
	int		i;
	double	t;

	hit.t = -1;
	while (temp)
	{
		i = 0;
		while (!(&(temp->object) == not) && i < temp->object.mesh->size)
		{
			if (call_back(ray, temp->object.mesh->triangles[i], &(hit.t)))
			{
				if (hit.t > 0.0)
				{
					t = reverse_equation(ray, l);
					if (t > hit.t)
						return (1);
				}
			}
			i++;
		}
		temp = temp->next;
	}
	return (0);
}
