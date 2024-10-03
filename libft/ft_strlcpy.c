/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
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

/* size_t	ft_strlcpy(char *dest, const char *src, size_t n);

int	main(void)
{
	const char	src[] = "ab272304023cde";
	char		dest[sizeof(src)];

	printf("%s\n", dest);
	ft_strlcpy(dest, src, sizeof(src));
	printf("%s\n", dest);
	return (0);
} */

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (n == 0)
		return (srcsize);
	i = 0;
	if (n != 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}
