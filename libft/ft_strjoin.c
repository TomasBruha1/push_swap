/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strjoin(char const *s1, char const *s2);

int	main(void)
{
	char const	s1[] = "123ahoj jak se vede";
	char const	s2[] = "456";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
} */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjnd;
	size_t	s1len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	strjnd = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjnd)
		return (NULL);
	s1len = ft_strlen(s1);
	i = 0;
	while (s1[i])
	{
		strjnd[i] = s1[i];
		i++;
	}
	while (s2[i - s1len])
	{
		strjnd[i] = s2[i - s1len];
		i++;
	}
	strjnd[i] = '\0';
	return (strjnd);
}
