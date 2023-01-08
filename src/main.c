/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:17 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/05 11:14:50 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	t_read *read;
	t_camera cam;

	if (argc != 2)
		ft_error("Usage: ./miniRT <file.rt>", USAGE_ERR);
	read = malloc(sizeof(t_read));
	init_read(read, argv[1]);
	read_file(read);
	
	return (0);
}