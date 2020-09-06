# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/29 11:02:17 by gvan-roo          #+#    #+#              #
#    Updated: 2017/07/03 09:38:14 by gvan-roo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

PATH_HEAD	=	./headers
PATH_LIB	=	./libft

SRSC		=	./srsc/get_lst.c	\
				./srsc/print_lst.c	\
				./srsc/main.c

OSRC		=	get_lst.o	\
				print_lst.o	\
				main.o		\

FLAGS		=	-Wall -Werror -Wextra

all	:	$(NAME)

$(NAME)	:	$(OSRC)
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -I $(PATH_HEAD) -c $(SRSC)
	gcc -o $(NAME) $(OSRC) -L$(PATH_LIB) -lft -lmlx -framework OpenGL -framework AppKit

$(OSRC) :
	
clean	:
	rm -f $(OSRC)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean
	make
