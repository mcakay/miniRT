/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:28:06 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 21:28:06 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	point_light(t_gen gen, t_hit *h, t_point light, t_vec3 color)
{
	double	rtn;
	double	dist;
	t_vec3	ld;

	ld = add((light.center), neg(h->p));
	ld = dvd(ld, length(sub(light.center, h->p)));
	rtn = max(dot(h->normal, ld), 0);
	rtn = rtn * light.brightness;
	dist = length_squared(sub(light.center, h->p));
	ld = dvd(mp(mpv(color, rtn), add(light.color, gen.read->amb_l_rgb)), dist);
	return (ld);
}
