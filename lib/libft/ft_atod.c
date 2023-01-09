/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 05:38:11 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 06:17:48 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read.h"

double	ft_power(int base, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

double	ft_atod(char *str)
{
	char	**split;
	double	result;

	if (ft_strchr(str, '.') == NULL)
		return (ft_atoi(str));
	split = ft_split(str, '.');
	check_valid_divided(2, split, -1);
	if (ft_atoi(split[0]) < 0)
		result = ft_atoi(split[0]) - (double)ft_atoi(split[1])
			/ ft_power(10, ft_strlen(split[1]));
	else
		result = ft_atoi(split[0]) + (double)ft_atoi(split[1])
			/ ft_power(10, ft_strlen(split[1]));
	ft_free(split);
	return (result);
}
