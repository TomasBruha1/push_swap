/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
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

/* void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	unsigned char	src[] = "12345";
	unsigned char	dest[6];

	printf("dest before memcpy %s\n", dest);
	ft_memcpy(dest, src, 6);
	printf("dest after memcpy %s\n", dest);
	return (0);
} */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n--)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (dest_ptr);
}
