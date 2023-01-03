#include "read.h"

void ambient_lightning_read(t_read *read, char **split)
{
	char **rgb_split;

	rgb_split = ft_split(split[2], ',');
	read->ambient_lightning_ratio = ft_atod(split[1]);
	read->ambient_lightning_rgb = ft_atoi_array(rgb_split);
	ft_free(rgb_split);
}

void camera_read(t_read *read, char **split)
{
	char **camera_xyz_split;
	char **camera_orientation_split;

	camera_xyz_split = ft_split(split[1], ',');
	read->camera_xyz = ft_atod_array(camera_xyz_split);
	ft_free(camera_xyz_split);
	camera_orientation_split = ft_split(split[2], ',');
	read->camera_orientation = ft_atod_array(camera_orientation_split);
	ft_free(camera_orientation_split);
	read->camera_fov = ft_atoi(split[3]);
}

void light_read(t_read *read, char **split)
{
	char **light_xyz_split;
	char **light_rgb_split;

	light_xyz_split = ft_split(split[1], ',');
	read->light_xyz = ft_atod_array(light_xyz_split);
	ft_free(light_xyz_split);
	read->light_brightness = ft_atod(split[2]);
	light_rgb_split = ft_split(split[3], ',');
	read->light_rgb = ft_atoi_array(light_rgb_split);
	ft_free(light_rgb_split);
}
