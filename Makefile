# Compiler flags
CFLAGS = -Wall -Wextra -Werror
MFLAGS	= -lXext -lX11 -lm -lbsd

# Directories
SRCDIR = srcs
OBJDIR = objs
FT_PRINTFDIR = all_libs/ft_printf
LIBFTDIR = all_libs/ft_printf/libft
MLXDIR = libs/mlx

# Libraries
LIBSFLAG = -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf -L$(MLXDIR) -lmlx_Linux

# Source files
SRCS = so_long.c \
	   srcs/fd_to_string.c 
OBJS = so_long.o \
	   objs/fd_to_string.o 

# Executable name
NAME = so_long

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -Wall -Wextra -Werror  $(LIBSFLAG) -I/usr/include -I$(MLXDIR) -O3 -c $< -o $@


$(NAME): $(OBJS)
	@ make -C $(FT_PRINTFDIR)
	@ make -C $(MLXDIR)
	@ make -C $(LIBFTDIR)
	$(CC) $(OBJS) -L$(MLXDIR) -lmlx_Linux -L/usr/lib -I$(MLXDIR) -lXext -lX11 -lm -lz $(LIBSFLAG) -o $(NAME)

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re