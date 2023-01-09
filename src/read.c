/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:27:09 by mcakay            #+#    #+#             */
/*   Updated: 2023/01/09 06:34:30 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void	init_read(t_read *read, char *file)
{
	read->amb_l_amount = 0;
	read->lg_amount = 0;
	read->cam_amount = 0;
	read->sph_head = NULL;
	read->pl_head = NULL;
	read->cyl_head = NULL;
	read->file = file;
	read->fd = open(file, O_RDONLY);
	if (read->fd == -1)
		ft_error("Failed to open file", FILE_ERR, -1);
}

void	identify(char **split, t_read *read, int l)
{
	if (ft_strncmp(split[0], "A", 2) == 0)
		ambient_lightning_read(read, split, l);
	else if (ft_strncmp(split[0], "C", 2) == 0)
		camera_read(read, split, l);
	else if (ft_strncmp(split[0], "L", 2) == 0)
		light_read(read, split, l);
	else if (ft_strncmp(split[0], "sp", 3) == 0)
		sphere_read(read, split, l);
	else if (ft_strncmp(split[0], "pl", 3) == 0)
		plane_read(read, split, l);
	else if (ft_strncmp(split[0], "cy", 3) == 0)
		cylinder_read(read, split, l);
	else
		ft_error("Invalid identifier", INVALID_IDENTIFIER_ERR, l);
}

void	read_file(t_read *read)
{
	char	*line;
	int		l;
	char	**split;

	l = 0;
	is_rt(read->file);
	line = get_next_line(read->fd);
	while (line)
	{
		l++;
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(read->fd);
			continue ;
		}
		split = ft_split(line, ' ');
		identify(split, read, l);
		ft_free(split);
		free(line);
		check_argument_amount(read, l);
		line = get_next_line(read->fd);
	}
	close(read->fd);
}
