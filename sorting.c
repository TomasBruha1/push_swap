/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/08 23:29:37 by tbruha           ###   ########.fr       */
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
		sort_big(a);
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

// If I have over 3 elements I will start moving them to b one by one until I have 3 left in a.
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
		// ft where I assign index > target node > above_median or not > push_price > cheapest
		// push_node_to_b
		// don't forget to reset bool for cheapest.
		// OK do one function from the list above to start with. NOW.
	//	ft_error();
	}
	sort_3(a);
	// DO LATER while nodes in b keep pushing to a....
	// DO LATER ft push_node_to_a 
	
	// DO LATER free b
}

// Set of functions to assign index, target, price, cheapest and above_median to node.
// Afterwards I pick the cheapest node and push it to b. Reset bools before or after??
void	push_node_to_b(t_stack **a, t_stack **b)
{
	ft_pb(a, b, 1);
	print_stack_stuff(*a, 'a');
	print_stack_stuff(*b, 'b');
	ft_dlst_assign_index(a);
	ft_dlst_assign_index(b);
	print_stack_stuff(*a, 'a');
	print_stack_stuff(*b, 'b');
	ft_pb(a, b, 1);
	ft_pb(a, b, 1);
	ft_pb(a, b, 1);
	ft_pb(a, b, 1);
	ft_dlst_assign_index(a);
	ft_dlst_assign_index(b);
	print_stack_stuff(*a, 'a');
	print_stack_stuff(*b, 'b');
	assign_target_node_in_b(a, b);
	print_stack_stuff(*a, 'a');
	print_stack_stuff(*b, 'b');

	printf("Node 1 = %d and target is %d\n", (*a)->number, (*a)->target_node->number);
	printf("Node 2 = %d and target is %d\n", (*a)->next->number, (*a)->next->target_node->number);
	printf("Node 3 = %d and target is %d\n", (*a)->next->next->number, (*a)->next->next->target_node->number);
	
	// actually push to b
}
	
// I NEED NEAREST LOWER OR MAX. I work with values of numbers here.
// Here I assign target nodes in b to nodes in a.
void	assign_target_node_in_b(t_stack **a, t_stack **b)
{	
	t_stack *current; // only to traverse the list and assign target_node to them
	t_stack *target; // node in "b" that I'm looking for
	t_stack	*temp; // to traverse "b"
	
	current = *a;
	while (current != NULL)
	{
		temp = *b;
		target = *b; // I need to set it equal to "find_min_number" function I will create.
		while (temp != NULL)
		{
			if (temp->number < current->number && temp->number > target->number) // icky
				target = temp;
			temp = temp->next;
		}
		if (target->number > current->number)
			target = find_max_number(*b);
		current->target_node = target;
		current = current->next;
	}
}

// line 105 // target = *b;