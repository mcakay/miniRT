/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:17 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 15:32:48 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_objects(t_gen gen)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	sp = gen.read->sph_head;
	pl = gen.read->pl_head;
	cy = gen.read->cyl_head;
	while (sp)
	{
		add_scene(gen, "sp", (t_vec3[]){sp->xyz, sp->rgb},
			objdata(sp->diameter, 0, 1, vec3(0, 0, 0)));
		sp = sp->next;
	}
	while (pl)
	{
		add_scene(gen, "pl", (t_vec3[]){pl->xyz, pl->rgb},
			objdata(0, 0, 1, pl->orientation));
		pl = pl->next;
	}
	while (cy)
	{
		add_scene(gen, "cy", (t_vec3[]){cy->xyz, cy->rgb},
			objdata(cy->diameter, cy->height, 1, cy->orientation));
		cy = cy->next;
	}
}

t_gen	init_gen(char **argv)
{
	t_gen	gen;

	gen.read = malloc(sizeof(t_read));
	gen.scene = NULL;
	init_read(gen.read, argv[1]);
	read_file(gen.read);
	gen.light.center = gen.read->lg_xyz;
	gen.light.brightness = gen.read->lg_bright;
	gen.light.color = gen.read->lg_rgb;
	gen.ambient_color = gen.read->amb_l_rgb;
	gen.ambient_salt = mpv(gen.ambient_color, gen.read->amb_l_ratio);
	gen.cam = camera(gen.read->cam_xyz,
			gen.read->cam_orient, vec3(0, 1, 0), gen.read->cam_fov);
	return (gen);
}

int	main(int argc, char **argv)
{
	t_gen	gen;
	FILE	*fp;

	if (argc != 2)
		ft_error("Usage: ./miniRT <file.rt>", USAGE_ERR);
	gen = init_gen(argv);
	add_objects(gen);
	fp = openppm("test.ppm", IMAGE_WIDTH, IMAGE_WIDTH / ASPECT_RATIO);
	render(gen, fp);
	fclose(fp);
	return (0);
}
