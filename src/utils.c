/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:52:12 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 05:42:24 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../lib/minilibx/minilibx/mlx.h"

double	to_radians(double degree)
{
	double	rad;

	rad = (degree * PI) / 180;
	return (rad);
}

double	max(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

void	avoid_norm(t_triangle *tri, t_vec3 *bot, t_vec3 *top, int i)
{
	tri->a = top[i + 1];
	tri->c = bot[i + 1];
}

int	key(int keycode, t_gen *gen)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(gen->mlx, gen->win);
		exit(0);
	}
	return (0);
}

int	xbutton(t_gen *gen)
{
	mlx_destroy_window(gen->mlx, gen->win);
	exit(0);
	return (0);
}
