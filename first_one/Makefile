CC = cc
CFLAGS = -Wall -Wextra -Werror 
CFILES = file1.c file2.c file3.c file4.c file5.c
OBJ = $(CFILES:.c=.o)
NAME = alo.a
Exec = peroro

all : $(NAME)

Exec : $(Exec)

%.o: %.c
	$(CC)  -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(Exec): $(OBJ) $(NAME)
		$(CC) $(OBJ) -L. -lmlx -framework OpenGL -framework AppKit -o $(Exec)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re