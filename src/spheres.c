/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:12:23 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 20:12:23 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calculate_array(t_vec3 arr[4], double f[4], double r)
{
	arr[0] = vec3(r * cos(f[2]) * cos(f[3]),
			r * cos(f[2]) * sin(f[2]), r * sin(f[2]));
	arr[1] = vec3(r * cos(f[2]) * cos(f[3] + (DI * PI * 2)),
			r * cos(f[2]) * sin(f[2] + (DI * PI * 2)),
			r * sin(f[2]));
	arr[2] = vec3(r * cos(f[2] + (DJ * PI)) * cos(f[3] + (DI * PI * 2)),
			r * cos(f[2] + (DJ * PI)) * sin(f[3] + (DI * PI * 2)),
			r * sin(f[2] +(DJ * PI)));
	arr[3] = vec3(r * cos(f[2] + (DJ * PI)) * cos(f[3]),
			r * cos(f[2] + (DJ * PI)) * sin(f[3]),
			r * sin(f[2] + (DJ * PI)));
}

//p1, p2, p3, p4 | i, j, a, b | left, right
void	draw_sphere(double r, t_mesh *self)
{
	t_vec3		arr[4];
	double		f[4];
	t_triangle	t[2];

	f[0] = 0;
	while (f[0] < 1.0)
	{
		f[1] = 0;
		while (f[1] < 1.0)
		{
			f[2] = (f[1] - 0.5) * PI;
			f[3] = f[0] * 2 * PI;
			calculate_array(arr, f, r);
			t[0] = triangle(arr[0], arr[3], arr[2]);
			t[1] = triangle(arr[2], arr[1], arr[0]);
			mesh_append(self, t[0]);
			mesh_append(self, t[1]);
			f[1] += DJ;
		}
		f[0] += DI;
	}
}
