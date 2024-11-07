/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/07 22:57:47 by tbruha           ###   ########.fr       */
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
	{
		printf("**a = value: %d\n", (*a)->number);
		sort_big(a);
	}
}

// Hard coded for exactly 3 elements.
void	sort_3(t_stack **a)
{
	ft_dlst_assign_index(a);
	
	if ((*a)->next->next->index == 2)
		ft_sa(a, 1);
	else if ((*a)->next->index == 2)
	{
		ft_rra(a, 1);
		if ((*a)->index == 1)
			ft_sa(a, 1);
	}
	else
	{
		ft_ra(a, 1);
		if ((*a)->index == 1)
			ft_sa(a, 1);
	}
}

// init stack_b > push one
// 
// 
// 

// If I have over 3 elements I will
void	sort_big(t_stack **a)
{
	t_stack	*b;
	int		i;
	
	i = 1;
	write(1, "a\n", 2);
	b = NULL;
	ft_pb(a, &b, 1);
	if (!check_if_sorted(*a) && ft_dlstsize(*a) > 3)
		ft_pb(a, &b, 1);
	

	
	//if less than 3 > sort 3 and return from b

	// free b
	while ((*a) != NULL)
	{
		printf("Stack a node %d   value: %d   with index: %d\n", i, (*a)->number, (*a)->index);
		(*a) = (*a)->next;
		i++;
	}
	i = 1;
	write(1, "\n", 2);
	while (b != NULL)
	{
		printf("Stack b node %d   value: %d   with index: %d\n", i, b->number, b->index);
		b = b->next;
		i++;
	}
}
