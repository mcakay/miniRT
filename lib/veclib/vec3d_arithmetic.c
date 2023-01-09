/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:22:07 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 05:36:52 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3d.h"

t_vec3	add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vec3	sub(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vec3	mp(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result);
}

t_vec3	mpv(t_vec3 a, double c)
{
	t_vec3	result;

	result.x = a.x * c;
	result.y = a.y * c;
	result.z = a.z * c;
	return (result);
}

t_vec3	dvd(t_vec3 a, double c)
{
	t_vec3	result;

	if (c == 0)
	{
		c = 0.001;
	}
	result.x = a.x / c;
	result.y = a.y / c;
	result.z = a.z / c;
	return (result);
}
