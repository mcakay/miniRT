/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:17:12 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 22:17:12 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*scene_obj(t_object object)
{
	t_scene	*rtn;
	size_t	size;

	size = sizeof(t_scene);
	rtn = malloc(size + 4);
	rtn->next = NULL;
	rtn->prev = NULL;
	rtn->object = object;
	return (rtn);
}

void	scene_add_back(t_scene **self, t_scene *newscn)
{
	t_scene	*temp;

	if (*self == NULL)
	{
		*self = newscn;
		return ;
	}
	temp = *self;
	while (temp->next)
		temp = temp->next;
	temp->next = newscn;
}

void	calculate_normals(t_mesh *mesh)
{
	t_vec3	ab;
	t_vec3	ac;
	t_vec3	norm;
	int		i;

	i = 0;
	while (i < mesh->size)
	{
		ab = sub((mesh->triangles[i].a), mesh->triangles[i].b);
		ac = sub((mesh->triangles[i].a), mesh->triangles[i].c);
		norm = unit_vector(cross(ac, ab));
		(mesh->triangles[i]).normal = norm;
		i++;
	}
}

t_objdata	objdata(double radius, double height, double size, t_vec3 dir)
{
	t_objdata	cyldata;

	cyldata.dir = dir;
	cyldata.r = radius;
	cyldata.h = height;
	cyldata.size = size;
	return (cyldata);
}

void	add_scene(t_gen gen, char *name,
	t_vec3 *center_and_color, t_objdata data)
{
	scene_add_back(&(gen.scene),
		scene_obj(object(name,
				center_and_color[0],
				center_and_color[1],
				data)));
}
