/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include "libft.h"

/* void	*ft_bzero(void *str, size_t n);

int	main(void)
{
	unsigned char	str[] = "12345";

	printf("before bzero: %s\n", str);
	printf("%p \n", str);
	ft_bzero(str+1, 4);
	printf("after bzero: %s\n", str);
	printf("%p \n", ft_bzero(str+1, 4));
	return (0);
} */

void	*ft_bzero(void *str, size_t n)
{
	void	*str_ptr;

	str_ptr = str;
	while (n--)
	{
		*(unsigned char *)str++ = '\0';
	}
	return (str_ptr);
}
