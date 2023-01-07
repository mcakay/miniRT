/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:30:17 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 10:16:48 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//a, b, c
t_mesh	*make_cylinder(t_vec3 *bot, t_objdata *data, t_vec3 *top, int sectors)
{
	t_mesh	*mmes;
	t_vec3	arr[3];
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
            mesh_append(mmes, triangle(vec3(0, data->h,0), top[i], top[i + 1]));        
        else
            mesh_append(mmes, triangle(vec3(0, data->h,0), top[i], top[0])); 
        i++;
    }
    i = 0;
    while (i < (sectors))
    {
        if (i < (sectors - 1))
        {
            arr[0] = top[i + 1];
            arr[2] = bot[i + 1];
        }
        else
        {
            arr[0] =  top[0];
            arr[2] =  bot[0];
        }
        arr[1] = top[i];
        mesh_append(mmes, triangle(arr[0], arr[1], arr[2]));
        if (i < (sectors - 1))
        {
            arr[2] = bot[i + 1];
        }
        else 
            arr[2] = bot[0];        
        arr[0] = top[i];
        arr[1] = bot[i];
        mesh_append(mmes, triangle(arr[0], arr[1], arr[2]));
        i++;
    }
    free(bot);
    free(top);
    return mmes;
}

void cylinder(t_mesh **self, t_objdata *data, t_vec3 center)
{
    t_vec3 *arr;
    t_vec3 *arr2;
    double degree;
    int sectorCount = 20;
    float sectorStep = 2 * PI / sectorCount;
    double x;
    double y;
    double z;
    int h;
    degree = 0;
    h = 0;
    int i;
    arr = malloc(sizeof(t_vec3) * (sectorCount + 1));
    arr2 = malloc(sizeof(t_vec3) * (sectorCount + 1));
    i = 0;
    h = 0;
    while (++i <= sectorCount)
    {
		degree = i * (sectorStep);
		x = data->r * cos(degree);
		y = data->r * sin(degree);
		z = 0;
		arr[h] = vec3(x, z, y);
		h++;
	}
	h = 0;
	i = 0;
	while (++i <= sectorCount)
	{
		degree = i * sectorStep;
		x = data->r * cos(degree);
		y = data->r * sin(degree);
		z = data->h;
		arr2[h] = vec3(x, z, y);
		h++;
	}
	*self = make_cylinder(arr, data, arr2, sectorCount);
	rotate_by_directions(*self, data->dir);
	move_mesh(*self, add(neg(vec3(0, 0, 0)), center));
	calculate_normals(*self);
}
