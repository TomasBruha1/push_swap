/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:05:20 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/15 16:33:14 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here I calculate how many ops(moves) it will cost each node to be pushed
// on top of its target node in b.
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
		if ((temp->above_median == true && temp->target_node->above_median
			== true) || (temp->above_median == false
			 && temp->target_node->above_median == false))
			temp->push_price = price_reduction_count(count_a, count_b) + 1;
		else
			temp->push_price = count_a + count_b + 1;
		temp = temp->next;
	}
}

// Here I calculate how many ops(moves) it will cost each node to be pushed
//on top of its target node in a.
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
		if ((temp->above_median == true && 
			temp->target_node->above_median == true)
			|| (temp->above_median == false && temp->target_node->above_median
			 == false))
			temp->push_price = price_reduction_count(count_a, count_b);
		else
			temp->push_price = count_a + count_b;
		temp = temp->next;
	}
}

// If the given node and its target are both above or both below median
// this function will return the reduced count for the push_price.
int	price_reduction_count(int count_a, int count_b)
{
	if (count_a >= count_b)
		return (count_a);
	else
		return (count_b);
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

// Here I assign true/false to node if it is above median or not.
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
