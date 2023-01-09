/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:43:54 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:43:55 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_triangle	triangle(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_triangle	t;

	t.a = v1;
	t.b = v2;
	t.c = v3;
	return (t);
}

void	plane(t_mesh **self, t_cyl *data, t_vec3 center)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
	t_vec3	d;

	*self = mesh();
	a = vec3(-1 * data->size, 0, -1 * data->size);
	b = vec3(1 * data->size, 0, -1 * data->size);
	c = vec3(-1 * data->size, 0, 1 * data->size);
	d = vec3(1 * data->size, 0, 1 * data->size);
	mesh_append(*self, triangle(a, b, d));
	mesh_append(*self, triangle(d, c, a));
	rotate_by_directions(*self, data->dir);
	move_mesh(*self, center);
	calculate_normals(*self);
}

t_object	object(char *name, t_vec3 center, t_vec3 color, t_cyl data)
{
	t_object	obj;

	obj.center = center;
	obj.color = color;
	obj.name = name;
	obj.direction = data.dir;
	if (ft_strncmp("sph", name, ft_strlen(name)) == 0)
	{
		obj.mesh = mesh();
		draw_sphere(data.r, obj.mesh);
		rotate_by_directions(obj.mesh, data.dir);
		move_mesh(obj.mesh, center);
		calculate_normals(obj.mesh);
	}
	else if (ft_strncmp("cyl", name, ft_strlen(name)) == 0)
	{
		cylinder(&(obj.mesh), &data, center);
	}
	else if (ft_strncmp("pln", name, ft_strlen(name)) == 0)
	{
		plane(&(obj.mesh), &data, center);
	}
	return (obj);
}
