# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 15:34:26 by tbruha            #+#    #+#              #
#    Updated: 2024/11/15 13:34:56 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
CC		= cc
INCLUDE	= -L ./libft -lft

SRC		= 	push_swap.c lst_utils1.c lst_utils2.c operations_swap_and_push.c \
			operations_rotations.c operations_reverse_rotations.c sorting1.c \
			sorting2.c errors_free_and_other.c nodes_info1.c nodes_info2.c \
						
OBJ		:=	$(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME)
	
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
