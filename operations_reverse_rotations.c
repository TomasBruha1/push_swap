/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:37 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/16 17:35:38 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra - Shifts down all elements in stack_a, last one becomes first one.
void	ft_rra(t_stack **stack_a, int print)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = temp;
	while (i > 0)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}

// rrb - Shifts down ll elements in stack_b, last one becomes first one.
void	ft_rrb(t_stack **stack_b, int print)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b);
	while ((*stack_b)->next)
	{
		(*stack_b) = (*stack_b)->next;
		i++;
	}
	(*stack_b)->next = temp;
	while (i > 0)
	{
		temp = temp->next;
		i--;
	}
	if (print == 1)
		write(1, "rrb\n", 4);
}

// rrr - Does rra and rrb at the same time.
// void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int print)
// {

// }