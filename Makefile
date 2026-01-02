NAME = fractol

SRC = src/main.c src/init.c src/render.c src/events.c src/utils.c src/utils2.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux


MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
