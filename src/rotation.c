/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:17:32 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 20:17:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	direction_to_angle(t_vec3 dir)
{
	double	angle_xy_degrees;
	double	angle_yz_degrees;
	double	angle_xz_degrees;
	double	value;

	value = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	angle_xy_degrees = atan2(dir.y, dir.x) * (180.0 / PI);
	angle_yz_degrees = acos(dir.z / value);
	angle_xy_degrees = angle_xy_degrees * (180.0 / PI);
	angle_xz_degrees = atan2(dir.z, dir.x) * (180.0 / PI);
	return (vec3(angle_xy_degrees, angle_yz_degrees, angle_xz_degrees));
}

void	rotate(t_mesh *mesh, float angle, int axis)
{
	int	i;

	i = 0;
	while (i < mesh->size)
	{
		if (axis == 0)
		{
			rotate_x(&mesh->triangles[i].a.y, &mesh->triangles[i].a.z, angle);
			rotate_x(&mesh->triangles[i].b.y, &mesh->triangles[i].b.z, angle);
			rotate_x(&mesh->triangles[i].c.y, &mesh->triangles[i].c.z, angle);
		}
		else if (axis == 1)
		{
			rotate_y(&mesh->triangles[i].a.x, &mesh->triangles[i].a.z, angle);
			rotate_y(&mesh->triangles[i].b.x, &mesh->triangles[i].b.z, angle);
			rotate_y(&mesh->triangles[i].c.x, &mesh->triangles[i].c.z, angle);
		}
		else if (axis == 2)
		{
			rotate_z(&mesh->triangles[i].a.x, &mesh->triangles[i].a.y, angle);
			rotate_z(&mesh->triangles[i].b.x, &mesh->triangles[i].b.y, angle);
			rotate_z(&mesh->triangles[i].c.x, &mesh->triangles[i].c.y, angle);
		}
		i++;
	}
}

void	rotate_by_directions(t_mesh *mesh, t_vec3 norms)
{
	t_vec3	angles;

	angles = direction_to_angle(norms);
	rotate(mesh, 90 - angles.y, 0);
	rotate(mesh, 90 - angles.x, 2);
}
