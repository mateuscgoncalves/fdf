.PHONY: all clean fclean re
NAME = fdf
SRCS =	main.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c
LIBFT = ./libft/libft.a
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		$(CC) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
	
re: fclean all
