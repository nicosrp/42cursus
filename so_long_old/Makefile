NAME := so_long

CC := gcc

CFLAGS := -Wall -Werror -Wextra -lheaders/

SOURCE := [wo die logik drin ist / Quelldateien]
GETNEXTLINE := get_next_line/*c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)


clean:

fclean: clean
	make clean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all
