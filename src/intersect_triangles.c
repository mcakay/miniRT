/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:06:27 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 03:01:38 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	det_check(t_elements elm, t_hit *hit)
{
	if (elm.det > EPSILON)
	{
		if (hit->u < 0.0 || hit->u > elm.det)
			return (0);
		if (hit->v < 0.0 || (hit->u + hit->v) > elm.det)
			return (0);
	}
	else if (elm.det < -EPSILON)
	{
		if (hit->u > 0.0 || hit->u < elm.det)
			return (0);
		if (hit->v > 0.0 || (hit->u + hit->v) < elm.det)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	intersect_triangle(t_ray ray, t_triangle tri, t_hit *hit)
{
	t_elements	elm;

	elm.edge1 = sub(tri.b, tri.a);
	elm.edge2 = sub(tri.c, tri.a);
	elm.pvec = cross(ray.direction, elm.edge2);
	elm.det = dot(elm.edge1, elm.pvec);
	elm.tvec = sub(ray.origin, tri.a);
	elm.inv_det = 1.0 / elm.det;
	elm.qvec = cross(elm.tvec, elm.edge1);
	hit->u = dot(elm.tvec, elm.pvec);
	hit->v = dot(ray.direction, elm.qvec);
	if (!det_check(elm, hit))
		return (0);
	hit->t = dot(elm.edge2, elm.qvec) * elm.inv_det;
	hit->u *= elm.inv_det;
	hit->v *= elm.inv_det;
	return (1);
}

int	call_back(t_ray ray, t_triangle tris, double *value)
{
	int		result;
	t_hit	hit;

	result = intersect_triangle(ray, tris, &hit);
	*value = hit.t;
	return (result);
}
