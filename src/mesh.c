/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:46:31 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:46:32 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		(mesh->triangles[i]).a = add((mesh->triangles[i]).a, to);
		(mesh->triangles[i]).b = add((mesh->triangles[i]).b, to);
		(mesh->triangles[i]).c = add((mesh->triangles[i]).c, to);
		i++;
	}
}
