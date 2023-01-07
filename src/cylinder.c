/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:30:17 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 15:13:47 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mesh	*get_mmes(t_vec3 *bot, t_vec3 *top, t_objdata *data, int sectors)
{
	t_mesh	*mmes;
	int		i;

	mmes = mesh();
	i = 0;
	while (i < (sectors))
	{
		if (i < (sectors - 1))
			mesh_append(mmes, triangle(vec3(0, 0, 0), bot[i + 1], bot[i]));
		else
			mesh_append(mmes, triangle(vec3(0, 0, 0), bot[0], bot[i]));
		i++;
	}
	i = 0;
	while (i < (sectors))
	{
		if (i < (sectors - 1))
			mesh_append(mmes, triangle(vec3(0, data->h,
						0), top[i], top[i + 1]));
		else
			mesh_append(mmes, triangle(vec3(0, data->h, 0), top[i], top[0]));
		i++;
	}
	return (mmes);
}

//i, sectors
void	append_sectors(int iarr[2], t_vec3 *arr, t_vec3 *top, t_vec3 *bot)
{
	if (iarr[0] < (iarr[1] - 1))
	{
		arr[0] = top[iarr[0] + 1];
		arr[2] = bot[iarr[0] + 1];
	}
	else
	{
		arr[0] = top[0];
		arr[2] = bot[0];
	}
}

//a, b, c
t_mesh	*make_cylinder(t_vec3 *bot, t_objdata *data, t_vec3 *top, int sectors)
{
	t_mesh	*mmes;
	t_vec3	arr[3];
	int		i;

	i = 0;
	mmes = get_mmes(bot, top, data, sectors);
	while (i < (sectors))
	{
		append_sectors((int [2]){i, sectors}, arr, top, bot);
		arr[1] = top[i];
		mesh_append(mmes, triangle(arr[0], arr[1], arr[2]));
		if (i < (sectors - 1))
			arr[2] = bot[i + 1];
		else
			arr[2] = bot[0];
		arr[0] = top[i];
		arr[1] = bot[i];
		mesh_append(mmes, triangle(arr[0], arr[1], arr[2]));
		i++;
	}
	free(bot);
	free(top);
	return (mmes);
}

void	cylinder_append(t_vec3 *varr[2],
		t_objdata *data, int iarr[2], double darr[4])
{
	while (++iarr[0] <= SECTOR_COUNT)
	{
		darr[3] = iarr[0] * (2 * PI / SECTOR_COUNT);
		darr[0] = data->r * cos(darr[3]);
		darr[1] = data->r * sin(darr[3]);
		darr[2] = data->h;
		varr[1][iarr[1]] = vec3(darr[0], darr[1], darr[2]);
		iarr[1]++;
	}
	iarr[0] = 0;
	iarr[1] = 0;
	while (++iarr[0] <= SECTOR_COUNT)
	{
		darr[3] = iarr[0] * (2 * PI / SECTOR_COUNT);
		darr[0] = data->r * cos(darr[3]);
		darr[1] = data->r * sin(darr[3]);
		darr[2] = data->h;
		varr[1][iarr[1]] = vec3(darr[0], darr[1], darr[2]);
		iarr[1]++;
	}
}

//arr, arr2 | x, y, z, degree | i, h
void	cylinder(t_mesh **self, t_objdata *data, t_vec3 center)
{
	t_vec3	*varr[2];
	double	darr[4];
	int		iarr[2];

	varr[0] = malloc(sizeof(t_vec3) * (SECTOR_COUNT + 1));
	varr[1] = malloc(sizeof(t_vec3) * (SECTOR_COUNT + 1));
	iarr[0] = 0;
	iarr[1] = 0;
	cylinder_append(varr, data, iarr, darr);
	*self = make_cylinder(varr[0], data, varr[1], SECTOR_COUNT);
	rotate_by_directions(*self, data->dir);
	move_mesh(*self, add(neg(vec3(0, 0, 0)), center));
	calculate_normals(*self);
}
