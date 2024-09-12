/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:19:01 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/10 19:20:21 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_variables(t_game *g)
{
	g->mcount = 0;
	g->frame = 0;
	g->ms = 0;
	g->x = 0;
	g->y = 0;
	g->pl = 0;
	g->e = 0;
	g->dir = 0;
}

void	init(t_game *g)
{
	g->mlx.mlx = mlx_init();
	g->mlx.window = mlx_new_window(g->mlx.mlx,
			g->l * TILE_RES, g->h * TILE_RES, "Get2Bed");
	init_images(g);
	g->mcount = 0;
	g->frame = 0;
	g->ms = 0;
	get_ms(g);
	spawnenemy(g);
}

int	keysmash(int keycode, t_game *game)
{
	if (keycode == W)
		move(game, -1, 0);
	if (keycode == S)
		move(game, +1, 0);
	if (keycode == A)
		move(game, 0, -1);
	if (keycode == D)
		move(game, 0, +1);
	if (keycode == ESC)
		closegame(game);
	print_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (finalcheck(&game, argc, argv) == 0)
		return (fexit(game.map));
	init(&game);
	init_variables(&game);
	mlx_loop_hook(game.mlx.mlx, refreshscreen, &game);
	mlx_key_hook(game.mlx.window, keysmash, &game);
	mlx_hook(game.mlx.window, 17, 1L << 0, closegame, &game);
	mlx_loop(game.mlx.mlx);
}
