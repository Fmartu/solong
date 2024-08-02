/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfiletoarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:52:44 by fmartusc          #+#    #+#             */
/*   Updated: 2024/08/01 16:52:44 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	nline(char *file);
static int singlecolumnall(char *file);

char **finalmap(char *file)
{
	int **map;
	int fd;
	int i;

	i = 0;
	map = singlecolumnall(file);
	if(!map)
		return(0);
	fd = open(file, O_RDONLY);
	while (1)
		get_next_line(fd, &map[i++]);
	map[i] = NULL;
	close(fd);
	return(map);
}


static int	nline(char *file)
{
	int fd;
	int line;
	int chareader;
	char n;

	line = 1
	chareader = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return(0)
	while (chareader != 0)
	{
		chareader = read(fd, &n, 1);
		if (chareader == 0)
			break;
		else if (chareader < 0)
			return(0);
		else (n == '\n')
			line++;
	}
	close(fd);
	return(line);
}

static int singlecolumnall(char *file)
{
	int nlines;
	char **fullmap;

	nlines = nline(file);
	if (nline == 0)
	{
		ft_printf("Error: fd error");
		return(0);
	}
	fullmap = malloc(sizeof(char *) * nline + 1);
	if (!fullmap)
	{
		ft_printf("Error: malloc error");
		return (0);
	}
	return(fullmap);
}