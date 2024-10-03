/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:15:24 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/20 12:15:31 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
/* 
int	main(void)
{
	const char	nptr[] = " 	  +23543ab44545d";
	
	printf("%d", ft_atoi(nptr));
	return (0);
}
 */

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		res;
	int		sign;
	size_t	i;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
