/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:00 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 06:29:33 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include "get_next_line.h"
# include "libft.h"
# include "vec3d.h"
# include <pthread.h>
# include <fcntl.h>
# include <stdio.h>

//error codes
# define FILE_ERR 1
# define INVALID_ELEMENT_ERR 2
# define INVALID_RANGE_ERR 3
# define INVALID_ARGUMENTS_ERR 4
# define INVALID_INPUT_ERR 5
# define USAGE_ERR 6
# define INVALID_IDENTIFIER_ERR 7
# define INVALID_FILE_EXT_ERR 8

typedef struct s_sphere
{
	t_vec3				xyz;
	double				diameter;
	t_vec3				rgb;
	struct s_sphere		*next;
}						t_sphere;

typedef struct s_plane
{
	t_vec3				xyz;
	t_vec3				orientation;
	t_vec3				rgb;
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	t_vec3				xyz;
	t_vec3				orientation;
	double				diameter;
	double				height;
	t_vec3				rgb;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_read
{
	double				amb_l_ratio;
	t_vec3				amb_l_rgb;
	t_vec3				cam_xyz;
	t_vec3				cam_orient;
	int					cam_fov;
	t_vec3				lg_xyz;
	double				lg_bright;
	t_vec3				lg_rgb;
	t_sphere			*sph_head;
	t_plane				*pl_head;
	t_cylinder			*cyl_head;
	char				*file;
	int					fd;
	int					amb_l_amount;
	int					cam_amount;
	int					lg_amount;
}						t_read;

//read_utils.c
void					ft_free(char **strs);
void					ft_error(char *str, int error_code, int l);
t_vec3					split_vec(char **strs);

//read.c
void					read_file(t_read *read);
void					init_read(t_read *read, char *file);

//read_elements.c
void					ambient_lightning_read(t_read *read, char **split,
							int l);
void					camera_read(t_read *read, char **split, int l);
void					light_read(t_read *read, char **split, int l);

//read_objects.c
void					plane_read(t_read *read, char **split, int l);
void					sphere_read(t_read *read, char **split, int l);
void					cylinder_read(t_read *read, char **split, int l);

//read_insert.c
void					insert_sphere(t_read *read, t_sphere *sphere);
void					insert_plane(t_read *read, t_plane *plane);
void					insert_cylinder(t_read *read, t_cylinder *cylinder);

//read_check.c
void					check_argument_amount(t_read *read, int l);
void					check_range(double min, double max, t_vec3 value,
							int l);
void					check_valid_divided(int expected, char **split, int l);
void					is_rt(char *str);

#endif