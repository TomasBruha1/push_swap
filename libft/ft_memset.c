/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

/* void	*ft_memset(void *str, int c, size_t n);

int	main(void)
{
	unsigned char	str[] = "12345";

	printf("before memset: %s\n", str);
	ft_memset(str+1, 'x', 2);
	printf("after memset: %s\n", str);
	return (0);
} */

void	*ft_memset(void *str, int c, size_t n)
{
	void	*str_ptr;

	str_ptr = str;
	while (n--)
	{
		*(unsigned char *)str++ = (unsigned char)c;
	}
	return (str_ptr);
}
