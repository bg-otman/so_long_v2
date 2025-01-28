SRCS =  src/main.c src/move_player.c src/draw_background.c src/draw_wall.c src/draw_all.c \
		src/valid_key.c src/draw_obstacle.c src/process_map.c src/parse_map.c src/free_static.c \
		src/put_error.c src/check_valid_path.c src/clean_and_exit.c src/ft_free.c \
		src/init_texture.c src/draw_collectable.c src/draw_door.c src/draw_img.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
# MLX_LIB = -lmlx -lX11 -lXext -lm
MLX_LIB = minilibx/libmlx.a -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) libft/$(LIBFT) -o $(NAME)

$(LIBFT) :
	@$(MAKE) -C libft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f src/*.o libft/*.o get_next_line/*.o

fclean: clean
	@rm -f $(NAME) libft/$(LIBFT)

re: fclean all
