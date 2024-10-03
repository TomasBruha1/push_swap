/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:12:44 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/22 14:12:46 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n);
static int		int_len(long n);
static char		*before_alloc(int n);

/* int	main(void)
{
	int	i;

	i = -123;
	printf("%s", ft_itoa(i));
	//ft_itoa(i);
	return (0);
} */	

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	int		len;
	int		i;

	nbr = n;
	len = int_len(nbr);
	res = before_alloc(len);
	if (!res)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		res[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}

static int	int_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*before_alloc(int n)
{
	char	*temp;

	temp = malloc((n + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[0] = '0';
	return (temp);
}
