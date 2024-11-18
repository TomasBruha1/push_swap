/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/18 14:30:51 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here I check number of arguments and pick how to solve it.
void	what2sort(t_stack **a)
{
	if (ft_dlstsize(*a) == 2)
		sa(a, 1);
	else if (ft_dlstsize(*a) == 3)
		sort_3(a);
	else
		sort_big(a);
}

// Hard coded for exactly 3 elements.
void	sort_3(t_stack **a)
{
	assign_value_index(a);
	if ((*a)->next->next->value_index == 2)
		sa(a, 1);
	else if ((*a)->next->value_index == 2)
	{
		rra(a, 1);
		if ((*a)->value_index == 1)
			sa(a, 1);
	}
	else
	{
		ra(a, 1);
		if ((*a)->value_index == 1)
			sa(a, 1);
	}
}

// If I have over 3 elements I will move them to b. After initialization we do
// pb and repeat until there are 3 left in a. Then we sort and push b to a.
void	sort_big(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	pb(a, &b, 1);
	if (!check_if_sorted(*a) && ft_dlstsize(*a) > 3)
		pb(a, &b, 1);
	while (!check_if_sorted(*a) && ft_dlstsize(*a) > 3)
	{
		prep_nodes_in_a(a, &b);
		push_node_to_b(a, &b);
	}
	if (!check_if_sorted(*a))
	{
		prep_nodes_in_a(a, &b);
		sort_3(a);
	}
	prep_nodes_in_a(a, &b);
	while (b)
	{
		prep_nodes_in_b(a, &b);
		push_node_to_a(a, &b);
	}
	min_on_top(a);
	// DO LATER free b
}

// I will find cheapest node and then set of instructions how to rotate
// nodes based on the cheapest node. Once we do double rotations we finish
// with single rotations to top of stacks and push to b.
void	push_node_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest_node(a);
	if (cheap->above_median == true &&
	cheap->target_node->above_median == true)
		while (cheap != *a && cheap->target_node != *b)
			rr(a, b, 1);
	else if (cheap->above_median == false && 
	cheap->target_node->above_median == false)
		while (cheap !=*a && cheap->target_node !=*b)
			rrr(a, b, 1);
	push_to_top(a, b, cheap);
	pb(a, b, 1);
}

// I will find cheapest node and then set of instructions how to rotate
// nodes based on the cheapest node. Once we do double rotations we finish
// with single rotations to top of stacks and push back to a.
void	push_node_to_a(t_stack **a, t_stack **b)
{
	t_stack *current;
	
	current = *b;
	if (current->above_median == true && 
	current->target_node->above_median == true)
		while (current != *b && current->target_node != *a)
			rr(a, b, 1);
	else if (current->above_median == false && 
	current->target_node->above_median == false)
		while (current !=*b && current->target_node !=*a)
			rrr(a, b, 1);
	push_to_top2(a, b, current);
	pa(a, b, 1);
}
