/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:40 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/02 12:04:00 by tbruha           ###   ########.fr       */
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
	struct s_stack	*prev;
} t_stack;

// FT PROTOTYPES for push_swap

void	ft_error(void);
void	init_parse_stack(t_stack **a, char **argv);
void	init_stack(t_stack **a, char **argv);
int		is_arg_valid(char *arg);
long	ft_atol(const char *nptr);
void	check_duplicates(t_stack *lst);
int		check_if_sorted(t_stack *a);

// D LST FTs

void	ft_dlstadd_back(t_stack **lst, t_stack *node);
t_stack	*ft_dlstlast(t_stack *lst);
t_stack	*ft_dlstnew(void *content);
int		ft_dlstsize(t_stack *lst);

// OPERATIONS sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);
void	ft_pb(t_stack **a, t_stack **b, int print);
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_ra(t_stack **a, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	ft_rra(t_stack **a, int print);
void	ft_rrb(t_stack **b, int print);

// t_stack	ft_sort(t_stack stack_a);

#endif
