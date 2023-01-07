/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:21:42 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 15:34:45 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//u, v | i, j
void	render(t_gen gen, FILE *stream)
{
	double	d[2];
	t_ray	ray_s;
	t_vec3	optimum;
	int		i[2];

	i[1] = (IMAGE_WIDTH / ASPECT_RATIO) - 1;
	while (i[1] > 0)
	{
		i[0] = 0;
		while (i[0] < IMAGE_WIDTH)
		{
			d[0] = ((double)(i[0])) / (IMAGE_WIDTH - 1);
			d[1] = ((double)(i[1])) / ((IMAGE_WIDTH / ASPECT_RATIO) - 1);
			ray_s = cr_ray(gen.cam.origin, direction(gen.cam, d[0], d[1]));
			optimum = ray_color(gen, ray_s);
			++i[0];
			write_color(stream, optimum, 1);
		}
		--i[1];
	}
}
