##
## Makefile for Makefile in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
## 
## Made by adrien veau-greiner
## Login   <veau-g_a@epitech.net>
## 
## Started on  Thu May 13 12:21:33 2010 adrien veau-greiner
## Last update Fri May 14 19:34:00 2010 adrien veau-greiner
##

CC	=	gcc

NAME	=	client-fx

SRC	=	main.c \
		get_entry.c \
		aff.c \
		error.c \
		connect_server.c \
		check_command.c \
		start_client.c \
		receive_command.c \
		client_handler.c \
		receive_start_conf.c \
		receive_map.c \
		receive_size.c \
		receive_time_unity.c \
		init_world.c \
		init_graph.c \
		utils.c \
		cmd_msz.c \
		cmd_sgt.c \
		cmd_bct.c \
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


