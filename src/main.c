/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:17 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 03:27:13 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void init_img(t_image *img)
{
	img->aspect_ratio = 16.0 / 9.0;
	img->dir = vec3(0, 0, 1);
	img->fl = 1.0;
	img->fow = 90;
	img->origin = vec3(0, 0, 0);
	img->vup = vec3(0, 1, 0);
}

int main(int argc, char **argv)
{
	t_gen	gen;
	t_image	img;
	t_read	*read;

	if (argc != 2)
		ft_error("Usage: ./miniRT <file.rt>", USAGE_ERR);
	read = malloc(sizeof(t_read));
	init_read(read, argv[1]);
	read_file(read);

	gen.mlx = mlx_init();
	init_img(&img);
	init_cam(&gen, img);
	gen.scene = NULL;
	gen.win = mlx_new_window(gen.mlx, gen.cam.win_x, gen.cam.win_y, "miniRT");
	gen.ambient_ratio = 0.3;
	gen.ambient_color = vec3(0.1, 0.1, 0.1);
	gen.ambient_salt = mpv(gen.ambient_color, 0.5 * gen.ambient_ratio);
	gen.light.center = vec3(0, 0.8, 1);
	gen.light.brightness = 2;
	gen.light.color = vec3(1, 1, 1);
	add_pln(&gen, vec3(0, 0, 3), vec3(1, 0, 0), cyldata(2, 0.4, 1, vec3(0, 0,
					-1)));
	add_pln(&gen, vec3(0, 1, 2), vec3(1, 0, 0), cyldata(0.5, 0.4, 1, vec3(0, -1,
					0)));
	add_pln(&gen, vec3(1, -0, 2), vec3(1, 0, 0), cyldata(0.5, 0.4, 1, vec3(1, 0,
					0)));
	add_pln(&gen, vec3(-1, -0, 2), vec3(1, 0, 0), cyldata(0.5, 0.4, 1, vec3(-1,
					0, 0)));
	add_pln(&gen, vec3(0, -1, 2), vec3(1, 0, 0), cyldata(0.5, 0.4, 1, vec3(0, 1,
					0)));
	add_cyl(&gen, vec3(0, -1, 1.5), vec3(0, 0, 0.8), cyldata(0.2, 0.5, 1,
				vec3(0, 1, 0)));
	add_pln(&gen, vec3(0, 0, 1), vec3(1, 0, 0), cyldata(2, 0.4, 1, vec3(0, 0,
					1)));
	add_sph(&gen, vec3(0, 0, 1.5), vec3(1, 0.4, 0), cyldata(0.2, 0.5, 1, vec3(0,
					1, 0)));
	render(&gen, gen.cam.win_y, gen.cam.win_x);
	mlx_loop(gen.mlx);
	return (0);
}