/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:45:09 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:45:11 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	rad_to_deg(float rad)
{
	float	degrees;

	degrees = rad * 180.0 / PI;
	return (degrees);
}

int	sign(float x)
{
	if (x >= 0)
	{
		return (1);
	}
	return (-1);
}

t_vec3	direction_to_angle(t_vec3 dir)
{
	double	angle_xy;
	double	angle_yz;
	double	sqrt_result;

	sqrt_result = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	angle_xy = atan2(dir.y, dir.x);
	angle_yz = acos(dir.z / sqrt_result);
	return (vec3(angle_xy * 180.0 / PI, angle_yz * 180.0 / PI, 0));
}

void	rotate(t_mesh *mesh, float angle, int axis)
{
	int	i;

	i = -1;
	while (++i < mesh->size)
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
	}
}

void	rotate_by_directions(t_mesh *mesh, t_vec3 norms)
{
	t_vec3	angles;

	angles = direction_to_angle(norms);
	rotate(mesh, 90 - angles.y, 0);
	rotate(mesh, 90 - angles.x, 2);
}
