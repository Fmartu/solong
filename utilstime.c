/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:37:45 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/10 17:33:27 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

long long	milliseconds(void)
{
	struct timeval	time;
	long long		microtime;

	gettimeofday(&time, NULL);
	microtime = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (microtime);
}

void	get_ms(t_game *g)
{
	long long	now;

	now = milliseconds();
	if (now > g->ms)
		g->ms = now;
}

void	movecount(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->mcount);
	mlx_string_put(game->mlx.mlx, game->mlx.window,
		128, 128, 0xFF00FF00, moves);
	free(moves);
}
