/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:41:46 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/03 14:37:38 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	what2sort(t_stack **a)
{
	if (ft_dlstsize(*a) == 2)
		ft_sa(a, 1);
	else if(ft_dlstsize(*a) == 3)
		sort_3(a);
	else
		sort_big(a);
}

void	sort_3(t_stack **a)
{
	if (!a)
		return ;

	// I need their indexes

	// function to add all struct element's a value.
	
	
	
}

void	sort_big(t_stack **a)
{
	if (!a)
		return ;
}