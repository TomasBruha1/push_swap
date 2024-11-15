/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_info1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:28:30 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/15 13:20:59 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here I assign target nodes in b to nodes in a.
// I look for closest lower or MAX number.
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

// Here I assign target nodes in b to nodes in a.
// I'm looking for closest higher or MIN node.
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

// This function will give each node in the stack an index value.
void	assign_value_index(t_stack **lst)
{
	t_stack	*current;
	t_stack	*min_node;
	int		index;
	int		min_number;
	
	if (!*lst)
		return ;
	index = 0;
	while (1)
	{
		current = *lst;
		min_node = NULL;
		min_number = INT_MAX;
		while (current)
		{
			if (current->number < min_number && current->value_index == -1)
			{
				min_number = current->number;
				min_node = current;
			}
			current = current->next;
		}
		if (min_node == NULL)
			break ;
		min_node->value_index = index++;
	}
}

// This function resets value_index for all nodes in the stack to -1.
void	reset_nodes(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	while (temp)
	{
		temp->value_index = -1;
		temp = temp->next;
	}
}

// It will mark the node with lowest push_price bool for cheapest as TRUE.
void	find_cheapest(t_stack **a)
{
	t_stack	*cheapest_node;
	t_stack	*temp;

	cheapest_node = *a;
	temp = *a;
	while (temp)
	{
		if (temp->push_price < cheapest_node->push_price)
			cheapest_node = temp;
		temp = temp->next;
	}
	cheapest_node->cheapest = true;
}
