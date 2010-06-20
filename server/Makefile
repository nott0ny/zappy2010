##
## Makefile for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur
##
## Made by amine mouafik
## Login   <mouafi_a@epitech.net>
##
## Started on  Tue May  4 20:55:10 2010 amine mouafik
## Last update Sun Jun 20 16:33:53 2010 amine mouafik
##

CC	=	cc
NAME	=	serveur
SRCS	=	sources/main.c			\
		sources/load_params.c		\
		sources/get_params.c		\
		sources/check_params.c		\
		sources/load_map.c		\
		sources/load_network.c		\
		sources/connect_socket.c	\
		sources/manage_fdts.c		\
		sources/wait_clients.c		\
		sources/new_connection.c	\
		sources/add_player.c		\
		sources/stdread.c		\
		sources/get_player_infos.c	\
		sources/get_graphic_infos.c	\
		sources/get_team_infos.c	\
		sources/check_player_team.c	\
		sources/check_player_cmd.c	\
		sources/check_args.c		\
		sources/get_args.c		\
		sources/check_incantation.c	\
		sources/stdwrite.c		\
		sources/init_ringbuffer.c	\
		sources/manage_ringbuffer.c	\
		sources/add_stack.c		\
		sources/execute_stack.c		\
		sources/moves.c			\
		sources/take.c			\
		sources/drop.c			\
		sources/expulse.c		\
		sources/explore.c		\
		sources/list_inventory.c	\
		sources/incantation.c		\
		sources/broadcast.c		\
		sources/fork.c			\
		sources/connect_nbr.c		\
		sources/healthcare.c		\
		sources/clean_player.c		\
		sources/clean_exit.c		\
		sources/graphic.c		\
		sources/graphic_checks.c	\
		sources/graphic_map.c		\
		sources/graphic_player.c	\
		sources/graphic_params.c	\
		sources/verbose.c		\
		sources/x.c
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-W -Wall -ansi -pedantic -o $@ $(IFLAGS) -g3
IFLAGS	=	-I./includes
LFLAGS	=	-lm
RM	=	rm -rf

$(NAME)	: $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

all	: $(NAME)

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

.PHONY	:
		$(NAME) all clean fclean re tar
