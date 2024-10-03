/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/* size_t	ft_strlcat(char *dest, const char *src, size_t size);

int	main(void)
{
	char		dest[] = "abc";
	const char	src[] = "def";
	
	ft_strlcat(dest, src, 0);
	printf("%s", (dest));
	return (0);
} */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	if ((src == NULL && size == 0) || (dest == NULL && size == 0))
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && i < size -1 - dest_len)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}
