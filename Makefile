SRCS =  mandatory/main.c mandatory/move_player.c mandatory/draw_background.c mandatory/draw_wall.c mandatory/draw_all.c \
		mandatory/valid_key.c mandatory/draw_obstacle.c mandatory/process_map.c mandatory/parse_map.c mandatory/free_static.c \
		mandatory/put_error.c mandatory/check_valid_path.c mandatory/clean_and_exit.c mandatory/ft_free.c \
		mandatory/init_data.c mandatory/draw_img.c mandatory/close_window.c mandatory/read_map.c mandatory/is_valid_elements.c \
		mandatory/put_img_to_buffer.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_BNS =   bonus/main_bonus.c bonus/move_player_bonus.c bonus/draw_background_bonus.c bonus/draw_wall_bonus.c bonus/draw_all_bonus.c \
		bonus/valid_key_bonus.c bonus/draw_obstacle_bonus.c bonus/process_map_bonus.c bonus/parse_map_bonus.c bonus/free_static_bonus.c \
		bonus/put_error_bonus.c bonus/check_valid_path_bonus.c bonus/clean_and_exit_bonus.c bonus/ft_free_bonus.c \
		bonus/init_data_bonus.c bonus/draw_img_bonus.c bonus/close_window_bonus.c bonus/read_map_bonus.c bonus/is_valid_elements_bonus.c \
		bonus/put_img_to_buffer_bonus.c bonus/load_sprites_bonus.c bonus/draw_moves_bonus.c bonus/enemy_bonus.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = libft/libft.a
PRINTF = printf/ftprintf.a
CC = cc #-fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror
# MLX_LIB = -lmlx -lX11 -lXext -lm
MLX_LIB = minilibx/libmlx.a -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRC_BNS:.c=.o)
NAME = so_long
NAME_BNS = so_long_bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@$(MAKE) -C libft

$(PRINTF) :
	@$(MAKE) -C printf

bonus : $(NAME_BNS)

$(NAME_BNS) : $(OBJS_BNS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_BNS)  $(MLX_LIB) $(PRINTF) $(LIBFT) -o $(NAME_BNS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f mandatory/*.o bonus/*.o libft/*.o get_next_line/*.o printf/*.o

fclean: clean
	@rm -f $(NAME) $(NAME_BNS) $(LIBFT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re bonus