/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:59:15 by tbruha            #+#    #+#             */
/*   Updated: 2024/06/23 18:59:16 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_putchar_fd(char c, int fd);

int	main(void)
{
	ft_putchar_fd('a', 1);
	return (0);
} */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
