/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:35:55 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/02 20:38:57 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "mapstuff/map.h"

void	putimage(char toprint, t_game *g, int x, int y)
{
	if (toprint == '1')
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.window,
			g->img.wall[g->frame % 2], x * TILE_RES, y * TILE_RES);
	else if (toprint == 'C')
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.window,
			g->img.water[g->frame % 5],
			(x * TILE_RES) + (TILE_RES / 4), y * TILE_RES + (TILE_RES / 4));
	else if (toprint == 'N')
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.window,
			g->img.enemy[g->frame % 2], x * TILE_RES, y * TILE_RES);
	else if (toprint == 'E')
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.window,
			g->img.bed[g->ccount == 0], x * TILE_RES, y * TILE_RES);
	else if (toprint == 'P')
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.window,
			g->img.me[g->frame % 4], x * TILE_RES, y * TILE_RES);
	else if (toprint == 'T')
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.window,
			g->img.trans[g->frame % 2], x * TILE_RES, y * TILE_RES);
	else
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.window,
			g->img.floor, x * TILE_RES, y * TILE_RES);
}

void	print_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < g->h)
	{
		i = 0;
		while (i < g->l)
		{
			putimage(g->map[j][i], g, i, j);
			i++;
		}
		j++;
	}
	movecount(g);
}
