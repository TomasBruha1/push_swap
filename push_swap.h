/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:40 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/15 11:18:28 by tbruha           ###   ########.fr       */
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

// PUSH_SWAP FTs

// push_swap.c
void	init_parse_stack(t_stack **a, char **argv);
void	init_stack(t_stack **a, char **argv);
int		check_if_sorted(t_stack *a);
void	check_duplicates(t_stack *lst);

// ERROR MGMT
// errors_free_and_other.c
long	ft_atol(const char *nptr);
void	ft_error(void);
int		is_arg_valid(char *arg);

// LIST FTs
// lst_utils1.c
void	ft_dlstadd_back(t_stack **lst, t_stack *node);
t_stack	*ft_dlstlast(t_stack *lst);
t_stack	*ft_dlstnew(void *content);
int		ft_dlstsize(t_stack *lst);
// lst_utils2.c
t_stack	*find_min_index(t_stack *lst);
t_stack	*find_max_index(t_stack *lst);
t_stack	*find_min_number(t_stack *lst);
t_stack	*find_max_number(t_stack *lst);
t_stack	*get_cheapest_node(t_stack **a);

// INITIALIZING NODES
// nodes_info1.c
void	assign_target_node_in_b(t_stack **a, t_stack **b);
void	assign_target_node_in_a(t_stack **a, t_stack **b);
void	assign_value_index(t_stack **lst);
void	reset_nodes(t_stack **lst);
void	above_median(t_stack **lst);
// nodes_info2.c
void	push_price_a_nodes(t_stack **a, t_stack **b);
void	push_price_b_nodes(t_stack **a, t_stack **b);
int		price_reduction_count(int count_a, int count_b);
void	assign_index(t_stack **lst);
void	find_cheapest(t_stack **a);

// SORTING FTs

// sorting1.c
void	what2sort(t_stack **a);
void	sort_3(t_stack **a);
void	sort_big(t_stack **a);
void	push_node_to_b(t_stack **a, t_stack **b);
void	push_node_to_a(t_stack **a, t_stack **b);
// sorting2.c
void	prep_nodes_in_a(t_stack **a, t_stack **b);
void	prep_nodes_in_b(t_stack **a, t_stack **b);
void	push_to_top(t_stack **a, t_stack **b, t_stack *cheap);
void	push_to_top2(t_stack **a, t_stack **b, t_stack *cheap);
void	min_on_top(t_stack **a);

// OPERATIONS sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
// operations_swap_and_push.c
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
// operations_rotations.c
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
// operations_reverse_rotations.c
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	fake_rra(t_stack **a);
void	fake_rrb(t_stack **b);

// HELPER >> DELETE LATER

void	print_stack_stuff(t_stack *stack_a, t_stack *stack_b);

#endif
