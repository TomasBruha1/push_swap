/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:37 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/12 17:53:51 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra - Shifts down all elements in stack a, last one becomes first one.
// Avoid using *a=*a->next (WHY? No idea).
void	rra(t_stack **a, int print)
{
	t_stack	*temp;
	t_stack *temp2;
	
	if (!*a || !(*a)->next)
		return ;
	temp = ft_dlstlast(*a);
	temp2 = *a;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *a;
	*a = temp;
	temp2->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}

// rrb - Shifts down ll elements in stack b, last one becomes first one.
void	rrb(t_stack **b, int print)
{
	t_stack	*temp;
	t_stack *temp2;
	
	if (!*b || !(*b)->next)
		return ;
	temp = ft_dlstlast(*b);
	temp2 = *b;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *b;
	*b = temp;
	temp2->next = NULL;
	if (print == 1)
		write(1, "rrb\n", 4);
}

// It calls fake rra and rrb and do the moves then prints rrr.
void	rrr(t_stack **a, t_stack **b, int print)
{
	fake_rra(a);
	fake_rrb(b);
	if (print == 1)
		write(1, "rrr\n", 4);
}

// Reverse rotate all nodes in a aka minus one. Doesn't print anything.
void	fake_rra(t_stack **a)
{
	t_stack	*temp;
	t_stack *temp2;
	
	if (!*a || !(*a)->next)
		return ;
	temp = ft_dlstlast(*a);
	temp2 = *a;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *a;
	*a = temp;
	temp2->next = NULL;
}

// Reverse rotates all nodes in b aka minus one. Doesn't print anything.
void	fake_rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack *temp2;
	
	if (!*b || !(*b)->next)
		return ;
	temp = ft_dlstlast(*b);
	temp2 = *b;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *b;
	*b = temp;
	temp2->next = NULL;
}
