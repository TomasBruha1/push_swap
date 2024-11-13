/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/13 18:42:45 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here I check number of arguments and pick how to solve it.
void	what2sort(t_stack **a)
{
	if (ft_dlstsize(*a) == 2)
		sa(a, 1);
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

// If I have over 3 elements I will start moving them to b one by one until I have 3 left in a.
void	sort_big(t_stack **a)
{
	t_stack	*b;
	int		i;
	t_stack *temp; // just for testing
	
	i = 1;
	b = NULL;
	temp = *a;
	pb(a, &b, 1); // first pb is automatic.
	if (!check_if_sorted(*a) && ft_dlstsize(*a) > 3) // Only if not sorted and above 3 elem.
		pb(a, &b, 1);
	while (!check_if_sorted(*a) && ft_dlstsize(*a) > 3)
	{
		preparing_nodes(a, &b);
		print_stack_stuff(*a, b);
		push_node_to_b(a, &b);
		// don't forget to reset bool for cheapest.
	}
	sort_3(a);
	print_stack_stuff(*a, b);
	// DO LATER while nodes in b keep pushing to a....
	// DO LATER ft push_node_to_a 
	
	// DO LATER free b
}

void	preparing_nodes(t_stack **a, t_stack **b)
{
	reset_nodes(a);
	reset_nodes(b);
	assign_value_index(a);
	assign_value_index(b);
	assign_target_node_in_b(a, b);
	assign_index(a);
	assign_index(b);
	above_median(a);
	above_median(b);
	push_price(a, b);
	find_cheapest(a);
}

// Set of functions to assign index, target, price, cheapest and above_median to node.
// Afterwards I pick the cheapest node and push it to b. Reset bools before or after??
void	push_node_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheap;
	
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
	printf("\ntop of a: %d\ntop of b: %d\n\n", (*a)->number, (*b)->number);
	pb(a, b, 1);
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
			(target == NULL || temp->number > target->number))
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
		count = 1;
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

// It finds and returns node with cheapest push_price.
t_stack	*get_cheapest_node(t_stack **a)
{
	t_stack	*cheap;
	t_stack *temp;

	temp = *a;
	while (temp)
	{
		if (temp->cheapest == true)
			cheap = temp;
		temp = temp->next;
	}
	return (cheap);
}

// It will rotate cheapest and his target node to top of both stacks.
void	push_to_top(t_stack **a, t_stack **b, t_stack *cheap)
{
	if (cheap->above_median == true)
		while (cheap != *a)
			ra(a, 1);
	else
		while (cheap != *a)
			rra(a, 1);
	if (cheap->target_node->above_median == true)
		while (cheap->target_node !=*b)
			rb(b, 1);
	else
		while (cheap->target_node != *b)
			rrb(b, 1);
}
