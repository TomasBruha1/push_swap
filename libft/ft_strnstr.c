/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int	main(void)
{
	const char	haystack[] = "haystack";
	const char	needle[] = "stack";
	
	ft_strnstr(haystack, needle, sizeof(haystack));
	printf("%s", ft_strnstr(haystack, needle, sizeof(haystack)));
	return (0);
} */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && haystack[i + j] && i + j < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}

/* 
DESCRIPTION
     The strnstr() function locates the first occurrence of the 
	 null-terminated string little in the string big, where not 
	 more than len characters are searched.  Characters that appear 
	 after a ‘\0’ character are not searched.  Since the strnstr() 
	 function is a FreeBSD specific API, it should only be used when 
	 portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs 
	 nowhere in big, NULL is returned; otherwise a pointer to the first 
	 character of the first occurrence of little is returned.
 */