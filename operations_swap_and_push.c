/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_and_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:08:14 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/29 18:40:48 by tbruha           ###   ########.fr       */
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

// This function swaps first two elements in b.
void	ft_sb(t_stack **b, int print)
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

// Need to rewrite this because I need to print ss and not sa+sb.
// WILL COME BACK TO THIS LATER.
void	ft_ss(t_stack **a, t_stack **b, int print)
{
	ft_sa(a, print);
	ft_sb(b, print);
}

// Takes the top element of a and pushes it to top of b.
void	ft_pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}

// Takes the top element of b and pushes it to top of a.
void	ft_pa(t_stack **a, t_stack **b, int print)
{
	t_stack *temp;

	if (!*b)
		return ;
	temp = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = temp;
	if (print == 1)
		write(1, "pa\n", 3);
}
