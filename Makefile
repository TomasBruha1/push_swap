# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 15:34:26 by tbruha            #+#    #+#              #
#    Updated: 2024/09/23 15:34:28 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
CC		= cc
INCLUDE	= -L ./libft -lft

SRC		= 	push_swap.c

OBJ		:=	$(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@make -C libft/
#	@cp libft/libft.a ./
	@$(CC) $(CFLAGS) $(SRC) $(INCLUDE) libft.a -o $(NAME)
	
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<	

clean:
	@$(RM) $(OBJ)
	@make clean -C libft/

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft/

re:	fclean all

.PHONY:	all clean fclean re
