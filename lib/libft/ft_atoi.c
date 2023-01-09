/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:56:50 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 03:08:36 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read.h"

int check_error(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;
	char 	*tmp;

	i = 0;
	num = 0;
	sign = 1;
	tmp = ft_strtrim(str, "\n");
	if (check_error(tmp))
		ft_error("Invalid input", INVALID_INPUT_ERR);
	if (*(tmp + i) == '-' || *(tmp + i) == '+')
	{
		if (*(tmp + i) == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(*(tmp + i)))
	{
		num = num * 10 + *(tmp + i) - 48;
		i++;
	}
	return (num * sign);
}
