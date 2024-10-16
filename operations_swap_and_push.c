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

// This function swaps first two elements in stack_a.
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

// This function swaps first two elements in stack_b.
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

// Need to rewrite this because I need to print ss and not sa+sb.
// WILL COME BACK TO THIS LATER.
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	ft_sa(stack_a, print);
	ft_sb(stack_b, print);
}

// Takes the top element of stack_a and pushes it to top of stack_b.
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}

// Takes the top element of stack_b and pushes it to top of stack_a.
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack *temp;

	if (!*stack_b)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_b) = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}