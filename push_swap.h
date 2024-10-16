/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:40 by tbruha            #+#    #+#             */
/*   Updated: 2024/09/23 15:34:42 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// HEADERS

# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include "libft/libft.h"

// STRUCTS

// FT PROTOTYPES

void	init_stack_a(t_stack **stack_a, char **argv);
int		check_dupes(char **argv);
int		check_digit(char **argv);
void	ft_check_for_errors(int argc, char **argv);
void	ft_error(void);
void	init_parse_stack_a(t_stack **stack_a, char **argv);
t_stack	ft_sort(t_stack stack_a);
void	ft_sa(t_stack **stack_a, int print);
void	ft_sb(t_stack **stack_b, int print);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int print);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int print);

#endif
