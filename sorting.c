/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/08 16:01:26 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here I check number of arguments and pick how to solve it.
void	what2sort(t_stack **a)
{
	if (ft_dlstsize(*a) == 2)
		ft_sa(a, 1);
	else if(ft_dlstsize(*a) == 3)
		sort_3(a);
	else
	{
		printf("**a = value: %d\n", (*a)->number);
		sort_big(a);
	}
}

// Hard coded for exactly 3 elements.
void	sort_3(t_stack **a)
{
	// maybe add check_if_sorted, let's see...
	ft_dlst_assign_index(a);
	if ((*a)->next->next->index == 2)
		ft_sa(a, 1);
	else if ((*a)->next->index == 2)
	{
		ft_rra(a, 1);
		if ((*a)->index == 1)
			ft_sa(a, 1);
	}
	else
	{
		ft_ra(a, 1);
		if ((*a)->index == 1)
			ft_sa(a, 1);
	}
}

// 4 elem back to a from b.
// 
// 
// 

// If I have over 3 elements I will
void	sort_big(t_stack **a)
{
	t_stack	*b;
	int		i;
	
	i = 1;
	b = NULL;
	ft_pb(a, &b, 1); // first pb is automatic.
	if (!check_if_sorted(*a) && ft_dlstsize(*a) > 3) // Only if not sorted and above 3 elem.
		ft_pb(a, &b, 1);
	while (!check_if_sorted(*a) && ft_dlstsize(*a) > 3)
	{
		push_node_to_b(a, &b);
		
		// push_node_to_b
		// ft where I assign index > target node > above_median or not > push_price > cheapest
		// don't forget to reset bool for cheapest.
		// OK do one function from the list above to start with. NOW.
	}
	sort_3(a);
	// while nodes in b keep pushing to a....
	// ft push_node_to_a 
	
	// free b
	while ((*a) != NULL)
	{
		printf("Stack a node %d   value: %d   with index: %d\n", i, (*a)->number, (*a)->index);
		(*a) = (*a)->next;
		i++;
	}
	i = 1;
	write(1, "\n", 2);
	while (b != NULL)
	{
		printf("Stack b node %d   value: %d   with index: %d\n", i, b->number, b->index);
		b = b->next;
		i++;
	}
}

// Set of functions to assign index, target, price, cheapest and above_median to node.
// Afterwards I pick the cheapest node and push it to b. Reset bools before or after??
void	push_node_to_b(t_stack **a, t_stack **b)
{
	// Where to implement reset function for nodes so my assigning functions work.
	ft_dlst_assign_index(a);
	ft_dlst_assign_index(b);
	assign_target_node_in_b(a, b);
	// 
}

// Check how to eliminate nodes already with target nodes. Ones that aren't == NULL?

// I NEED NEAREST LOWER OR MAX. I work with values of numbers here.

void	assign_target_node_in_b(t_stack **a, t_stack **b)
{	
	t_stack *current_node_a; // only to traverse the list and assign target_node to them
	t_stack *target_node_b; // node in "b" that I'm looking for
	t_stack	*temp; // who knows what for, but let's see...
	
	temp = *a;
	current_node_a = *a;
	while (current_node_a != NULL)
	{
		target_node_b = *b;
		if ((current_node_a)->number < )
		
		current_node_a = target_node_b;
		current_node_a = current_node_a->next;
	}
	
}
