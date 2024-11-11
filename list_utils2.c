/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:39:33 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/11 17:55:06 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here I look for and return node with lowest index.
t_stack	*find_min_index(t_stack *lst)
{
	t_stack	*min_node;

	min_node = lst;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->index < min_node->index)
			min_node = lst;
		lst = lst->next;
	}
	return (min_node);
}

// Here I look for and return node with highest index.
t_stack	*find_max_index(t_stack *lst)
{
	t_stack	*max_node;

	max_node = lst;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->index > max_node->index)
			max_node = lst;
		lst = lst->next;
	}
	return (max_node);
}

// Here I look for and return node with highest number.
t_stack	*find_max_number(t_stack *lst)
{
	t_stack	*max_number;

	max_number = lst;
	while (lst)
	{
		if (lst->number > max_number->number)
			max_number = lst;
		lst = lst->next;
	}
	return (max_number);
}

// This function resets value_index for all nodes in the stack to -1.
void	reset_value_index(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	while (temp)
	{
		temp->value_index = -1;
		temp = temp->next;
	}
}

// It will assign regular index to a node.
void	assign_index(t_stack **lst)
{
	t_stack	*temp;
	int		index;
	
	temp = *lst;
	index = 0;
	while (temp)
	{
		temp->index = index;
		index++;
		temp = temp->next;
	}
}

t_stack	find_cheapest_node(t_stack *a)
{
	
}
