##
## Makefile for Makefile in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
## 
## Made by adrien veau-greiner
## Login   <veau-g_a@epitech.net>
## 
## Started on  Thu May 13 12:21:33 2010 adrien veau-greiner
## Last update Wed Jun  9 12:41:53 2010 adrien veau-greiner
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
		manage_ringbuffer.c \
		start_client.c \
		init_ringbuffer.c \
		init_cl.c \
		init_fd.c \
		utils.c \
		check_command.c \
		cmd_init.c \
		cmd_bct.c \
		cmd_sgt.c \
		cmd_msz.c \
		cmd_tna.c \
		receive_command.c \
		str_to_wordtab.c \
		xfunctions.c \
		disconnect.c

VPATH	=	./sources:./includes

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./includes/

CFLAGS	=	-W -Wall -ansi -pedantic -g3 $(INCLUDE)

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


