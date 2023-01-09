/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:23:30 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 05:37:16 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3d.h"

double	distance(t_vec3 u, t_vec3 v)
{
	return (sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2) + pow(u.z - v.z, 2)));
}

double	dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	length_squared(t_vec3 a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

double	length(t_vec3 v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}
