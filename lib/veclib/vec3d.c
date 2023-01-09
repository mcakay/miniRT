/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 05:37:26 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 05:37:26 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3d.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_vec3	cross(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = -(a.x * b.z - a.z * b.x);
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_vec3	neg(t_vec3 a)
{
	a.x = -1 * a.x;
	a.y = -1 * a.y;
	a.z = -1 * a.z;
	return (a);
}

t_vec3	unit_vector(t_vec3 v)
{
	return (dvd(v, length(v)));
}
