/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:02 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 15:35:39 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void ambient_lightning_read(t_read *read, char **split)
{
	char **rgb_split;

	check_valid_divided(3, split);
	rgb_split = ft_split(split[2], ',');
	check_valid_divided(3, rgb_split);
	read->ambient_lightning_ratio = ft_atod(split[1]);
	check_range(0, 1, &read->ambient_lightning_ratio, (int[]){VALUE, DOUBLE});
	read->ambient_lightning_rgb = ft_atoi_array(rgb_split);
	check_range(0, 255, read->ambient_lightning_rgb, (int[]){ARRAY, INT});
	ft_free(rgb_split);
}

void camera_read(t_read *read, char **split)
{
	char **camera_xyz_split;
	char **camera_orientation_split;

	check_valid_divided(4, split);
	camera_xyz_split = ft_split(split[1], ',');
	check_valid_divided(3, camera_xyz_split);
	read->camera_xyz = ft_atod_array(camera_xyz_split);
	ft_free(camera_xyz_split);
	camera_orientation_split = ft_split(split[2], ',');
	check_valid_divided(3, camera_orientation_split);
	read->camera_orientation = ft_atod_array(camera_orientation_split);
	check_range(-1, 1, read->camera_orientation, (int[]){ARRAY, DOUBLE});
	ft_free(camera_orientation_split);
	read->camera_fov = ft_atoi(split[3]);
	check_range(0, 180, &read->camera_fov, (int[]){VALUE, INT});
}

void light_read(t_read *read, char **split)
{
	char **light_xyz_split;
	char **light_rgb_split;

	check_valid_divided(4, split);
	light_xyz_split = ft_split(split[1], ',');
	check_valid_divided(3, light_xyz_split);
	read->light_xyz = ft_atod_array(light_xyz_split);
	ft_free(light_xyz_split);
	read->light_brightness = ft_atod(split[2]);
	check_range(0, 1, &read->light_brightness, (int[]){VALUE, DOUBLE});
	light_rgb_split = ft_split(split[3], ',');
	check_valid_divided(3, light_rgb_split);
	read->light_rgb = ft_atoi_array(light_rgb_split);
	check_range(0, 255, read->light_rgb, (int[]){ARRAY, INT});
	ft_free(light_rgb_split);
}
