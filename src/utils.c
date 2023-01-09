/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:52:12 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 03:11:06 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	to_radians(double degree)
{
	double	rad;

	rad = (degree * PI) / 180;
	return (rad);
}

double	max(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

void	avoid_norm(t_triangle *tri, t_vec3 *bot, t_vec3 *top, int i)
{
	tri->a = top[i + 1];
	tri->c = bot[i + 1];
}
