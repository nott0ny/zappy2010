##
## Makefile for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur
## 
## Made by amine mouafik
## Login   <mouafi_a@epitech.net>
## 
## Started on  Tue May  4 20:55:10 2010 amine mouafik
## Last update Mon Jun  7 15:32:03 2010 amine mouafik
##

CC	=	cc
NAME	=	server
SRCS	=	sources/main.c			\
		sources/load_params.c		\
		sources/get_params.c		\
		sources/check_params.c		\
		sources/load_map.c		\
		sources/load_network.c		\
		sources/connect_socket.c	\
		sources/manage_fdts.c		\
		sources/wait_clients.c		\
		sources/watch_fds.c		\
		sources/new_connection.c	\
		sources/add_player.c		\
		sources/stdread.c		\
		sources/stdread_player.c	\
		sources/stdwrite.c		\
		sources/init_ringbuffer.c	\
		sources/manage_ringbuffer.c	\
		sources/execution_stack.c	\
		sources/tmp_actions.c		\
		sources/x.c
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-W -Wall -ansi -pedantic -o $@ $(IFLAGS)
IFLAGS	=	-I./includes
RM	=	rm -rf

$(NAME)	: 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

all	: 	$(NAME)

clean	:
		$(RM) $(OBJS)
		$(RM) *~
		$(RM) \#*\#
		$(RM) sources/*~
		$(RM) sources/\#*\#
		$(RM) includes/*~
		$(RM) includes/\#*\#

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

tar	:
		tar -cf ./misc/$(NAME).tar --exclude $(NAME).tar *

.PHONY	:	$(NAME) all clean fclean re tar
