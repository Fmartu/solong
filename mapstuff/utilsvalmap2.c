/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsvalmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:30:09 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/10 19:07:45 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

void	ffill(char **map, int y, int x);
int		ffillfinal2(char **copy, int i);

int	fexit(char **tmpmap)
{
	int	i;

	i = 0;
	if (!tmpmap)
		return (0);
	if (*tmpmap != NULL)
	{
		while (tmpmap[i])
		{
			free(tmpmap[i]);
			i++;
		}
		free(tmpmap);
	}
	return (0);
}

int	ffillfinal(t_game *game)
{
	char	**copy;
	int		x;
	int		y;
	int		i;

	i = -1;
	copy = malloc(sizeof(char *) * (game->h + 1));
	if (!copy)
		return (0);
	copy[game->h] = 0;
	while (++i < game->h)
	{
		copy[i] = ft_strdup1(game->map[i]);
		if (ft_strchr(copy[i], 'P'))
		{
			x = ft_strchr(copy[i], 'P') - copy[i];
			y = i;
		}
	}
	game->p.x = x;
	game->p.y = y;
	ffill(copy, y, x);
	return (ffillfinal2(copy, i));
}

int	ffillfinal2(char **copy, int i)
{
	while (--i >= 0)
	{
		if (ft_strchr(copy[i], 'C') || ft_strchr(copy[i], 'E'))
		{
			fexit(copy);
			return (err(8));
		}
	}
	fexit(copy);
	return (1);
}

void	ffill(char **map, int y, int x)
{
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = '1';
	if (map[y + 1][x] != '1')
		ffill(map, y + 1, x);
	if (map[y - 1][x] != '1')
		ffill(map, y - 1, x);
	if (map[y][x + 1] != '1')
		ffill(map, y, x + 1);
	if (map[y][x - 1] != '1')
		ffill(map, y, x - 1);
}
