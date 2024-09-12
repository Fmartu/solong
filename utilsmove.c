/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:37:37 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/10 19:23:43 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move2(t_game *g, int py, int px, int fl);
void	move3(t_game *g, int fl);

void	move(t_game *g, int py, int px)
{
	int	fl;

	fl = 0;
	if (g->map[g->p.y + py][g->p.x + px] == '1')
		return ;
	if (g->map[g->p.y + py][g->p.x + px] == 'C')
		g->ccount--;
	if (g->map[g->p.y + py][g->p.x + px] == 'N')
	{
		ft_printf(BADEND);
		closegame(g);
	}
	if (g->map[g->p.y + py][g->p.x + px] == 'E')
	{
		if (g->ccount == 0)
		{
			ft_printf(GODEND);
			closegame(g);
			// exit(1);
		}
		else
			return ;
	}
	move2(g, py, px, fl);
}

void	move2(t_game *g, int py, int px, int fl)
{
	g->map[g->p.y][g->p.x] = '0';
	g->map[g->p.y + py][g->p.x + px] = 'P';
	g->mcount++;
	g->p.x += px;
	g->p.y += py;
	if (g->n.x < g->l && g->n.y < g->h)
	{
		blinkenemy(g);
		movenemy(g);
	}
	mlx_destroy_image(g->mlx.mlx, g->img.wall[0]);
	g->img.wall[0] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/wall1.xpm", &fl, &fl);
	mlx_destroy_image(g->mlx.mlx, g->img.wall[1]);
	g->img.wall[1] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/wall2.xpm", &fl, &fl);
	move3(g, fl);
}

void	move3(t_game *g, int fl)
{
	if (g->ccount == 0)
	{
		mlx_destroy_image(g->mlx.mlx, g->img.wall[0]);
		g->img.wall[0] = mlx_xpm_file_to_image(g->mlx.mlx,
				"xpm/rose.xpm", &fl, &fl);
		mlx_destroy_image(g->mlx.mlx, g->img.wall[1]);
		g->img.wall[1] = mlx_xpm_file_to_image(g->mlx.mlx,
				"xpm/rose2.xpm", &fl, &fl);
	}
	if (g->p.x == g-> n.x && g->p.y == g->n.y)
	{
		mlx_destroy_image(g->mlx.mlx, g->img.wall[0]);
		g->img.wall[0] = mlx_xpm_file_to_image(g->mlx.mlx,
				"xpm/blud.xpm", &fl, &fl);
		mlx_destroy_image(g->mlx.mlx, g->img.wall[1]);
		g->img.wall[1] = mlx_xpm_file_to_image(g->mlx.mlx,
				"xpm/flo.xpm", &fl, &fl);
		g->n.y = 0;
		g->n.x = 0;
	}
}
