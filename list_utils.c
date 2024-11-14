/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:43:05 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/14 19:08:20 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// It adds new node to the end of double list.
void	ft_dlstadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		(*lst) = node;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
	}
	else
	{
		last = ft_dlstlast(*lst);
		last->next = node;
		node->prev = last;
		node->next = NULL;
	}
}

// It finds the last node in a stack.
t_stack	*ft_dlstlast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

// It creates new node in double linked list.
// Do I need to NULL rest of the attributes for this node?
t_stack	*ft_dlstnew(void *content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = *(int *)content;
	new_node->index = -1;
	new_node->value_index = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->cheapest = false;
	new_node->above_median = false;
	new_node->push_price = INT_MAX;
	new_node->target_node = NULL;
	return (new_node);
}

// It returns the number of nodes in the stack.
int	ft_dlstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
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
