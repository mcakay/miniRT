/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:20 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 05:33:13 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void	insert_sphere(t_read *read, t_sphere *sphere)
{
	if (read->sph_head == NULL)
		read->sph_head = sphere;
	else
	{
		while (read->sph_head->next != NULL)
			read->sph_head = read->sph_head->next;
		read->sph_head->next = sphere;
	}
}

void	insert_plane(t_read *read, t_plane *plane)
{
	if (read->pl_head == NULL)
		read->pl_head = plane;
	else
	{
		while (read->pl_head->next != NULL)
			read->pl_head = read->pl_head->next;
		read->pl_head->next = plane;
	}
}

void	insert_cylinder(t_read *read, t_cylinder *cylinder)
{
	if (read->cyl_head == NULL)
		read->cyl_head = cylinder;
	else
	{
		while (read->cyl_head->next != NULL)
			read->cyl_head = read->cyl_head->next;
		read->cyl_head->next = cylinder;
	}
}
