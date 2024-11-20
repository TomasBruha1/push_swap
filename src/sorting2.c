/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:10:12 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/18 16:22:28 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function where I update and reset node values after every push to b.
void	prep_nodes_in_a(t_stack **a, t_stack **b)
{
	reset_nodes(a);
	reset_nodes(b);
	assign_value_index(a, 0);
	assign_value_index(b, 0);
	assign_target_node_in_b(a, b);
	assign_index(a);
	assign_index(b);
	above_median(a);
	above_median(b);
	push_price_a_nodes(a, b);
	find_cheapest(a);
}

// function where I update and reset node values after every push to a.
void	prep_nodes_in_b(t_stack **a, t_stack **b)
{
	assign_target_node_in_a(a, b);
	assign_index(a);
	assign_index(b);
	above_median(a);
	above_median(b);
}

// It will rotate cheap and his target node to top of both stacks. (a -> b)
void	push_to_top(t_stack **a, t_stack **b, t_stack *cheap)
{
	if (cheap->above_median == true)
		while (cheap != *a)
			ra(a, 1);
	else
		while (cheap != *a)
			rra(a, 1);
	if (cheap->target_node->above_median == true)
		while (cheap->target_node != *b)
			rb(b, 1);
	else
		while (cheap->target_node != *b)
			rrb(b, 1);
}

// It will rotate cheap and his target node to top of both stacks. (b -> a)
void	push_to_top2(t_stack **a, t_stack **b, t_stack *cheap)
{
	if (cheap->above_median == true)
		while (cheap != *b)
			rb(b, 1);
	else
		while (cheap != *b)
			rrb(b, 1);
	if (cheap->target_node->above_median == true)
		while (cheap->target_node != *a)
			ra(a, 1);
	else
		while (cheap->target_node != *a)
			rra(a, 1);
}

// Once everything is sorted in a this will bring the lowest node to the top.
void	min_on_top(t_stack **a)
{
	t_stack	*min_number;

	min_number = find_min_number(*a);
	if (min_number->above_median == true)
		while (min_number != *a)
			ra(a, 1);
	else
		while (min_number != *a)
			rra(a, 1);
}
