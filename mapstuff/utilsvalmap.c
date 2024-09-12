/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsvalmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:30:57 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/10 19:27:59 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	mapformat(char **argv);
int			squarecheck(t_game *tmpmap);
static int	borderscheck(t_game *tmpmap);

int	finalcheck(t_game *tmpmap, int argc, char **argv)
{
	tmpmap->map = NULL;
	if (argc != 2 || !argv[1][0])
		return (err(1));
	tmpmap->map = finalmap(argv[1]);
	if (!tmpmap->map)
		return (err(1));
	if (mapformat(argv) && squarecheck(tmpmap)
		&& borderscheck(tmpmap) && itemscheck(tmpmap) && ffillfinal(tmpmap))
		return (1);
	else
		return (0);
}

static int	mapformat(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (i < 4)
		return (err(1));
	if ((argv[1][i - 4] == '.') && (argv[1][i -3] == 'b')
		&& (argv[1][i - 2] == 'e') && (argv[1][i -1] == 'r'))
		return (1);
	else
		return (err(1));
}

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (1);
	return (0);
}

int	squarecheck(t_game *tmpmap)
{
	int	y;

	y = 0;
	tmpmap->l = (int) strlenline(tmpmap->map[0]);
	while (tmpmap->map[y])
	{
		if (tmpmap->l == (int) strlenline(tmpmap->map[y]))
			y++;
		else
			return (err(7));
	}
	if (y < 3)
		return (err(7));
	tmpmap->h = y;
	return (1);
}

static int	borderscheck(t_game *tmpmap)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tmpmap->map[y])
	{
		if ((tmpmap->map[y][0] != '1')
			|| (tmpmap->map[y][tmpmap->l - 1] != '1'))
			return (err(5));
		y++;
	}
	tmpmap->h = y;
	while (tmpmap->map[0][x + 1])
	{
		if ((tmpmap->map[0][x] != '1')
			|| (tmpmap->map[tmpmap->h - 1][x] != '1'))
			return (err(5));
		x++;
	}
	return (1);
}
