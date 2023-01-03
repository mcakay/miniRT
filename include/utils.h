/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:02 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 16:57:03 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#define FILE_ERR 1
#define INVALID_ELEMENT_ERR 2
#define INVALID_RANGE_ERR 3
#define INVALID_ARGUMENTS_ERR 4
#define INVALID_INPUT_ERR 5

void ft_free(char **strs);
void ft_error(char *str, int error_code);
int *ft_atoi_array(char **strs);
double *ft_atod_array(char **strs);

#endif