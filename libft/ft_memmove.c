/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/* void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	unsigned char	src[] = "12";
	unsigned char	dest[] = "1";

	printf("%s\n", dest);
	printf("%p\n", ft_memmove(dest, src, sizeof(dest)));
	ft_memmove(dest, src, 6);
	printf("%s\n", dest);
	return (0);
} */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (dest_ptr);
}
