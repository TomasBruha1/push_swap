/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_and_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:08:14 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/09 16:08:16 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a, int print)
{
	t_stack	*temp;

	if (!*stack_a || ft_lstsize(*stack_a) < 2)
		return ;
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

