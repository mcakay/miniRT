/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:09 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/04 17:55:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void init_read(t_read *read, char *file)
{
	read->ambient_lightning_amount = 0;
	read->light_amount = 0;
	read->camera_amount = 0;
	read->sphere_head = NULL;
	read->plane_head = NULL;
	read->cylinder_head = NULL;
	read->fd = open(file, O_RDONLY);
	if (read->fd == -1)
		ft_error("Failed to open file", FILE_ERR);
}

void read_file(t_read *read)
{
	char *line;
	char **split;

	line = get_next_line(read->fd);
	while (line)
	{
		split = ft_split(line, ' ');
		if (ft_strncmp(split[0], "A", 2) == 0)
			ambient_lightning_read(read, split);
		else if (ft_strncmp(split[0], "C", 2) == 0)
			camera_read(read, split);
		else if (ft_strncmp(split[0], "L", 2) == 0)
			light_read(read, split);
		else if (ft_strncmp(split[0], "sp", 3) == 0)
			sphere_read(read, split);
		else if (ft_strncmp(split[0], "pl", 3) == 0)
			plane_read(read, split);
		else if (ft_strncmp(split[0], "cy", 3) == 0)
			cylinder_read(read, split);
		ft_free(split);
		free(line);
		line = get_next_line(read->fd);
	}
	close(read->fd);
	check_argument_amount(read);
}
