NAME = push_swap
LIBFT = libft/libft.a
GETNEXTLINE = getnextline/get_next_line.a
SRCS = ${wildcard *.c}
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	@make clean -C get_next_line
	@make clean -C libft
	
fclean: clean
	@rm -f $(NAME) $(LIBFT) $(NAME)
	@make fclean -C GETNEXTLINE

re: fclean all

.PHONY: all clean fclean re