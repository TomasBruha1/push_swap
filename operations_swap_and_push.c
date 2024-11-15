/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_and_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:08:14 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/15 16:22:32 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function swaps first two elements in a.
void	sa(t_stack **a, int print)
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

// This function swaps first two elements in b.
void	sb(t_stack **b, int print)
{
	t_stack	*temp;

	if (!*b || !(*b)->next)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

// It does sa and sb at the same time for cost of one move and prints ss.
void	ss(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*a ||!*b || !(*a)->next || !(*b)->next)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	temp = *b;
	(*b) = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (print == 1)
		write(1, "ss\n", 3);
}

// Takes the top element of a and pushes it to top of b.
void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (print == 1)
		write(1, "pb\n", 3);
}

// Takes the top element of b and pushes it to top of a.
void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}
