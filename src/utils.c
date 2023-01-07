/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:52:12 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 21:26:40 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	to_radians(double degrees)
{
	return (degrees * PI / 180);
}

int	sign(float x)
{
	if (x >= 0)
		return (1);
	return (-1);
}

double max(double x, double y)
{
    if (x > y)
        return x;
    return y;
}
