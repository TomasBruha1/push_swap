/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:43:05 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/29 18:02:27 by tbruha           ###   ########.fr       */
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
		(*lst)->previous = NULL;
	}
	else
	{
		last = ft_dlstlast(*lst);
		last->next = node;
		node->previous = last;
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
	new_node->previous = NULL;
	new_node->next = NULL;
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
