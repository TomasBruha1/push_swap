/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:30 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/02 10:15:47 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all elements in a by 1. 1st element becomes the last one.
void	ft_ra(t_stack **a, int print)
{
	t_stack	*temp;

	temp = (*a)->next;
	ft_dlstlast(*a)->next = (*a);
	(*a)->next = NULL;
	(*a) = temp;
	if (print == 1)
		write(1, "ra\n", 3);
}

// Shifts all elements in b by 1. 1st element becomes the last one.
void	ft_rb(t_stack **b, int print)
{
	t_stack	*temp;

	temp = (*b)->next;
	ft_dlstlast(*b)->next = (*b);
	(*b)->next = NULL;
	(*b) = temp;
	if (print == 1)
		write(1, "rb\n", 3);
}

// Shifts up both stacks by 1.
void	ft_rr(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	temp = (*a)->next;
	ft_dlstlast(*a)->next = (*a);
	(*a)->next = NULL;
	(*a) = temp;
	temp = (*b)->next;
	ft_dlstlast(*b)->next = (*b);
	(*b)->next = NULL;
	(*b) = temp;
	if (print == 1)
		write(1, "rr\n", 3);
}
