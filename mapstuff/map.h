/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:31:56 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/02 16:31:56 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <unistd.h>
# include "../all_libs/gnl/get_next_line.h"
# include "../all_libs/ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include "../solong.h"
# include "../mlx/mlx.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_tile
{
	void	*img;
	t_coord	pos;
	char	item;
}	t_tile;

typedef struct s_imgtile
{
	void	*me[4];
	void	*water[5];
	void	*wall[2];
	void	*floor;
	void	*enemy[2];
	void	*bed[2];
	void	*trans[2];
	void	*blood;
}	t_imgtile;

typedef struct s_mlxwindow
{
	void	*window;
	void	*mlx;
}	t_mlxwindow;

typedef struct s_game
{
	char		**map;
	t_mlxwindow	mlx;
	t_imgtile	img;
	int			ccount;
	int			mcount;
	t_coord		p;
	t_coord		n;
	int			frame;
	int			l;
	int			h;
	long long	ms;
	int			x;
	int			y;
	int			pl;
	int			e;
	int			dir;
}	t_game;

char		*ft_strdup1(const char *s1);
char		**finalmap(char	*file);
int			itemscheck(t_game *tmpmap);
int			ffillfinal(t_game *game);
int			finalcheck(t_game *tmpmap, int argc, char	**argv);
void		get_ms(t_game *g);
void		print_map(t_game *g);
void		movecount(t_game *game);
void		movenemy(t_game *game);
void		blinkenemy(t_game *game);
int			spawnenemy(t_game *g);
void		free_g_img(t_game *g);
void		init_images(t_game *g);
long long	milliseconds(void);
int			closegame(t_game *game);
int			refreshscreen(t_game *g);
int			closegame(t_game *game);
void		move(t_game *g, int py, int px);

#endif