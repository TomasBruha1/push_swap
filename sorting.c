/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/14 19:06:59 by tbruha           ###   ########.fr       */
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
	
	i = 1;
	b = NULL;
	pb(a, &b, 1);
	if (!check_if_sorted(*a) && ft_dlstsize(*a) > 3)
		pb(a, &b, 1);
	while (!check_if_sorted(*a) && ft_dlstsize(*a) > 3)
	{
		prep_nodes_in_a(a, &b);
		push_node_to_b(a, &b);
	}
	prep_nodes_in_a(a, &b);
	sort_3(a);
	while (b)
	{
		prep_nodes_in_b(a, &b);
		push_node_to_a(a, &b);
	}
	min_on_top(a);
	// DO LATER free b
}

void	min_on_top(t_stack **a)
{
	t_stack *min_number;
	
	min_number = find_min_number(*a);
	if (min_number->above_median == true)
		while (min_number != *a)
			ra(a, 1);
	else
		while (min_number != *a)
			rra(a, 1);
}

void	prep_nodes_in_a(t_stack **a, t_stack **b)
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
	push_price_a_nodes(a, b);
	find_cheapest(a);
}

void	prep_nodes_in_b(t_stack **a, t_stack **b)
{
	assign_target_node_in_a(a, b);
	assign_index(a);
	assign_index(b);
	above_median(a);
	above_median(b);
	push_price_b_nodes(a, b);
	find_cheapest(b);
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
	pb(a, b, 1);
}

void	push_node_to_a(t_stack **a, t_stack **b)
{
	t_stack *cheap;
	
	cheap = get_cheapest_node(b);
	if (cheap->above_median == true && 
	cheap->target_node->above_median == true)
		while (cheap != *b && cheap->target_node != *a)
			rr(a, b, 1);
	else if (cheap->above_median == false && 
	cheap->target_node->above_median == false)
		while (cheap !=*b && cheap->target_node !=*a)
			rrr(a, b, 1);
	push_to_top2(a, b, cheap);
	pa(a, b, 1);
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

// I NEED NEAREST HIGHER OR MIN. I work with values of numbers here.
// Here I assign target nodes in b to nodes in a.
void	assign_target_node_in_a(t_stack **a, t_stack **b)
{	
	t_stack *current;
	t_stack *target;
	t_stack	*temp;
	
	current = *b;
	while (current != NULL)
	{
		temp = *a;
		target = NULL;
		while (temp != NULL)
		{
			if (temp->number > current->number && 
			(target == NULL || temp->number < target->number))
				target = temp;
			temp = temp->next;
		}
		if (target == NULL)
			target = find_min_number(*a);
		current->target_node = target;
		current = current->next;
	}
}

// Here I calculate how many ops its gonna cost to move both nodes to the top.
// For this I need to see if its above or below median FIRST.
void	push_price_a_nodes(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		count_a;
	int		count_b;

	temp = *a;
	while (temp)
	{
		count_a = 0;
		count_b = 0;
		if (temp->above_median == true)
			count_a += temp->index;
		else
			count_a += ((ft_dlstsize(*a)) - (temp->index));
		if (temp->target_node->above_median == true)
			count_b += temp->target_node->index;
		else
			count_b += (ft_dlstsize(*b)) - (temp->target_node->index);
		if ((temp->above_median == true && temp->target_node->above_median == true)
		|| (temp->above_median == false && temp->target_node->above_median == false))
			temp->push_price = price_reduction_count(count_a, count_b) + 1;
		else
			temp->push_price = count_a + count_b + 1;
		temp = temp->next;
	}
}

int	price_reduction_count(int count_a, int count_b)
{
	if (count_a >= count_b)
		return (count_a);
	else
		return (count_b);
}

void	push_price_b_nodes(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		count_a;
	int		count_b;

	temp = *b;
	while (temp)
	{
		count_a = 0;
		count_b = 0;
		if (temp->above_median == true)
			count_a += temp->index;
		else
			count_a += ((ft_dlstsize(*b)) - (temp->index));
		if (temp->target_node->above_median == true)
			count_b += temp->target_node->index;
		else
			count_b += (ft_dlstsize(*a)) - (temp->target_node->index);
		if ((temp->above_median == true && temp->target_node->above_median == true)
		|| (temp->above_median == false && temp->target_node->above_median == false))
			temp->push_price = price_reduction_count(count_a, count_b);
		else
			temp->push_price = count_a + count_b;
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
