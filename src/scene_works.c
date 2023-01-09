/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_works.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:08:21 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 02:10:16 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_cyl(t_gen *gen, t_vec3 center, t_vec3 color, t_cyl data)
{
	scene_add_back(&(gen->scene), scene_obj(object("cyl", center, color,
				data)));
}

void	add_sph(t_gen *gen, t_vec3 center, t_vec3 color, t_cyl data)
{
	scene_add_back(&(gen->scene), scene_obj(object("sph", center, color,
				data)));
}

void	add_pln(t_gen *gen, t_vec3 center, t_vec3 color, t_cyl data)
{
	scene_add_back(&(gen->scene), scene_obj(object("pln", center, color,
				data)));
}
