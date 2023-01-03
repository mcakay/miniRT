#include "read.h"

void insert_sphere(t_read *read, t_sphere *sphere)
{
	if (read->sphere_head == NULL)
		read->sphere_head = sphere;
	else
	{
		while (read->sphere_head->next != NULL)
			read->sphere_head = read->sphere_head->next;
		read->sphere_head->next = sphere;
	}
}

void insert_plane(t_read *read, t_plane *plane)
{
	if (read->plane_head == NULL)
		read->plane_head = plane;
	else
	{
		while (read->plane_head->next != NULL)
			read->plane_head = read->plane_head->next;
		read->plane_head->next = plane;
	}
}

void insert_cylinder(t_read *read, t_cylinder *cylinder)
{
	if (read->cylinder_head == NULL)
		read->cylinder_head = cylinder;
	else
	{
		while (read->cylinder_head->next != NULL)
			read->cylinder_head = read->cylinder_head->next;
		read->cylinder_head->next = cylinder;
	}
}
