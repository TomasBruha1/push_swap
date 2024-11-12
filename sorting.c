/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/12 17:35:15 by tbruha           ###   ########.fr       */
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
	// / maybe add check_if_sorted, let's see...
	assign_value_index(a);
	if ((*a)->next->next->value_index == 2)
		ft_sa(a, 1);
	else if ((*a)->next->value_index == 2)
	{
		ft_rra(a, 1);
		if ((*a)->value_index == 1)
			ft_sa(a, 1);
	}
	else
	{
		ft_ra(a, 1);
		if ((*a)->value_index == 1)
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
	assign_value_index(a);
	assign_value_index(b);
	assign_target_node_in_b(a, b);
	assign_index(a);
	assign_index(b);
	above_median(a);
	above_median(b);
	push_price(a, b);
	find_cheapest(*a);
	ft_pb(a, b, 1);
	
	// while (*a)
	// {
	// 	if ((*a)->cheapest)
	// 		printf("\ncheapest node value: %d", (*a)->number);
	// 	(*a) = (*a)->next;
	// }
	print_stack_stuff(*a, *b);
	
	exit(2);
}
	
// I NEED NEAREST LOWER OR MAX. I work with values of numbers here.
// Here I assign target nodes in b to nodes in a.
void	assign_target_node_in_b(t_stack **a, t_stack **b)
{	
	t_stack *current;
	t_stack *target;
	t_stack	*temp;
	
	current = *a;
	while (current != NULL)
	{
		temp = *b;
		target = NULL;
		while (temp != NULL)
		{
			if (temp->number < current->number && 
			(target == NULL ||temp->number > target->number))
				target = temp;
			temp = temp->next;
		}
		if (target == NULL)
			target = find_max_number(*b);
		current->target_node = target;
		current = current->next;
	}
}

// Here I calculate how many ops its gonna cost to move both nodes to the top.
// For this I need to see if its above or below median FIRST.
void	push_price(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		count;

	temp = *a;
	while (temp)
	{
		count = 0;
		if (temp->above_median == true)
			count += temp->index;
		else
			count += ((ft_dlstsize(*a)) - (temp->index));
		if (temp->target_node->above_median == true)
			count += temp->target_node->index;
		else
			count += (ft_dlstsize(*b)) - (temp->target_node->index);
		temp->push_price = count;
		temp = temp->next;	
	}
}

// Here I assign bool to node if it is above median or not.
void	above_median(t_stack **lst)
{
	int		i;
	t_stack	*temp;
	
	i = ft_dlstsize(*lst);
	temp = *lst;
	while (temp)
	{
		if (temp->index <= i / 2)
			temp->above_median = true;
		else
			temp->above_median = false;
		temp = temp->next;
	}
}
