/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:00 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 16:57:00 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "check.h"
#include "objects.h"

typedef struct s_read
{
	double ambient_lightning_ratio;
	int *ambient_lightning_rgb;
	double *camera_xyz;
	double *camera_orientation;
	int camera_fov;
	double *light_xyz;
	double light_brightness;
	int *light_rgb;
	t_sphere *sphere_head;
	t_plane *plane_head;
	t_cylinder *cylinder_head;
}	t_read;

void read_file(t_read *read, char *file);
void init_read(t_read *read);
void ambient_lightning_read(t_read *read, char **split);
void camera_read(t_read *read, char **split);
void light_read(t_read *read, char **split);
void plane_read(t_read *read, char **split);
void sphere_read(t_read *read, char **split);
void cylinder_read(t_read *read, char **split);
void insert_sphere(t_read *read, t_sphere *sphere);
void insert_plane(t_read *read, t_plane *plane);
void insert_cylinder(t_read *read, t_cylinder *cylinder);

#endif