/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:57:59 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 04:20:01 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	direction(t_cam cam, double u, double v)
{
	t_vec3	rtn;

	rtn = sub(mpv(cam.vertical, v), cam.origin);
	rtn = add(mpv(cam.horizontal, u), rtn);
	rtn = add(cam.lower_left, rtn);
	return (rtn);
}

void	init_cam(t_gen *gen, t_image img)
{
	double	theta;
	double	h;
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	theta = to_radians(img.fow);
	h = tan(theta / 2);
	gen->cam.v_h = 2.0 * h;
	gen->cam.v_w = img.aspect_ratio * gen->cam.v_h;
	w = unit_vector(sub(img.origin, img.dir));
	u = unit_vector(cross(img.vup, w));
	v = cross(w, u);
	gen->cam.fl = 1.0;
	gen->cam.origin = img.origin;
	gen->cam.horizontal = mpv(u, gen->cam.v_w);
	gen->cam.vertical = mpv(v, gen->cam.v_h);
	gen->cam.lower_left = add(neg(dvd(gen->cam.vertical, 2)), neg(w));
	gen->cam.lower_left = add(neg(dvd(gen->cam.horizontal, 2)),
			gen->cam.lower_left);
	gen->cam.lower_left = add(img.origin, gen->cam.lower_left);
	gen->cam.win_x = 1024;
	gen->cam.win_y = (int)gen->cam.win_x / img.aspect_ratio;
}
