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
static char	**singlecolumnall(char *file);

char	**finalmap(char *file)
{
	char	**map;
	int		fd;
	int		i;
	int		nlin;

	i = 0;
	map = singlecolumnall(file);
	if (map == NULL)
		return (NULL);
	nlin = nline(file);
	if (nlin == 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	while (i < nlin)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

static int	nline(char *file)
{
	int		fd;
	int		line;
	int		chareader;
	char	n;

	line = 1;
	chareader = 1;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	while (chareader != 0)
	{
		chareader = read(fd, &n, 1);
		if (chareader == 0)
			break ;
		else if (chareader < 0)
			return (0);
		else if (n == '\n')
			line++ ;
	}
	close(fd);
	return (line);
}

static char	**singlecolumnall(char *file)
{
	int		nlines;
	char	**fullmap;

	nlines = nline(file);
	if (nlines == 0)
		return (NULL);
	fullmap = malloc(sizeof(char *) * (nlines + 1));
	if (!fullmap)
		return (NULL);
	return (fullmap);
}
