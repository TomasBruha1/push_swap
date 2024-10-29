/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:37 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/29 18:41:44 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra - Shifts down all elements in stack a, last one becomes first one.
void	ft_rra(t_stack **a, int print)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = temp;
	while (i > 0)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}

// rrb - Shifts down ll elements in stack b, last one becomes first one.
void	ft_rrb(t_stack **b, int print)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (!*b || !(*b)->next)
		return ;
	temp = (*b);
	while ((*b)->next)
	{
		(*b) = (*b)->next;
		i++;
	}
	(*b)->next = temp;
	while (i > 0)
	{
		temp = temp->next;
		i--;
	}
	if (print == 1)
		write(1, "rrb\n", 4);
}

// rrr - Does rra and rrb at the same time.
// void	ft_rrr(t_stack **a, t_stack **b, int print)
// {

// }