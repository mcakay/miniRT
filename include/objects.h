/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:57 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/04 17:43:36 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct sphere
{
	double *xyz;
	double diameter;
	int *rgb;
	struct sphere *next;
}	t_sphere;

typedef struct plane
{
	double *xyz;
	double *orientation;
	int *rgb;
	struct plane *next;
}	t_plane;

typedef struct cylinder
{
	double *xyz;
	double *orientation;
	double diameter;
	double height;
	int *rgb;
	struct cylinder *next;
}	t_cylinder;

#endif