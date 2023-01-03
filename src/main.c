#include "minirt.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./minirt [scene.rt]\n");
		return (1);
	}
	t_read *read;

	read = malloc(sizeof(t_read));
	init_read(read);
	read_file(read, argv[1]);
	//test
	for (t_sphere *sphere = read->sphere_head; sphere; sphere = sphere->next)
		printf("Sphere: %.2f %.2f %.2f | %.2f | %d %d %d\n", sphere->xyz[0], sphere->xyz[1], sphere->xyz[2], sphere->diameter, sphere->rgb[0], sphere->rgb[1], sphere->rgb[2]);
	for (t_plane *plane = read->plane_head; plane; plane = plane->next)
		printf("Plane: %.2f %.2f %.2f | %.2f %.2f  %.2f | %d %d %d\n", plane->xyz[0], plane->xyz[1], plane->xyz[2], plane->orientation[0], plane->orientation[1], plane->orientation[2], plane->rgb[0], plane->rgb[1], plane->rgb[2]);
	for (t_cylinder *cylinder = read->cylinder_head; cylinder; cylinder = cylinder->next)
		printf("Cylinder: %.2f %.2f %.2f | %.2f %.2f %.2f | %.2f | %d %d %d\n", cylinder->xyz[0], cylinder->xyz[1], cylinder->xyz[2], cylinder->orientation[0], cylinder->orientation[1], cylinder->orientation[2], cylinder->diameter, cylinder->rgb[0], cylinder->rgb[1], cylinder->rgb[2]);
	return (0);
}