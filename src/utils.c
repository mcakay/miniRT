/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:12 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 16:27:12 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void ft_free(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void ft_error(char *str, int error_code)
{
	printf("Error: %s\n", str);
	exit(error_code);
}

int *ft_atoi_array(char **strs)
{
	int *result;
	int i;

	result = malloc(sizeof(int) * 3);
	i = 0;
	while (i < 3)
	{
		result[i] = ft_atoi(strs[i]);
		i++;
	}
	return (result);
}

double *ft_atod_array(char **strs)
{
	double *result;
	int i;

	result = malloc(sizeof(double) * 3);
	i = 0;
	while (i < 3)
	{
		result[i] = ft_atod(strs[i]);
		i++;
	}
	return (result);
}
