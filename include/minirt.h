/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:55 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/07 11:32:58 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#define ASPECT_RATIO (16.0 / 9.0)
#define IMAGE_WIDTH 1080
#define IMAGE_HEIGHT (IMAGE_WIDTH / ASPECT_RATIO)
#define PI 3.1415926535897932385
#define EPSILON 0.00001
#define DI 0.0667
#define DJ 0.1
#define DB (DI * PI * 2)
#define DA (DJ * PI)

#include "read.h"
#include "vec3d.h"
#include "elements.h"

typedef struct s_point
{
    t_vec3 center;
    double brightness;
    t_vec3 color;
}            t_point;

typedef struct  s_img
{
    int width;
    int height;
    double a_ratio;
}               t_img;

typedef struct s_ray
{
    t_vec3 origin;
    t_vec3 direction;
}               t_ray;

typedef struct s_objdata
{
    t_vec3 origin;
    t_vec3 color;
    t_vec3 dir;
    double r;
    double h;
    double size;

}               t_objdata;

typedef struct s_triangle
{
    t_vec3 a;
    t_vec3 b;
    t_vec3 c;
    t_vec3 normal;
}   t_triangle;

typedef struct s_mesh
{
    t_triangle *triangles;
    int size;
}               t_mesh;

typedef struct s_object
{
    char *name;
    t_mesh *mesh;
    t_vec3 center;
    t_vec3 direction;
    t_vec3 color;
}               t_object;

typedef struct s_scene
{
    t_object object;
    struct s_scene *next;
    struct s_scene *prev;
}               t_scene;

typedef struct s_hit
{
    double t;
    void *obj;
    t_vec3 p;
    t_vec3 normal;
    t_vec3 color;
    int front_face;
    double u;
    double v;
}               t_hit;

typedef struct s_gen
{
	t_read	*read;
	t_scene	*scene;
	t_point light;
	t_vec3	ambient_color;
	t_vec3	ambient_salt;
	t_cam	cam;
}	t_gen;

//utils
double	to_radians(double degrees);
double max(double x, double y);

//elements
t_cam camera(t_vec3 origin, t_vec3 direction, t_vec3 vup, double fov);

//meshes
t_triangle	triangle(t_vec3 v1, t_vec3 v2, t_vec3 v3);
t_object	object(char *name, t_vec3 center, t_vec3 color, t_objdata data);
t_mesh		*mesh(void);
void		move_mesh(t_mesh *mesh, t_vec3 to);
void		mesh_append(t_mesh *self, t_triangle triangle);

//lightning
t_vec3	point_light(t_gen gen, t_hit *h, t_point light, t_vec3 color);

//ray
t_vec3 ray_on_at(t_ray ray, double t);
t_ray cr_ray(t_vec3 origin, t_vec3 direction);
t_vec3	ray_color(t_gen gen, t_ray ray);
t_vec3 direction(t_cam cam, double u, double v);

//cylinder
void cylinder(t_mesh **self, t_objdata *data, t_vec3 center);

//writeppm
FILE	*openppm(const char *name, int width, int height);

//render
void render(t_gen gen, FILE *stream);

//scene
void	add_scene(t_gen gen, char *name,
	t_vec3 *center_and_color, t_objdata data);

//objects
t_objdata	objdata(double radius, double height, double size, t_vec3 dir);
void		calculate_normals(t_mesh *mesh);

//rotate
void	rotate_by_directions(t_mesh *mesh, t_vec3 norms);
void	rotate_x(double *y, double *z, double angle);
void	rotate_y(double *x, double *z, double angle);
void	rotate_z(double *x, double *y, float angle);

//triangle intersection
int	intersect_triangle(t_ray ray, t_triangle tri, t_hit *hit);

//draw sphere
void drawSphere(double r, t_mesh *self);

//raytrace
int	check_intersections(t_gen gen, t_ray ray, t_hit *hit);
int	shadow_ray(t_gen gen, t_ray ray, void *not);

//callback
int	call_back(t_ray ray, t_triangle tris, double *value);

//writeppm
void	write_color(FILE *fd, t_vec3 px_color, int samples);

#endif