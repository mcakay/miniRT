/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:09 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/03 16:27:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void init_read(t_read *read)
{
	read->sphere_head = NULL;
	read->plane_head = NULL;
	read->cylinder_head = NULL;
}

void read_file(t_read *read, char *file)
{
	int fd;
	char *line;
	char **split;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open file", FILE_ERR);
	line = get_next_line(fd);
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
		else
			ft_error("Invalid element", INVALID_ELEMENT_ERR);
		ft_free(split);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}