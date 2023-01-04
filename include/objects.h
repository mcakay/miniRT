/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:57 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/04 23:01:07 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct s_sphere
{
	double *xyz;
	double diameter;
	int *rgb;
	struct s_sphere *next;
}	t_sphere;

typedef struct s_plane
{
	double *xyz;
	double *orientation;
	int *rgb;
	struct s_plane *next;
}	t_plane;

typedef struct s_cylinder
{
	double *xyz;
	double *orientation;
	double diameter;
	double height;
	int *rgb;
	struct s_cylinder *next;
}	t_cylinder;

#endif