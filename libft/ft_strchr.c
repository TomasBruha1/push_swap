/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
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

/* char	*ft_strchr(const char *s, int c);

int	main(void)
{
	const char	str[] = "abcd";
	
	ft_strchr(str, 'c');
	return (0);
} */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
