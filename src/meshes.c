/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meshes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:02 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 22:02:02 by mcakay           ###   ########.fr       */
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

t_mesh	*mesh(void)
{
	t_mesh	*mesh;

	mesh = malloc(sizeof(t_mesh));
	mesh->size = 0;
	mesh->triangles = NULL;
	return (mesh);
}

void	mesh_append(t_mesh *self, t_triangle triangle)
{
	t_triangle	*temp;
	int			i;

	if (!self)
		return ;
	temp = self->triangles;
	self->triangles = malloc(sizeof(t_triangle) * (self->size + 2));
	i = 0;
	while (i < self->size)
	{
		self->triangles[i] = temp[i];
		i++;
	}
	free(temp);
	self->triangles[i] = triangle;
	self->size++;
}

void	move_mesh(t_mesh *mesh, t_vec3 to)
{
	int	i;

	i = 0;
	while (i <= mesh->size)
	{
		mesh->triangles[i].a = add((mesh->triangles[i]).a, to);
		mesh->triangles[i].b = add((mesh->triangles[i]).b, to);
		mesh->triangles[i].c = add((mesh->triangles[i]).c, to);
		i++;
	}
}

//a, b, c, d
void	plane(t_mesh **self, t_objdata *data, t_vec3 center)
{
	t_vec3	arr[4];

	*self = mesh();
	arr[0] = vec3(-1 * data->size, 0, -1 * data->size);
	arr[1] = vec3(1 * data->size, 0, -1 * data->size);
	arr[2] = vec3(-1 * data->size, 0, 1 * data->size);
	arr[3] = vec3(1 * data->size, 0, 1 * data->size);
	mesh_append(*self, triangle(arr[0], arr[1], arr[3]));
	mesh_append(*self, triangle(arr[3], arr[2], arr[0]));
	rotate_by_directions(*self, data->dir);
	move_mesh(*self, center);
	calculate_normals(*self);
}
