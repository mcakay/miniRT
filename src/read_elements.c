/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:02 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 14:24:37 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void	ambient_lightning_read(t_read *read, char **split)
{
	char	**rgb_s;
	t_vec3	rgb;

	check_valid_divided(3, split);
	rgb_s = ft_split(split[2], ',');
	check_valid_divided(3, rgb_s);
	read->amb_l_ratio = ft_atod(split[1]);
	check_range(0, 1, vec3(read->amb_l_amount, 0, 0));
	rgb = split_vec(rgb_s);
	read->amb_l_rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
	check_range(0, 1, read->amb_l_rgb);
	ft_free(rgb_s);
	read->amb_l_amount++;
}

void	camera_read(t_read *read, char **split)
{
	char	**cam_xyz_s;
	char	**cam_orient_s;

	check_valid_divided(4, split);
	cam_xyz_s = ft_split(split[1], ',');
	check_valid_divided(3, cam_xyz_s);
	read->cam_xyz = split_vec(cam_xyz_s);
	ft_free(cam_xyz_s);
	cam_orient_s = ft_split(split[2], ',');
	check_valid_divided(3, cam_orient_s);
	read->cam_orient = split_vec(cam_orient_s);
	check_range(-1, 1, read->cam_orient);
	ft_free(cam_orient_s);
	read->cam_fov = ft_atoi(split[3]);
	check_range(0, 180, vec3(read->cam_fov, 0, 0));
	read->cam_amount++;
}

void	light_read(t_read *read, char **split)
{
	char	**light_xyz_s;
	char	**light_rgb_s;
	t_vec3	rgb;

	check_valid_divided(4, split);
	light_xyz_s = ft_split(split[1], ',');
	check_valid_divided(3, light_xyz_s);
	read->lg_xyz = split_vec(light_xyz_s);
	ft_free(light_xyz_s);
	read->lg_bright = ft_atod(split[2]);
	check_range(0, 1, vec3(read->lg_bright, 0, 0));
	light_rgb_s = ft_split(split[3], ',');
	check_valid_divided(3, light_rgb_s);
	rgb = split_vec(light_rgb_s);
	read->lg_rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
	check_range(0, 1, read->lg_rgb);
	ft_free(light_rgb_s);
	read->lg_amount++;
}
