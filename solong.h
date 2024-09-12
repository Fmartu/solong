/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:53 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/10 18:31:54 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define TILE_RES 128
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

# define ERROR1 "Error\nFormat error : You need a valid .be(e)r \
... or better, some water\n"
# define ERROR2 "Error\nChar error: I know you know the full alphabet, \
but please, use just PECN01 in your map\n"
# define ERROR3 "Error\nMalloc error: too drunk to explain why\n"
# define ERROR4 "Error\nFD error: it seems to be empty or missing... \
as your wallet\n"
# define ERROR5 "Error\nMap error: the breeze coming from the holes in \
the wall is not good. Try to sorround the square map with walls\n"
# define ERROR6 "Error\nChar error: too much alhool can make you see double, \
but there should be just one of you (P) and you should drink at least a cup \
of water (C) before going to sleep in the only bed you have (E)\n"
# define ERROR7 "Error\nMap error: plz, too tired to argue, \
make the room a square\n"
# define ERROR8 "Error\nReaching error: before going out make \
sure you can get to your water and bed\n"
# define BADEND "Bad ending: you trow up\n"
# define GODEND "Good ending: you menage to get to the bed \
well hydrated\n"

# include "./mapstuff/map.h"
# include "mapstuff/map.h"
# include "./all_libs/ft_printf/ft_printf.h"
# include <stdio.h>
# include <sys/time.h>

int			err(int ret);
int			valid_char(char c);
int			strlenline(char *str);
long long	milliseconds(void);
int			fexit(char **tmpmap);
char		*ft_itoa(int n);

#endif
