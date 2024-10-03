/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set);
static int	char_check(char const c, char const *set);

/* int	main(void)
{
	char const	str[] = "abbacbacbacHello there Obi-Wan Kenobiabc";
	char const	set[] = "cba";

	printf("%s", ft_strtrim(str, set));
	return (0);
} */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimd;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (char_check(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_check(s1[end - 1], set))
		end--;
	if (end <= start)
		return (ft_calloc(1, sizeof(char)));
	trimd = malloc(end - start + 1);
	if (!trimd)
		return (NULL);
	ft_memcpy(trimd, s1 + start, end - start);
	trimd[end - start] = '\0';
	return (trimd);
}

static int	char_check(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}
