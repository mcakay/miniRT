/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:44:40 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:44:41 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*render(void *p)
{
	t_render_utils	util;
	t_th			*t;

	t = (t_th *)p;
	util.j = t->h - t->id - 1;
	util.ray_s.origin = t->gen->cam.origin;
	while (util.j >= 0)
	{
		util.v = ((double)(util.j)) / (t->h - 1);
		util.i = -1;
		while (++util.i < t->w)
		{
			util.u = ((double)(util.i)) / (t->w - 1);
			util.ray_s.direction = direction(t->gen->cam, util.u, util.v);
			util.optimum = ray_color(t->gen, util.ray_s);
			pthread_mutex_lock(t->mutex);
			write_color(t->gen, util.optimum,
				vec3(t->w - util.i, t->h - util.j, 0), 1);
			pthread_mutex_unlock(t->mutex);
			util.h++;
		}
		util.j -= 10;
	}
	return (NULL);
}

void	pre_render(t_gen *gen, int h, int w)
{
	t_th			t[10];
	pthread_mutex_t	m;
	int				i;

	i = 0;
	pthread_mutex_init(&m, NULL);
	while (i < 10)
	{
		t[i].gen = gen;
		t[i].h = h;
		t[i].w = w;
		t[i].id = i;
		t[i].mutex = &m;
		pthread_create(&t[i].thread, NULL, &render, &t[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(t[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&m);
}
