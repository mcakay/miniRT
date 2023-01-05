/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:57 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/05 13:48:53 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "vec3d.h"

typedef struct s_sphere
{
	t_vec3 xyz;
	double diameter;
	t_vec3 rgb;
	struct s_sphere *next;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	xyz;
	t_vec3  orientation;
	t_vec3	rgb;
	struct s_plane *next;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	xyz;
	t_vec3	orientation;
	double	diameter;
	double	height;
	t_vec3	rgb;
	struct s_cylinder *next;
}	t_cylinder;

#endif