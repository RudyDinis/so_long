NAME = so_long
LIBFT = src/utils/libft
SRC = src/utils/gnl/get_next_line_utils.c src/utils/gnl/get_next_line.c \
		src/main.c src/map/map_checker.c src/map/map.c src/utils/pile/push.c src/utils/pile/view.c \
		src/sprite/sprite.c src/map/draw_map.c src/map/check_condition.c src/map/wall/angle.c \
		src/map/wall/line.c src/map/wall/check_angle.c

OBJ := $(SRC:%.c=%.o)

CC = cc -std=c11
CFLAGS = -I . -Imlx_linux

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