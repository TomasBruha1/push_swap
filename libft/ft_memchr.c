/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);
/* 
int	main(void)
{
	const char  s[] = "abc";
	
	printf("%p\n", ft_memchr(s, 'c', sizeof(s)));
	return (0);
} */

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		cc;

	src = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (n)
	{
		if (*src == cc)
			return ((void *)src);
		src++;
		n--;
	}
	return (NULL);
}

/* 
DESCRIPTION
	The  memchr() function scans the initial n bytes of the memory
	area pointed to by s for the first instance of c.  Both c and 
	the bytes of the memory area pointed to by s are interpreted 
	as unsigned char.
 
 RETURN VALUE
	The memchr() and memrchr() functions return a pointer to the
	matching byte or  NULL if the character does not occur in the
	given memory area.
 */