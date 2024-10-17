/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:30 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/16 17:35:31 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all elements in stack_a by 1. 1st element becomes the last one.
void	ft_ra(t_stack **stack_a, int print)
{
	t_stack	*temp;

	temp = (*stack_a)->next;
	ft_lstlastdouble(*stack_a)->next = (*stack_a);
	(*stack_a)->next = NULL;
	(*stack_a) = temp;
	if (print == 1)
		write(1, "ra\n", 3);
}

// Shifts all elements in stack_b by 1. 1st element becomes the last one.
void	ft_rb(t_stack **stack_b, int print)
{
	t_stack	*temp;

	temp = (*stack_b)->next;
	ft_lstlastdouble(*stack_b)->next = (*stack_b);
	(*stack_b)->next = NULL;
	(*stack_b) = temp;
	if (print == 1)
		write(1, "rb\n", 3);
}

// Shifts up both stacks by 1.
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;

	temp = (*stack_a)->next;
	ft_lstlastdouble(*stack_a)->next = (*stack_a);
	(*stack_a)->next = NULL;
	(*stack_a) = temp;
	temp = (*stack_b)->next;
	ft_lstlastdouble(stack_b)->next = (stack_b);
	(*stack_b)->next = NULL;
	(*stack_b) = temp;
	if (print == 1)
		write(1, "rr\n", 3);
}
