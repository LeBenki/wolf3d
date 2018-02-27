##
## Makefile for Pushswap in /home/lucas99.06/Epitech/Semester1/Prog_Elem/CPE_2016_Pushswap
##
## Made by Lucas Benkemoun
## Login   <benke_l@epitech.net>
##
## Started on  Thu Nov 24 22:54:13 2016 Lucas Benkemoun
## Last update Sun Jan 15 00:31:31 2017 Lucas Benkemoun
##

CC	=	gcc

RM	=	rm -f

#CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-I. -lm -Ofast
CFLAGS	+=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME	=	wolf3d

SRCS	=	main.c \
		calcul_wall.c \
		keyboard.c \
		my_strncpy.c \
		my_str_to_wordtab.c \
		parsing.c \
		util_graph.c \
		src/my_put_pixel.c \
		src/raycast.c \
		src/window.c \
		src/my_draw_line.c \
		src/move_forward.c \
		crosshair.c \
		radar.c \
		file.c \
		draw_wall.c \
		action.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
