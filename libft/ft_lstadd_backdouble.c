/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_backdouble.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:20:39 by tbruha            #+#    #+#             */
/*   Updated: 2024/09/23 18:20:41 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_backdouble(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_lstlastdouble(*lst);
	if (last)
	{
		last->next = new;
		last->previous = *lst;
	}
	else
		*lst = new;
}
