SRCS =  src/main.c src/move_player.c src/draw_background.c src/draw_wall.c src/draw_all.c \
		src/valid_key.c src/draw_obstacle.c src/process_map.c src/parse_map.c src/free_static.c \
		src/put_error.c src/check_valid_path.c src/clean_and_exit.c src/ft_free.c \
		src/init_data.c src/draw_img.c src/close_window.c src/read_map.c src/is_valid_elements.c \
		src/put_img_to_buffer.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = libft/libft.a
PRINTF = printf/ftprintf.a
CC = cc #-fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror
# MLX_LIB = -lmlx -lX11 -lXext -lm
MLX_LIB = minilibx/libmlx.a -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@$(MAKE) -C libft

$(PRINTF) :
	@$(MAKE) -C printf

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f src/*.o libft/*.o get_next_line/*.o printf/*.o

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(PRINTF)

re: fclean all