/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsimage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:37:56 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/10 18:06:01 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_images2(t_game *g);

void	free_g_img(t_game *g)
{
	mlx_destroy_image(g->mlx.mlx, g->img.floor);
	mlx_destroy_image(g->mlx.mlx, g->img.wall[0]);
	mlx_destroy_image(g->mlx.mlx, g->img.wall[1]);
	mlx_destroy_image(g->mlx.mlx, g->img.me[0]);
	mlx_destroy_image(g->mlx.mlx, g->img.me[1]);
	mlx_destroy_image(g->mlx.mlx, g->img.me[2]);
	mlx_destroy_image(g->mlx.mlx, g->img.me[3]);
	mlx_destroy_image(g->mlx.mlx, g->img.bed[0]);
	mlx_destroy_image(g->mlx.mlx, g->img.bed[1]);
	mlx_destroy_image(g->mlx.mlx, g->img.water[0]);
	mlx_destroy_image(g->mlx.mlx, g->img.water[1]);
	mlx_destroy_image(g->mlx.mlx, g->img.water[2]);
	mlx_destroy_image(g->mlx.mlx, g->img.water[3]);
	mlx_destroy_image(g->mlx.mlx, g->img.water[4]);
	mlx_destroy_image(g->mlx.mlx, g->img.enemy[0]);
	mlx_destroy_image(g->mlx.mlx, g->img.enemy[1]);
	mlx_destroy_image(g->mlx.mlx, g->img.trans[0]);
	mlx_destroy_image(g->mlx.mlx, g->img.trans[1]);
	mlx_destroy_window(g->mlx.mlx, g->mlx.window);
	mlx_destroy_display(g->mlx.mlx);
	free(g->mlx.mlx);
}

void	init_images(t_game *g)
{
	int	fl;

	fl = 0;
	g->img.floor = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/flo.xpm", &fl, &fl);
	g->img.wall[0] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/wall1.xpm", &fl, &fl);
	g->img.wall[1] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/wall2.xpm", &fl, &fl);
	g->img.me[0] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/me1.xpm", &fl, &fl);
	g->img.me[1] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/me2.xpm", &fl, &fl);
	g->img.me[2] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/me3.xpm", &fl, &fl);
	g->img.me[3] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/me4.xpm", &fl, &fl);
	g->img.bed[0] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/exitclose.xpm", &fl, &fl);
	g->img.bed[1] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/exitopen.xpm", &fl, &fl);
	init_images2(g);
}

void	init_images2(t_game *g)
{
	int	fl;

	fl = 0;
	g->img.water[0] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/col1.xpm", &fl, &fl);
	g->img.water[1] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/col2.xpm", &fl, &fl);
	g->img.water[2] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/col3.xpm", &fl, &fl);
	g->img.water[3] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/col4.xpm", &fl, &fl);
	g->img.water[4] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/col5.xpm", &fl, &fl);
	g->img.enemy[0] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/enem1.xpm", &fl, &fl);
	g->img.enemy[1] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/enem2.xpm", &fl, &fl);
	g->img.trans[0] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/trans.xpm", &fl, &fl);
	g->img.trans[1] = mlx_xpm_file_to_image(g->mlx.mlx,
			"xpm/trans2.xpm", &fl, &fl);
}

int	refreshscreen(t_game *g)
{
	long long	millitime;
	long long	difference;

	millitime = milliseconds();
	difference = millitime - g->ms;
	if (difference >= 130)
	{
		get_ms(g);
		g->frame++;
		print_map(g);
	}
	return (0);
}

int	closegame(t_game *game)
{
	free_g_img(game);
	fexit(game->map);
	exit(0);
}
