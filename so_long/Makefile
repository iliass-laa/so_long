CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = appear_win.c read_things.c read_2.c\
		 utils.c utils3.c enjoy.c \
		 so_long.c utils2.c utils4.c
OBJ = $(CFILES:.c=.o)
NAME = so_long
BNAME = so_long_bonus
BFILES = appear_win_bonus.c read_2_bonus.c \
		utils_bonus.c utils3_bonus.c utils4_bonus.c \
		enjoy_bonus.c so_long_bonus.c utils2_bonus.c \
		reading_things_bonus.c
BOBJ = $(BFILES:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus : $(BOBJ)
	$(CC) $(BOBJ) -L. -lmlx -framework OpenGL -framework AppKit -o $(BNAME)
clean :
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	rm -rf $(NAME) $(BNAME)

re : fclean all

.PHONY : all clean fclean re