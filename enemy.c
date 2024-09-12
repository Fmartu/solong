/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:29:57 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/02 20:43:11 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapstuff/map.h"
#include "solong.h"

int	movedir(t_game *game, int x, int y);

int	spawnenemy(t_game *game)
{
	game->n.x = 1;
	game->n.y = 1;
	while (game->n.y < game->h)
	{
		if (game->map[game->n.y][game->n.x] == '0')
		{
			game->map[game->n.y][game->n.x] = 'N';
			return (1);
		}
		game->n.x++;
		game->n.y++;
	}
	return (0);
}

void	blinkenemy(t_game *game)
{
	if (game->map[game->n.y][game->n.x] == 'C')
		return ;
	else if (game->map[game->n.y][game->n.x] == 'P')
		return ;
	else if (game->map[game->n.y][game->n.x] == 'E')
		return ;
	else if (game->map[game->n.y][game->n.x] == '1')
		return ;
	else if (game->map[game->n.y][game->n.x] == 'T')
		game->map[game->n.y][game->n.x] = 'N';
	else if (game->map[game->n.y][game->n.x] == 'N')
		game->map[game->n.y][game->n.x] = 'T';
}

void	movenemy(t_game *game)
{
	int	x;
	int	y;

	x = game->n.x;
	y = game->n.y;
	if (game->map[game->n.y][game->n.x] == 'N')
	{
		movedir(game, x, y);
	}
}

int	movedir(t_game *game, int x, int y)
{
	if (game->map[game->n.y + 1][game->n.x] == '0' && game->dir != 3)
	{
		game->map[++game->n.y][game->n.x] = 'N';
		game->dir = 1;
	}
	else if (game->map[game->n.y][game->n.x - 1] == '0' && game->dir != 4)
	{
		game->map[game->n.y][--game->n.x] = 'N';
		game->dir = 2;
	}
	else if (game->map[game->n.y - 1][game->n.x] == '0' && game->dir != 1)
	{
		game->map[--game->n.y][game->n.x] = 'N';
		game->dir = 3;
	}
	else if (game->map[game->n.y][game->n.x + 1] == '0' && game->dir != 2)
	{
		game->map[game->n.y][++game->n.x] = 'N';
		game->dir = 4;
	}
	else
		return (game->dir = 0);
	game->map[y][x] = '0';
	return (1);
}
