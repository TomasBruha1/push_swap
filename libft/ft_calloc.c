/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:05:28 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/19 20:05:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_calloc(size_t nmemb, size_t size);

int	main(void)
{
	ft_calloc(0, 0);
	return (0);
} */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cptr;
	size_t	totalsize;

	totalsize = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		cptr = malloc(0);
		return (cptr);
	}
	if (totalsize / nmemb != size)
		return (NULL);
	cptr = malloc(totalsize);
	if (!cptr)
		return (NULL);
	ft_bzero(cptr, totalsize);
	return (cptr);
}
