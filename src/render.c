/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:21:42 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 11:40:38 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void render(t_gen gen, FILE *stream)
{
	double	u;
	double	v;
    t_ray	ray_s;
    t_vec3	curcol;
    t_vec3	optimum;
    t_vec3	temp;
	for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
	{
        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            for (size_t samp = 0; samp < 1; samp++)
            {
                if (i % 2 == 0 || 1)
                {
                    u = ((double)(i)) / (IMAGE_WIDTH - 1);
                    v = ((double)(j)) / (IMAGE_HEIGHT - 1);
                    ray_s = cr_ray(gen.cam.origin, direction(gen.cam, u, v));
                    optimum = ray_color(gen, ray_s);
                    temp = optimum;
                }
                else
                    optimum = temp;
                curcol = optimum;
            }
            write_color(stream, curcol, 1);
        }
    }
}