/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:40 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/28 20:08:57 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// HEADERS

# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

// STRUCTS

typedef struct s_stack
{
	int		number;
	int		index; // Do I need it?
	int		push_price;
	bool	cheapest;
	bool	above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*previous;
} t_stack;

// FT PROTOTYPES

void	ft_error(void);
void	init_parse_stack(t_stack **a, char **argv);
int		is_arg_valid(int *arg);

// D LST FTs

void	ft_dlstadd_back(t_stack **lst, t_stack *node);
t_stack	*ft_dlstlast(t_stack *lst);
t_stack	*ft_dlstnew(void *content);
int		ft_dlstsize(t_stack *lst);

// int		check_if_sorted(t_stack *stack_a);
// t_stack	ft_sort(t_stack stack_a);
// int		check_dupes(char **argv);
// int		check_digit(char **argv);
// void	ft_sa(t_stack **stack_a, int print);
// void	ft_sb(t_stack **stack_b, int print);
// void	ft_ss(t_stack **stack_a, t_stack **stack_b, int print);
// void	ft_pb(t_stack **stack_a, t_stack **stack_b, int print);
// void	ft_pa(t_stack **stack_a, t_stack **stack_b, int print);
// void	ft_ra(t_stack **stack_a, int print);
// void	ft_rra(t_stack **stack_a, int print);
// void	ft_rrb(t_stack **stack_b, int print);

#endif
