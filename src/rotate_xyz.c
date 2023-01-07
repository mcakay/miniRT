/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_xyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:36:58 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 01:14:16 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_x(double *y, double *z, double angle)
{
	float	rad;
	float	sin_a;
	float	cos_a;
	float	new_y;
	float	new_z;

	rad = angle * (PI / 180.0);
	sin_a = sin(rad);
	cos_a = cos(rad);
	new_y = (*y * cos_a) - (*z * sin_a);
	new_z = (*y * sin_a) + (*z * cos_a);
	*y = new_y;
	*z = new_z;
}

void	rotate_y(double *x, double *z, double angle)
{
	float	rad;
	float	sin_a;
	float	cos_a;
	float	new_x;
	float	new_z;

	rad = angle * (PI / 180.0);
	sin_a = sin(rad);
	cos_a = cos(rad);
	new_x = *x * cos_a + *z * sin_a;
	new_z = -*x * sin_a + *z * cos_a;
	*x = new_x;
	*z = new_z;
}

void	rotate_z(double *x, double *y, float angle)
{
	float	rad;
	float	sin_a;
	float	cos_a;
	float	new_x;
	float	new_y;

	rad = angle * (PI / 180.0);
	sin_a = sin(rad);
	cos_a = cos(rad);
	new_x = *x * cos_a - *y * sin_a;
	new_y = *x * sin_a + *y * cos_a;
	*x = new_x;
	*y = new_y;
}
