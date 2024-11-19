/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free_and_other.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:22:09 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/19 23:21:42 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// I will send args from argv[] parsed or not and check if their ok.
// Checks if number, int MIN/MAX.
int	is_arg_valid(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1]) != 0)
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	if (ft_atol(arg) <= INT_MIN || ft_atol(arg) >= INT_MAX)
		return (1);
	return (0);
}

// Converting sent argument to long so I can check if the number is within INT.
long	ft_atol(const char *nptr)
{
	long	res;
	long	sign;
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

// Writes Error and exits.
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (2);
}

// It will free particular stack.
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
