PROG    = so_long

SRCS    =	main.c errors.c utilsmove.c utilsimage.c mapstuff/mapfiletoarray.c mapstuff/utilsvalmap.c mapstuff/utilsvalmap2.c \
		 all_libs/gnl/get_next_line.c  all_libs/gnl/get_next_line_utils.c utilstime.c graphic.c itoa.c \
		 enemy.c mapstuff/utilsvalmap3.c

OBJS     = ${SRCS:.c=.o}
MAIN    = main.c


CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g

%.o : %.c
	@gcc ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

all:         ${PROG}

${PROG}:    ${OBJS}
						@make -C mlx
						@make -C all_libs/ft_printf
						@$(CC) ${OBJS} -lmlx -lXext -lX11 -L mlx -o${PROG} all_libs/ft_printf/libftprintf.a

clean:
						@rm -f ${OBJS}


fclean:     clean
						@rm -f $(NAME)
						@rm -f ${PROG}

re:            fclean all

.PHONY: all clean fclean re