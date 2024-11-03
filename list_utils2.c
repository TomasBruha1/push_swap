/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:39:33 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/03 20:13:13 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min_value(t_stack *a)
{
	t_stack	*min;

	min = a;
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->index < min->index)
			min = a;
		a = a->next;
	}
	return (min);
}

t_stack	*find_max_value(t_stack *a)
{
	t_stack	*max;

	max = a;
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->index > max->index)
			max = a;
		a = a->next;
	}
	return (max);
}
