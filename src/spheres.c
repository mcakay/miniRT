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

//p1, p2, p3, p4
void drawSphere(double r, t_mesh *self)
{
	t_vec3	arr[4];

    for (float i = 0; i < 1.0; i += DI)
	{
		for (float j = 0; j < 1.0; j += DJ)
        {
        	float b = i * 2 * PI;
            float a = (j - 0.5) * PI;
            arr[0] = vec3(r * cos(a) * cos(b),r * cos(a) * sin(b),r * sin(a));
            arr[1] = vec3(r * cos(a) * cos(b + DB), r * cos(a) * sin(b + DB),
				r * sin(a));
            arr[2] = vec3(r * cos(a + DA) * cos(b + DB),
			r * cos(a + DA) * sin(b + DB), r * sin(a + DA));
			arr[3] = vec3(r * cos(a + DA) * cos(b), r * cos(a + DA) * sin(b),
            	r * sin(a + DA));
            t_triangle left = triangle(arr[0], arr[3], arr[2]);
            t_triangle right = triangle(arr[2], arr[1], arr[0]);
            mesh_append(self, left);
            mesh_append(self, right);
        }
	}
}
