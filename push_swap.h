/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:40 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/11 17:33:02 by tbruha           ###   ########.fr       */
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
	int		value_index;
	int		index;
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
t_stack	*find_min_index(t_stack *lst);
t_stack	*find_max_index(t_stack *lst);
t_stack	*find_max_number(t_stack *lst);
void	assign_target_node_in_b(t_stack **a, t_stack **b);
void	assign_value_index(t_stack **lst);
void	reset_value_index(t_stack **lst);
void	above_median(t_stack **lst);
void	push_price(t_stack **a, t_stack **b);
void	assign_index(t_stack **lst);

// SORTING FTs

void	what2sort(t_stack **a);
void	sort_3(t_stack **a);
void	sort_big(t_stack **a);
void	push_node_to_b(t_stack **a, t_stack **b);

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
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	fake_rra(t_stack **a);
void	fake_rrb(t_stack **b);

// HELPER DELETE LATER

void	print_stack_stuff(t_stack *stack_a, t_stack *stack_b);

#endif
