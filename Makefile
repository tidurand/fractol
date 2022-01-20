SRCS = fractol.c fractol_utils.c fractales.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

%.o: %.c
	$(CC) -Wall -Wextra -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all