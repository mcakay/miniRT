/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:15:06 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 05:21:24 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_gen *gen, int height, int width)
{
	t_render_utils	util;

	util.j = height - 1;
	while (util.j >= 0)
	{
		util.i = -1;
		while (++util.i < width)
		{
			if (util.i % 8 == 0)
			{
				util.u = ((double)(util.i)) / (width - 1);
				util.v = ((double)(util.j)) / (height - 1);
				util.ray_s = cr_ray(gen->cam.origin, direction(gen->cam, util.u,
							util.v));
				util.optimum = ray_color(gen, util.ray_s);
				util.temp = util.optimum;
			}
			else
				util.optimum = util.temp;
			util.curcol = util.optimum;
			write_color(gen, util.curcol, vec3(width - util.i, height - util.j, 0), 1);
			util.h++;
		}
		util.j--;
	}
}
