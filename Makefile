SRCS = fractol.c fractol_utils.c colors.c zoom.c features.c parsing.c julia.c mandelbrot.c features_2.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: mlx/libmlx.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mlx/libmlx.a:
	make -C mlx

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean -C mlx

re: fclean all

.PHONY : all clean fclean re