NAME = so_long
LIBFT = src/utils/libft
SRC = src/utils/gnl/get_next_line_utils.c src/utils/gnl/get_next_line.c \
		src/main.c src/map/map_checker.c src/map/map.c src/utils/free/free.c \
		src/sprite/sprite.c src/map/draw_map.c src/map/check_condition.c src/map/wall/angle.c \
		src/map/wall/line.c src/map/wall/end.c src/map/wall/check_angle.c src/map/wall/check_end.c \
		src/visual_info/draw_write.c src/utils/close.c src/ghost/ghost.c src/sprite/sprite_check.c \
		src/map/wall/check_t.c src/map/wall/t.c src/map/wall/check_square.c  \
		src/map/wall/square.c src/map/draw_exit.c src/map/check_size.c src/map/wall/load.c

OBJ := $(SRC:%.c=%.o)

CC = cc -std=c11
CFLAGS = -Wall -Wextra -Werror -I . -Imlx_linux

all: $(NAME)

$(NAME): $(OBJ)
	make -C ${LIBFT}
	$(CC) $(CFLAGS) $(OBJ) ${LIBFT}/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ${LIBFT}
	rm -f $(OBJ)

fclean: clean
	make fclean -C ${LIBFT}
	rm -f $(NAME)

re : fclean all
