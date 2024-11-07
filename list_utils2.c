/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:39:33 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/07 19:03:54 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
