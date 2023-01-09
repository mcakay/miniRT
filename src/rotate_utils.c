/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:44:52 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:44:54 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_x(double *y, double *z, double angle)
{
	float	rad;
	float	cos_a;
	float	sin_a;
	float	new_y;
	float	new_z;

	rad = angle * PI / 180.0;
	cos_a = cos(rad);
	sin_a = sin(rad);
	new_y = *y * cos_a - *z * sin_a;
	new_z = *y * sin_a + *z * cos_a;
	*y = new_y;
	*z = new_z;
}

void	rotate_y(double *x, double *z, double angle)
{
	float	rad;
	float	cos_a;
	float	sin_a;
	float	new_x;
	float	new_z;

	rad = angle * PI / 180.0;
	cos_a = cos(rad);
	sin_a = sin(rad);
	new_x = *x * cos_a + *z * sin_a;
	new_z = -*x * sin_a + *z * cos_a;
	*x = new_x;
	*z = new_z;
}

void	rotate_z(double *x, double *y, double angle)
{
	float	rad;
	float	cos_a;
	float	sin_a;
	float	new_y;
	float	new_x;

	rad = angle * PI / 180.0;
	cos_a = cos(rad);
	sin_a = sin(rad);
	new_x = *x * cos_a - *y * sin_a;
	new_y = *x * sin_a + *y * cos_a;
	*x = new_x;
	*y = new_y;
}
