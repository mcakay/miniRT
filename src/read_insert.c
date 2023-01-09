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
	t_sphere	*temp;

	if (read->sph_head == NULL)
		read->sph_head = sphere;
	else
	{
		temp = read->sph_head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = sphere;
	}
}

void	insert_plane(t_read *read, t_plane *plane)
{
	t_plane	*temp;

	if (read->pl_head == NULL)
		read->pl_head = plane;
	else
	{
		temp = read->pl_head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = plane;
	}
}

void	insert_cylinder(t_read *read, t_cylinder *cylinder)
{
	t_cylinder	*temp;

	if (read->cyl_head == NULL)
		read->cyl_head = cylinder;
	else
	{
		temp = read->cyl_head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = cylinder;
	}
}
