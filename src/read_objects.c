/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:03 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 14:22:41 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void	sphere_read(t_read *read, char **split)
{
	t_sphere	*sphere;
	t_vec3		rgb;
	char		**sphere_xyz_split;
	char		**sphere_rgb_split;

	check_valid_divided(4, split);
	sphere = malloc(sizeof(t_sphere));
	sphere->next = NULL;
	sphere_xyz_split = ft_split(split[1], ',');
	check_valid_divided(3, sphere_xyz_split);
	sphere->xyz = split_vec(sphere_xyz_split);
	ft_free(sphere_xyz_split);
	sphere->diameter = ft_atod(split[2]);
	sphere_rgb_split = ft_split(split[3], ',');
	check_valid_divided(3, sphere_rgb_split);
	rgb = split_vec(sphere_rgb_split);
	sphere->rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
	check_range(0, 1, sphere->rgb);
	ft_free(sphere_rgb_split);
	insert_sphere(read, sphere);
}

void	plane_read(t_read *read, char **split)
{
	t_plane		*plane;
	t_vec3		rgb;
	char		**plane_xyz_split;
	char		**plane_orientation_split;
	char		**plane_rgb_split;

	check_valid_divided(4, split);
	plane = malloc(sizeof(t_plane));
	plane->next = NULL;
	plane_xyz_split = ft_split(split[1], ',');
	check_valid_divided(3, plane_xyz_split);
	plane->xyz = split_vec(plane_xyz_split);
	ft_free(plane_xyz_split);
	plane_orientation_split = ft_split(split[2], ',');
	check_valid_divided(3, plane_orientation_split);
	plane->orientation = split_vec(plane_orientation_split);
	check_range(-1, 1, plane->orientation);
	ft_free(plane_orientation_split);
	plane_rgb_split = ft_split(split[3], ',');
	check_valid_divided(3, plane_rgb_split);
	rgb = split_vec(plane_rgb_split);
	plane->rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
	check_range(0, 1, plane->rgb);
	ft_free(plane_rgb_split);
	insert_plane(read, plane);
}

void	cylinder_read(t_read *read, char **split)
{
	t_cylinder	*cylinder;
	t_vec3		rgb;
	char		**s;

	check_valid_divided(6, split);
	cylinder = malloc(sizeof(t_cylinder));
	cylinder->next = NULL;
	s = ft_split(split[1], ',');
	check_valid_divided(3, s);
	cylinder->xyz = split_vec(s);
	ft_free(s);
	s = ft_split(split[2], ',');
	check_valid_divided(3, s);
	cylinder->orientation = split_vec(s);
	check_range(-1, 1, cylinder->orientation);
	ft_free(s);
	cylinder->diameter = ft_atod(split[3]);
	cylinder->height = ft_atod(split[4]);
	s = ft_split(split[5], ',');
	check_valid_divided(3, s);
	rgb = split_vec(s);
	cylinder->rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
	check_range(0, 1, cylinder->rgb);
	ft_free(s);
	insert_cylinder(read, cylinder);
}
