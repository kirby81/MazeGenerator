RM			=	rm -rfv
CC			=	gcc
GC			=	gcc -g

EXEC		=	MazeGenerator

SRC			=	source/main.c \
				source/maze.c \
				source/stdtool.c \
				source/tree.c

OBJS		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-std=c99

LFLAGS  +=	`sdl-config --cflags --libs`

$(EXEC):		$(OBJS)
				$(CC) -o $@ $^ $(LFLAGS)

all:			$(EXEC)

clean:
				$(RM) source/*.o

fclean:			clean
				$(RM) $(EXEC)

re:				fclean all

%.o: %.c
				$(CC) -o $@ -c $< $(CFLAGS)
