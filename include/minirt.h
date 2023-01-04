/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:55 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/04 20:40:45 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#define ASPECT_RATIO 16.0 / 9.0
#define IMAGE_WIDTH 1920
#define IMAGE_HEIGHT (int)(IMAGE_WIDTH / ASPECT_RATIO)

#include "read.h"
#include "vec3d.h"

#endif