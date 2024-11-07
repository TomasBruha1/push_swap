/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/07 20:51:08 by tbruha           ###   ########.fr       */
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
		sort_big(a);
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

// Check if a->next->next is max. If it is do swap and done. // DONE
// If 
// 
// 
// 

// If I have over 3 elements I will
void	sort_big(t_stack **a)
{
	if (!a)
		return ;
}