/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:55 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/05 11:06:46 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#define ASPECT_RATIO 16.0 / 9.0
#define IMAGE_WIDTH 1920
#define IMAGE_HEIGHT (int)(IMAGE_WIDTH / ASPECT_RATIO)
#define PI 3.1415926535897932385

#include "read.h"
#include "vec3d.h"
#include "elements.h"

//utils
double	to_radians(double degrees);

//elements
t_camera camera(t_vec3 origin, t_vec3 direction, t_vec3 vup, double fov);

#endif