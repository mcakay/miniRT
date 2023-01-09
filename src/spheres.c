/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:12:27 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 03:05:28 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_utils
{
	float	pi;
	float	di;
	float	dj;
	float	db;
	float	da;
	float	i;
	float	j;
}	t_utils;

typedef struct s_square
{
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
	t_vec3	p4;
}	t_square;

t_utils	initutils(void)
{
	t_utils	utils;

	utils.pi = 3.141;
	utils.di = 0.0667;
	utils.dj = 0.1;
	utils.db = utils.di * 2 * utils.pi;
	utils.da = utils.dj * utils.pi;
	utils.i = 0;
	utils.j = 0;
	return (utils);
}

void	put_s(t_utils s, float r, t_mesh *self)
{
	float		a;
	float		b;
	t_square	sq;

	b = s.i * 2 * s.pi;
	a = (s.j - 0.5) * s.pi;
	sq.p1 = vec3(r * cos(a) * cos(b), r * cos(a) * sin(b), r * sin(a));
	sq.p2 = vec3(r * cos(a) * cos(b + s.db),
			r * cos(a) * sin(b + s.db), r * sin(a));
	sq.p3 = vec3(r * cos(a + s.da) * cos(b + s.db),
			r * cos(a + s.da) * sin(b + s.db), r * sin(a + s.da));
	sq.p4 = vec3(r * cos(a + s.da) * cos(b),
			r * cos(a + s.da) * sin(b), r * sin(a + s.da));
	mesh_append(self, triangle(sq.p1, sq.p4, sq.p3));
	mesh_append(self, triangle(sq.p3, sq.p2, sq.p1));
}

void	draw_sphere(double r, t_mesh *self)
{
	t_utils	s;

	s = initutils();
	while (s.i < 1.0)
	{
		s.j = 0;
		while (s.j < 1.0)
		{
			put_s(s, r, self);
			s.j += s.dj;
		}
		s.i += s.di;
	}
}
