##
## Makefile for  in /home/miele_t/
## 
## Made by thomas miele
## Login   <miele_t@epitech.net>
## 
## Started on  Thu Mar 15 08:59:42 2012 thomas miele
## Last update Sat Jun  2 16:21:34 2012 thomas miele
##

NAME=	rt

SRC=	Src/main.c		\
	Src/calc_mesh.c		\
	Src/color.c		\
	Src/get_mesh.c		\
	Src/inter_mesh.c	\
	Src/light.c		\
	Src/llist.c		\
	Src/luminosite.c	\
	Src/mesh.c		\
	Src/mlx.c		\
	Src/raytracer.c		\
	Src/rotate.c		\
	Src/shadow.c		\

OBJ=	$(SRC:.c=.o)

CC=	gcc

CFLAGS=	-Wall  -D_REENTRANT #-I/usr/include/SDL2

LDFLAGS= -L/usr/lib/x86_64-linux-gnu -lSDL2

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
#	@clean
	@rm -f Src/*.c~
	@rm -f Src/*\#*#
	@rm -f Src/Include/*.c~
	@rm -f Src/Include/*\#*#
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
