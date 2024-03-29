CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = so_long.c reading.c appear_win.c enjoy.c utils.c utils2.c
OBJ = $(CFILES:.c=.o)
NAME = exec

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re