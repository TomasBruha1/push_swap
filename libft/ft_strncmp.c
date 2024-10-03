/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/* int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	unsigned char	s1[] = "ab";
	unsigned char	s2[] = "abc";
	
	printf("%d", ft_strncmp((const char *)s1, (const char *)s2, 3));
	return (0);
} */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0')
	{
		if (i < n)
			while ((unsigned char)s1[i] != (unsigned char)s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
