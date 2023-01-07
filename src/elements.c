/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:45:39 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/05 10:46:54 by mcakay           ###   ########.fr       */
/*                             s                                               */
/* ************************************************************************** */

#include "minirt.h"

t_cam camera(t_vec3 origin, t_vec3 direction, t_vec3 vup, double fov)
{
	t_cam	cam;
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	w = unit_vector(sub(origin, direction));
	u = unit_vector(cross(vup, w));
	v = cross(w, u);
	cam.fl= 1;
	cam.origin = origin;
	cam.horizontal = mpv(u, cam.v_w);
	cam.vertical = mpv(v, cam.v_h);
	cam.v_h = 2 * tan(to_radians(fov) / 2);
	cam.v_w = ASPECT_RATIO * cam.v_h;
	cam.lower_left = add(neg(dvd(cam.vertical, 2)), neg(w));
    cam.lower_left = add(neg(dvd(cam.horizontal, 2)), cam.lower_left);
    cam.lower_left = add(origin, cam.lower_left);
	return (cam);
}
