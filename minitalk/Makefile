# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 16:02:15 by nsherpa           #+#    #+#              #
#    Updated: 2023/08/16 17:16:37 by nsherpa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_FT_PF = ./ft_printf/libftprintf.a
SRCS = server.c client.c
SERVER = server.c
CLIENT = client.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@make -C ./ft_printf
	@$(CC) $(CFLAGS) $(NAME) $(SERVER) $(NAME_FT_PF) -o $(NAME_S)
	@$(CC) $(CFLAGS) $(NAME) $(CLIENT) $(NAME_FT_PF) -o $(NAME_C)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	@make clean -C ./ft_printf
	
fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@make fclean -C ./ft_printf
	
re: fclean all

.PHONY: all clean fclean re