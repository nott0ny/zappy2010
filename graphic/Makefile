##
## Makefile for Makefile in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
## 
## Made by adrien veau-greiner
## Login   <veau-g_a@epitech.net>
## 
## Started on  Thu May 13 12:21:33 2010 adrien veau-greiner
## Last update Mon Jun  7 19:06:05 2010 adrien veau-greiner
##

CC	=	gcc

NAME	=	client-fx

SRC	=	main.c \
		get_entry.c \
		aff.c \
		client_handler.c \
		my_select.c \
		error.c \
		check_fd.c \
		connect_server.c \
		start_client.c \
		init_cl.c \
		init_fd.c \
		utils.c \
		check_command.c \
		cmd_init.c \
		cmd_bct.c \
		cmd_sgt.c \
		cmd_msz.c \
		receive_command.c \
		str_to_wordtab.c \
		xfunctions.c \
		disconnect.c

VPATH	=	./sources:./includes

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./includes/

CFLAGS	=	-W -Wall -ansi -pedantic $(INCLUDE)

LDFLAGS	=

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -fr $(OBJ)
	rm -fr *~

re: clean all

fclean:
	rm $(NAME)


