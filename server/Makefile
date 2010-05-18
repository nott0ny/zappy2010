##
## Makefile for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur
## 
## Made by amine mouafik
## Login   <mouafi_a@epitech.net>
## 
## Started on  Tue May  4 20:55:10 2010 amine mouafik
## Last update Thu May 13 17:11:29 2010 amine mouafik
##

CC	=	cc
NAME	=	server
SRCS	=	sources/main.c			\
		sources/init.c			\
		sources/load_params.c		\
		sources/get_params.c		\
		sources/check_params.c		\
		sources/load_map.c		\
		sources/load_network.c		\
		sources/wait_clients.c		\
		sources/tools/print_err.c	\
		sources/tools/xmalloc.c
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
