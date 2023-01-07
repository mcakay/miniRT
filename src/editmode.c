/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editmode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:27:02 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/06 21:27:02 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	call_back(t_ray ray, t_triangle tris, double *value)
{
	int		result;
	t_hit	hit;

	result = intersect_triangle(ray, tris, &hit);
	*value = hit.t;
	return (result);
}
