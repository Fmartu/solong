NAME = libftprintf.a

SRCS = ft_printf.c  ft_putaddrss.c ft_putchar.c ft_putexa.c ft_putnbr.c ft_putstr.c ft_putunsigned.c ft_strchr.c ft_strlen.c ft_putchar_fd.c\

OUT = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra
 
.c.o:
	${CC} ${CFLAGS} -g -c  $< -o ${<:.c=.o}

$(NAME): $(OUT)
		ar rcs $(NAME) $(OUT)

all:	$(NAME)

clean:
		rm -f $(OUT)

fclean: clean
		rm -f $(NAME)

re: 	fclean all
