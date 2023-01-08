/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:44:50 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/05 14:39:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void	check_range(double min, double max, t_vec3 value)
{
	if (value.x < min || value.x > max)
		ft_error("Invalid range", INVALID_ARGUMENTS_ERR);
	if (value.y < min || value.y > max)
		ft_error("Invalid range", INVALID_ARGUMENTS_ERR);
	if (value.z < min || value.z > max)
		ft_error("Invalid range", INVALID_ARGUMENTS_ERR);
}

void	check_valid_divided(int expected, char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	if (i != expected)
		ft_error("Invalid number of arguments", INVALID_ARGUMENTS_ERR);
}

void	check_argument_amount(t_read *read)
{
	if (read->amb_l_amount > 1)
		ft_error("Invalid number of ambient lightning", INVALID_ARGUMENTS_ERR);
	if (read->cam_amount > 1)
		ft_error("Invalid number of camera", INVALID_ARGUMENTS_ERR);
	if (read->lg_amount > 1)
		ft_error("Invalid number of lights", INVALID_ARGUMENTS_ERR);
}
