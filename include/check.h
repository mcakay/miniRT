/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:50 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 16:56:51 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

#include "utils.h"

#define INT 4
#define DOUBLE 2
#define ARRAY 3
#define VALUE 1

void 	check_range(double min, double max, void *value, int *type);
void	check_valid_divided(int expected, char **split);

#endif