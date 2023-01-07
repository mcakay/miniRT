/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:40:34 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 19:40:34 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

FILE	*openppm(const char *name, int width, int height)
{
	FILE	*fp;

	fp = fopen(name, "w");
	fprintf(fp, "P3\n %d %d \n%d\n", width, height, 255);
	return (fp);
}

double	my_clamp(double num, double low, double high)
{
	if (num < low)
		return (low);
	else if (num > high)
		return (high);
	return (num);
}

void	write_color(FILE *fd, t_vec3 px_color, int samples)
{
	double	r;
	double	g;
	double	b;
	double	scl;

	scl = 1.0 / samples;
	r = px_color.x;
	g = px_color.y;
	b = px_color.z;
	r = sqrt(scl * r);
	g = sqrt(scl * g);
	b = sqrt(scl * b);
	unsigned ri = (unsigned)(255.999 * my_clamp(r, 0.0, 0.999));
	unsigned gi = (unsigned)(255.999 * my_clamp(g, 0.0, 0.999));
	unsigned bi = (unsigned)(255.999 * my_clamp(b, 0.0, 0.999));
	fprintf(fd, "%u %u %u\n", ri, gi, bi);
}

int	write_ppm(int red, int green, int blue, FILE *fd)
{
	if (red < 0 || green < 0 || blue < 0)
	{
		red = 0;
		green = 0;
		blue = 0;
	}
	if (red > 255 || green > 255 || blue > 255)
	{
		red = 255;
		green = 255;
		blue = 255;
	}
	fprintf(fd, "%d %d %d\n", red, green, blue);
	return (1);
}
