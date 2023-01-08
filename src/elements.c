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

t_camera camera(t_vec3 origin, t_vec3 direction, t_vec3 vup, double fov)
{
	t_camera camera;
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	w = unit_vector(sub(origin, direction));
	u = unit_vector(cross(vup, w));
	v = cross(w, u);
	camera.focal_length = 1;
	camera.origin = origin;
	camera.horizontal = mpv(u, camera.v_width);
	camera.vertical = mpv(v, camera.v_height);
	camera.v_height = 2 * tan(to_radians(fov) / 2);
	camera.v_width = ASPECT_RATIO * camera.v_height;
	camera.lower_left = add(neg(dvd(camera.vertical, 2)), neg(w));
    camera.lower_left = add(neg(dvd(camera.horizontal, 2)), camera.lower_left);
    camera.lower_left = add(origin, camera.lower_left);
	return (camera);
}
