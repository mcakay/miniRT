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