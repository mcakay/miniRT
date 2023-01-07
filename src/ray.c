/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:25:40 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:40 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	ray_on_at(t_ray ray, double t)
{
	return (add(ray.origin, mpv(ray.direction, t)));
}

t_ray	cr_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	rtn;

	rtn.origin = origin;
	rtn.direction = direction;
	return (rtn);
}

t_vec3	direction(t_cam cam, double u, double v)
{
	t_vec3	rtn;

	rtn = sub(mpv(cam.vertical, v), cam.origin);
	rtn = add(mpv(cam.horizontal, u), rtn);
	rtn = add(cam.lower_left, rtn);
	return (rtn);
}

t_vec3	ray_color(t_gen gen, t_ray ray)
{
	t_hit	hit;
	t_ray	shadow_r;

	if (check_intersections(gen, ray, &hit))
	{
		shadow_r = cr_ray(hit.p, unit_vector(sub(gen.light.center, hit.p)));
		if (shadow_ray(gen, shadow_r, hit.obj) == 0)
			return (add(point_light(gen, &hit, gen.light, hit.color),
					gen.ambient_salt));
		else
			return (add(vec3(0, 0, 0), gen.ambient_salt));
	}
	return (mpv(gen.ambient_color, 0.8));
}
