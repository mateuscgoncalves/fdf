.PHONY: all clean fclean re
NAME = parsemap.a
SRCS =	../gnl/get_next_line.c \
		../gnl/get_next_line_utils.c \
		ft_count_columns.c \
		ft_create_matrix.c \
		ft_free_matrix.c \
		ft_free_stack.c \
		ft_read_map.c \
		ft_split_ints.c \

OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all