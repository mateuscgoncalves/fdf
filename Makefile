.PHONY: all clean fclean re
NAME = fdf
SRCS =	main.c \
		bres_alg.c \
		map.c \
		exit.c
		
LIBFT = ./libft/libft.a
PARSEMAP = ./parsemap/parsemap.a
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		make bonus -C ./libft
		make -C ./parsemap
		$(CC) $(OBJS) $(LIBFT) $(PARSEMAP) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
	
re: fclean all
