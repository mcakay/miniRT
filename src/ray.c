/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:10:31 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 03:02:40 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	cr_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	rtn;

	rtn.origin = origin;
	rtn.direction = direction;
	return (rtn);
}

t_vec3	ray_on_at(t_ray ray, double t)
{
	return (add(ray.origin, mpv(ray.direction, t)));
}

t_vec3	ray_color(t_gen *gen, t_ray ray)
{
	t_hit	hit;
	t_ray	shadow_r;

	if (check_intersections(gen->scene, ray, &hit))
	{
		shadow_r = cr_ray(hit.p, unit_vector(sub(gen->light.center, hit.p)));
		if (shadow_ray(gen->light.center, gen->scene, shadow_r, hit.obj) == 0)
		{
			return (add(point_light(gen, &hit, gen->light, hit.color),
					gen->ambient_salt));
		}
		else
		{
			return (point_light(gen, &hit, gen->light, add(mpv(hit.color, 0.2),
						gen->ambient_salt)));
		}
	}
	return (mpv(gen->ambient_color, 0.8));
}
