NAME = libftprintf.a

SRCS = ft_printf.c ft_checkpf.c ft_strings.c ft_decint.c ft_utilspf.c ft_atoi.c

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}

RM = rm -f

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} -g  -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
re: fclean all
