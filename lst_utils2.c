/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:39:33 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/15 16:24:52 by tbruha           ###   ########.fr       */
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

// Here I look for and return node with lowest number.
t_stack	*find_min_number(t_stack *lst)
{
	t_stack	*min_number;

	min_number = lst;
	while (lst)
	{
		if (lst->number < min_number->number)
			min_number = lst;
		lst = lst->next;
	}
	return (min_number);
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

// It finds and returns node with cheapest push_price.
t_stack	*get_cheapest_node(t_stack **a)
{
	t_stack	*cheap;
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->cheapest == true)
			cheap = temp;
		temp = temp->next;
	}
	return (cheap);
}
