/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:31:42 by tbruha            #+#    #+#             */
/*   Updated: 2024/10/29 18:27:09 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long		res;
	long		sign;
	size_t	i;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	res = res * sign;
	if (res <= INT_MIN || res >= INT_MAX)
		ft_error();
	return (res);
}

// Here I check the list for duplicates.
void	check_duplicates(t_stack *lst)
{
	t_stack	*temp;

	while (lst)
	{
		temp = lst->next;
		while (temp)
		{
			if (lst->number == temp->number)
				ft_error();
			temp = temp->next;			
		}
		lst = lst->next;
	}
}

int	check_if_sorted(t_stack *a) // 1 2 3 4
{
	int	i;
	
	i = a->number;
	while(a)
	{
		if (i > a->number)
			return (0);
		i = a->number;
		a = a->next;
	}
	return (1);
}
