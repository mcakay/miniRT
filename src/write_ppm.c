/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:46:16 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:47:04 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	my_clamp(double num, double low, double high)
{
	if (num < low)
		return (low);
	else if (num > high)
		return (high);
	return (num);
}

int	rgb_to_int(int r, int g, int b)
{
	int	rtn;

	rtn = b;
	rtn += g * 256;
	rtn += r * 256 * 256;
	return (rtn);
}

void	write_color(t_gen *gen, t_vec3 px_color, t_vec3 xy, int samples)
{
	double	r;
	double	g;
	double	b;
	double	scl;
	int		color;

	scl = 1.0 / samples;
	r = sqrt(scl * px_color.x);
	g = sqrt(scl * px_color.y);
	b = sqrt(scl * px_color.z);
	color = rgb_to_int(
			(int)(255.999 * my_clamp(r, 0.0, 0.999)),
			(int)(255.999 * my_clamp(g, 0.0, 0.999)),
			(int)(255.999 * my_clamp(b, 0.0, 0.999)));
	mlx_pixel_put(gen->mlx, gen->win, xy.x, xy.y, color);
}
