/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:45:57 by ialgac            #+#    #+#             */
/*   Updated: 2023/01/09 06:47:11 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
