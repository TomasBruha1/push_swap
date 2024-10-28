/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_and_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:08:14 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/28 20:06:56 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function swaps first two elements in a.
void	ft_sa(t_stack **a, int print)
{
	t_stack	*temp;

	if (!*a || ft_dlstsize(*a) < 2)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
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
void	ft_ss(t_stack **a, t_stack **stack_b, int print)
{
	ft_sa(a, print);
	ft_sb(stack_b, print);
}

// Takes the top element of a and pushes it to top of stack_b.
void	ft_pb(t_stack **a, t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = (*a)->next;
	(*a)->next = (*stack_b);
	(*stack_b) = (*a);
	(*a) = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}

// Takes the top element of stack_b and pushes it to top of a.
void	ft_pa(t_stack **a, t_stack **stack_b, int print)
{
	t_stack *temp;

	if (!*stack_b)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = (*a);
	(*a) = (*stack_b);
	(*stack_b) = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}