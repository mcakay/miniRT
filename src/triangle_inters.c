/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_inters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:47:23 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 01:12:11 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	epsilon(double det, t_hit *hit)
{
	if (det > EPSILON)
	{
		if (hit->u < 0.0 || hit->u > det)
			return (0);
		if (hit->v < 0.0 || (hit->u + hit->v) > det)
			return (0);
		return (1);
	}
	else if (det < -EPSILON)
	{
		if (hit->u > 0.0 || hit->u < det)
			return (0);
		if (hit->v > 0.0 || (hit->u + hit->v) < det)
			return (0);
		return (1);
	}
	else
		return (0);
}

//edge1, edge2, tvec, pvec, qvec
int	intersect_triangle(t_ray ray, t_triangle tri, t_hit *hit)
{
	t_vec3	arr[5];
	double	det;
	double	inv_det;

	arr[0] = sub(tri.b, tri.a);
	arr[1] = sub(tri.c, tri.a);
	arr[2] = sub(ray.origin, tri.a);
	arr[3] = cross(ray.direction, arr[1]);
	arr[4] = cross(arr[2], arr[0]);
	det = dot(arr[0], arr[3]);
	inv_det = 1.0 / det;
	hit->u = dot(arr[2], arr[3]);
	hit->v = dot(ray.direction, arr[3]);
	if (!epsilon(det, hit))
		return (0);
	hit->t = dot(arr[1], arr[4]) * inv_det;
	hit->u *= inv_det;
	hit->v *= inv_det;
	return (1);
}
