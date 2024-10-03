/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:11:31 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/20 13:11:35 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
static int	count_str(char const *s, char c);
static char	*alloc_substr_cpy(const char *s, char c);

/* int	main(void)
{
	char const	str[] = "caacbbc";
	
	ft_split(str, 'c');
	//printf("%s", ft_split(str, 'c'));
	return (0);
} */

char	**ft_split(char const *s, char c)
{
	size_t		len;
	size_t		i;
	char		**result;

	len = count_str(s, c);
	result = ft_calloc(len + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (s[0] == c)
			s++;
		result[i] = alloc_substr_cpy(s, c);
		if (!result[i])
		{
			free(result);
			return (NULL);
		}
		s = s + ft_strlen(result[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}

static int	count_str(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*alloc_substr_cpy(const char *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = malloc(i + 1);
	if (!res)
	{
		free(res);
		return (NULL);
	}
	ft_strlcpy(res, s, i + 1);
	return (res);
}
