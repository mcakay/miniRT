/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:42:21 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:42:22 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	caps(t_vec3 *bot, t_vec3 *top, t_cyl *data, t_mesh *mmes)
{
	int	i;

	i = 0;
	while (i < (SECTOR))
	{
		if (i < (SECTOR - 1))
			mesh_append(mmes, triangle(vec3(0, 0, 0), bot[i + 1], bot[i]));
		else
			mesh_append(mmes, triangle(vec3(0, 0, 0), bot[0], bot[i]));
		i++;
	}
	i = 0;
	while (i < (SECTOR))
	{
		if (i < (SECTOR - 1))
			mesh_append(mmes, triangle(vec3(0, data->h, 0), top[i],
					top[i + 1]));
		else
			mesh_append(mmes, triangle(vec3(0, data->h, 0), top[i], top[0]));
		i++;
	}
	i = 0;
}

void	sectors(t_vec3 *bot, t_vec3 *top, t_mesh *mmes)
{
	t_triangle	rtn;
	int			i;

	i = -1;
	while (++i < (SECTOR))
	{
		if (i < (SECTOR - 1))
			avoid_norm(&rtn, bot, top, i);
		else
		{
			rtn.a = top[0];
			rtn.c = bot[0];
		}
		rtn.b = top[i];
		mesh_append(mmes, rtn);
		if (i < (SECTOR - 1))
			rtn.c = bot[i + 1];
		else
			rtn.c = bot[0];
		rtn.a = top[i];
		rtn.b = bot[i];
		mesh_append(mmes, rtn);
	}
}

t_mesh	*make_cylinder(t_vec3 *bot, t_cyl *data, t_vec3 *top)
{
	t_mesh	*mmes;

	mmes = mesh();
	caps(bot, top, data, mmes);
	sectors(bot, top, mmes);
	return (mmes);
}

int	fill_bottom(t_vec3 *arr, t_cyl *data, int sector_count, float top)
{
	int		i;
	int		h;
	double	degree;
	float	sector_step;

	sector_step = 2 * PI / sector_count;
	h = 0;
	i = 0;
	while (++i <= sector_count)
	{
		degree = i * (sector_step);
		arr[h].x = data->r * cos(degree);
		arr[h].z = data->r * sin(degree);
		arr[h].y = top;
		h++;
	}
	return (h);
}

void	cylinder(t_mesh **self, t_cyl *data, t_vec3 center)
{
	t_vec3	*arr;	
	t_vec3	*arr2;
	int		sector_count;

	sector_count = SECTOR;
	arr = malloc(sizeof(t_vec3) * (sector_count + 1));
	arr2 = malloc(sizeof(t_vec3) * (sector_count + 1));
	fill_bottom(arr, data, sector_count, 0);
	fill_bottom(arr2, data, sector_count, data->h);
	*self = make_cylinder(arr, data, arr2);
	free(arr);
	free(arr2);
	rotate_by_directions(*self, data->dir);
	move_mesh(*self, add(neg(vec3(0, 0, 0)), center));
	calculate_normals(*self);
}
