/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:44:50 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 14:00:26 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	check_range(double min, double max, void *value, int *type)
{
	int	i;

	i = 0;
	while (i < type[0])
	{
		if (type[1] == INT)
		{
			if (*(int *)value < min || *(int *)value > max)
				ft_error("Invalid range", INVALID_RANGE_ERR);
		}
		else if (type[1] == DOUBLE)
		{
			if (*(double *)value < min || *(double *)value > max)
				ft_error("Invalid range", INVALID_RANGE_ERR);
		}
		i++;
	}
}
