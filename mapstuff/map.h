#ifndef MAP_H
# define MAP_H

#include <fcntl.h>
#include <unistd.h>
#include "../gnl/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

char **finalmap(char *file);

typedef struct s_game
{
	char **map;

}

#endif