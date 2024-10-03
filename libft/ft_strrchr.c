/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	 const char	str[] = "abcabc";

	printf("%p", ft_strrchr(str, 'b'));
	return (0);
} */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*last_c;

	i = 0;
	cc = (char) c;
	last_c = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			last_c = ((char *) &s[i]);
		i++;
	}
	if (cc == '\0')
		last_c = ((char *) &s[i]);
	return (last_c);
}
