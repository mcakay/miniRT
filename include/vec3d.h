#ifndef VEC3D_H
# define VEC3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_vec3
{
	double x;
	double y;
	double z;
}				t_vec3;

t_vec3 vec3(double x, double y, double z);
t_vec3 unit_vector(t_vec3 v);
double length(t_vec3 v);
t_vec3 add(t_vec3 a, t_vec3 b);
t_vec3 sub(t_vec3 a, t_vec3 b);
t_vec3 mp(t_vec3 a, t_vec3 b);
t_vec3 mpv(t_vec3 a, double c);
t_vec3 dvd(t_vec3 a, double c);
t_vec3 cross(t_vec3 a, t_vec3 b);
t_vec3 neg(t_vec3 a);
double dot(t_vec3 a, t_vec3 b);
double distance(t_vec3 u, t_vec3 v);
double length_squared(t_vec3 a);

#endif