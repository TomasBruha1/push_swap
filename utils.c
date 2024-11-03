/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:31:42 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/03 12:32:20 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Converting sent argument to long so I can check if the number is within INT.
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

// I'm checking if the stack is sorted and if not it will go to ft sort.
// I also have check for empty stack a to prevent input such as: " ".
// I might need to move the check for " ". It causes problems.
int	check_if_sorted(t_stack *a)
{
	int		i;
	
	if (!a)
	 	return (0); // These two lines will be deleted after testing.
	if (!a)	
		ft_error(); // This checks for empty " ".
	i = a->number;
	while(a) // PROBLEM IS HERE
	{
		if (i > a->number)
			return (0);
		i = a->number;
		a = a->next;
	}
	return (1);
}
