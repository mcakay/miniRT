/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:55 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 05:28:22 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# define PI 3.1415926
# define MYRAND_MAX 0xFFFF
# define IMAX 2147483647
# define EPSILON 0.000001
# define SECTOR 25
# define KEY_ESC 53

#include "read.h"
#include "mlx.h"

typedef struct s_point
{
	t_vec3			center;
	double			brightness;
	t_vec3			color;
}					t_point;

typedef struct s_img
{
	int				width;
	int				height;
	double			a_ratio;

}					t_img;

typedef struct s_cyl
{
	t_vec3			origin;
	t_vec3			color;
	t_vec3			dir;
	double			r;
	double			h;
	double			size;

}					t_cyl;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef struct s_triangle
{
	t_vec3			a;
	t_vec3			b;
	t_vec3			c;
	t_vec3			normal;
}					t_triangle;

typedef struct s_mesh
{
	t_triangle		*triangles;
	int				size;
}					t_mesh;

typedef struct s_object
{
	char			*name;
	t_mesh			*mesh;
	t_vec3			center;
	t_vec3			direction;
	t_vec3			color;
}					t_object;

typedef struct s_scene
{
	t_object		object;
	struct s_scene	*next;
	struct s_scene	*prev;
}					t_scene;

typedef struct s_cam
{
	double			v_h;
	double			v_w;
	double			fl;
	t_vec3			origin;
	t_vec3			horizontal;
	t_vec3			vertical;
	t_vec3			lower_left;
	int				win_x;
	int				win_y;
}					t_cam;

typedef struct s_gen
{
	t_cam			cam;
	t_point			light;
	t_vec3			ambient_color;
	double			ambient_ratio;
	t_vec3			ambient_salt;
	t_scene			*scene;
	void			*mlx;
	void			*win;
}					t_gen;

typedef struct s_hit
{
	double			t;
	void			*obj;
	t_vec3			p;
	t_vec3			normal;
	t_vec3			color;
	int				front_face;
	double			u;
	double			v;
}					t_hit;

typedef struct s_image
{
	double			aspect_ratio;
	t_vec3			origin;
	t_vec3			dir;
	t_vec3			vup;
	float			fow;
	float			fl;
}					t_image;

typedef struct s_elements
{
	t_vec3			edge1;
	t_vec3			edge2;
	t_vec3			tvec;
	t_vec3			pvec;
	t_vec3			qvec;
	double			det;
	double			inv_det;
}					t_elements;

typedef struct s_render_utils
{
	int		i;
	int		j;
	int		h;
	double	u;
	double	v;
	t_vec3	curcol;
	t_vec3	optimum;
	t_vec3	temp;
	t_ray	ray_s;
}	t_render_utils;

double				to_radians(double degrees);
void				write_color(t_gen *gen, t_vec3 px_color, t_vec3 xy, int samples);
int					write_ppm(int red, int green, int blue, FILE *fd);
void				draw_sphere(double r, t_mesh *self);
double				max(double x, double y);
float				rad_to_deg(float rad);
void				rotate(t_mesh *mesh, float angle, int axis);
void				rotate_by_directions(t_mesh *mesh, t_vec3 norms);
t_vec3				direction_to_angle(t_vec3 dir);
void				render(t_gen *gen, int height, int width);
int					shadow_ray(t_vec3 l, t_scene *temp, t_ray ray, void *not);
int					check_intersections(t_scene *temp, t_ray ray, t_hit *hit);
t_vec3				ray_color(t_gen *gen, t_ray ray);
t_vec3				ray_on_at(t_ray ray, double t);
t_ray				cr_ray(t_vec3 origin, t_vec3 direction);
void				scene_add_back(t_scene **self, t_scene *newscn);
t_scene				*scene_obj(t_object object);
void				add_pln(t_gen *gen, t_vec3 center, t_vec3 color,
						t_cyl data);
void				add_sph(t_gen *gen, t_vec3 center, t_vec3 color,
						t_cyl data);
void				add_cyl(t_gen *gen, t_vec3 center, t_vec3 color,
						t_cyl data);
t_cyl				cyldata(double radius, double height, double size,
						t_vec3 dir);
void				calculate_normals(t_mesh *mesh);
void				move_mesh(t_mesh *mesh, t_vec3 to);
void				mesh_append(t_mesh *self, t_triangle triangle);
t_mesh				*mesh(void);
t_triangle			triangle(t_vec3 v1, t_vec3 v2, t_vec3 v3);
t_object			object(char *name, t_vec3 center, t_vec3 color, t_cyl data);
t_vec3				point_light(t_gen *gen, t_hit *h, t_point light,
						t_vec3 color);
int					call_back(t_ray ray, t_triangle tris, double *value);
int					det_check(t_elements elm, t_hit *hit);
int					intersect_triangle(t_ray ray, t_triangle tri, t_hit *hit);
double				to_radians(double degree);
void				init_cam(t_gen *gen, t_image img);
void				cylinder(t_mesh **self, t_cyl *data, t_vec3 center);
t_vec3				direction(t_cam cam, double u, double v);
void				avoid_norm(t_triangle *tri, t_vec3 *bot, t_vec3 *top, int i);
void				rotate_x(double *y, double *z, double angle);
void				rotate_y(double *x, double *z, double angle);
void				rotate_z(double *x, double *y, double angle);
int					xbutton(t_gen *gen);
int					key(int keycode, t_gen *gen);

#endif