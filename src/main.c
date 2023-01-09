/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:43:09 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:43:10 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_img(t_image *img)
{
	img->aspect_ratio = 16.0 / 9.0;
	img->dir = vec3(0, 0, 1);
	img->fl = 1.0;
	img->fow = 90;
	img->origin = vec3(0, 0, 0);
	img->vup = vec3(0, 1, 0);
}

void	add_objects(t_gen *gen, t_read *read)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cl;

	sp = read->sph_head;
	pl = read->pl_head;
	cl = read->cyl_head;
	while (sp)
	{
		add_sph(gen, sp->xyz, sp->rgb, cyldata(sp->diameter, 0, 0,
				vec3(0, 0, -1)));
		sp = sp->next;
	}
	while (pl)
	{
		add_pln(gen, pl->xyz, pl->rgb, cyldata(0, 0, 15, pl->orientation));
		pl = pl->next;
	}
	while (cl)
	{
		add_cyl(gen, cl->xyz, cl->rgb, cyldata(cl->diameter, cl->height, 0,
				cl->orientation));
		cl = cl->next;
	}
}

void	init_light(t_gen *gen, t_read *read)
{
	if (read->amb_l_amount)
	{
		gen->ambient_ratio = read->amb_l_ratio;
		gen->ambient_color = read->amb_l_rgb;
		gen->ambient_salt = mpv(gen->ambient_color, 0.5 * gen->ambient_ratio);
	}
	if (read->lg_amount != 0)
	{
		gen->light.center = read->lg_xyz;
		gen->light.brightness = read->lg_bright * 10;
		gen->light.color = read->lg_rgb;
	}
	else if (read->amb_l_amount)
	{
		gen->light.center = vec3(0, 0, 0);
		gen->light.brightness = 0.05;
		gen->light.color = gen->ambient_color;
	}
}

void	init_gen(t_gen *gen, t_read *read, t_image *img)
{
	gen->mlx = mlx_init();
	init_img(img);
	init_cam(gen, *img);
	gen->scene = NULL;
	gen->win = mlx_new_window(gen->mlx, gen->cam.win_x, gen->cam.win_y,
			"miniRT");
	gen->light.center = vec3(0, 0, 0);
	gen->light.brightness = 0.05;
	gen->light.color = vec3(0.01, 0.01, 0.01);
	gen->ambient_color = vec3(0.01, 0.01, 0.01);
	gen->ambient_ratio = 0.001;
	init_light(gen, read);
}

int	main(int argc, char **argv)
{
	t_gen	gen;
	t_image	img;
	t_read	*read;

	if (argc != 2)
		ft_error("Usage: ./miniRT <file.rt>", USAGE_ERR, -1);
	read = malloc(sizeof(t_read));
	init_read(read, argv[1]);
	read_file(read);
	init_gen(&gen, read, &img);
	add_objects(&gen, read);
	pre_render(&gen, gen.cam.win_y, gen.cam.win_x);
	mlx_hook(gen.win, 17, 0, &xbutton, &gen);
	mlx_hook(gen.win, 2, 0, &key, &gen);
	mlx_loop(gen.mlx);
	return (0);
}
