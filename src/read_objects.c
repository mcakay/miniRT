/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:03 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 16:27:03 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void sphere_read(t_read *read, char **split)
{
	t_sphere *sphere;
	char **sphere_xyz_split;
	char **sphere_rgb_split;

	check_valid_divided(4, split);
	sphere = malloc(sizeof(t_sphere));
	sphere->next = NULL;
	sphere_xyz_split = ft_split(split[1], ',');
	check_valid_divided(3, sphere_xyz_split);
	sphere->xyz = ft_atod_array(sphere_xyz_split);
	ft_free(sphere_xyz_split);
	sphere->diameter = ft_atod(split[2]);
	sphere_rgb_split = ft_split(split[3], ',');
	check_valid_divided(3, sphere_rgb_split);
	sphere->rgb = ft_atoi_array(sphere_rgb_split);
	check_range(0, 255, sphere->rgb, (int []){ARRAY, INT});
	ft_free(sphere_rgb_split);
	insert_sphere(read, sphere);
}

void plane_read(t_read *read, char **split)
{
	t_plane *plane;
	char **plane_xyz_split;
	char **plane_orientation_split;
	char **plane_rgb_split;

	check_valid_divided(4, split);
	plane = malloc(sizeof(t_plane));
	plane->next = NULL;
	plane_xyz_split = ft_split(split[1], ',');
	check_valid_divided(3, plane_xyz_split);
	plane->xyz = ft_atod_array(plane_xyz_split);
	ft_free(plane_xyz_split);
	plane_orientation_split = ft_split(split[2], ',');
	check_valid_divided(3, plane_orientation_split);
	plane->orientation = ft_atod_array(plane_orientation_split);
	check_range(-1, 1, plane->orientation, (int []){ARRAY, DOUBLE});
	ft_free(plane_orientation_split);
	plane_rgb_split = ft_split(split[3], ',');
	check_valid_divided(3, plane_rgb_split);
	plane->rgb = ft_atoi_array(plane_rgb_split);
	check_range(0, 255, plane->rgb, (int []){ARRAY, INT});
	ft_free(plane_rgb_split);
	insert_plane(read, plane);
}

void cylinder_read(t_read *read, char **split)
{
	t_cylinder *cylinder;
	char **cylinder_xyz_split;
	char **cylinder_orientation_split;
	char **cylinder_rgb_split;

	check_valid_divided(6, split);
	cylinder = malloc(sizeof(t_cylinder));
	cylinder->next = NULL;
	cylinder_xyz_split = ft_split(split[1], ',');
	check_valid_divided(3, cylinder_xyz_split);
	cylinder->xyz = ft_atod_array(cylinder_xyz_split);
	ft_free(cylinder_xyz_split);
	cylinder_orientation_split = ft_split(split[2], ',');
	check_valid_divided(3, cylinder_orientation_split);
	cylinder->orientation = ft_atod_array(cylinder_orientation_split);
	check_range(-1, 1, cylinder->orientation, (int []){ARRAY, DOUBLE});
	ft_free(cylinder_orientation_split);
	cylinder->diameter = ft_atod(split[3]);
	cylinder->height = ft_atod(split[4]);
	cylinder_rgb_split = ft_split(split[5], ',');
	check_valid_divided(3, cylinder_rgb_split);
	cylinder->rgb = ft_atoi_array(cylinder_rgb_split);
	check_range(0, 255, cylinder->rgb, (int []){ARRAY, INT});
	ft_free(cylinder_rgb_split);
	insert_cylinder(read, cylinder);
}
