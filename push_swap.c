/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:32 by tbruha            #+#    #+#             */
/*   Updated: 2024/09/23 15:34:36 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 3)
	{
		printf("error");
		return (0);
	}
	stack_a = NULL;
	check_digit(argv);
	check_dupes(argv);
	init_stack_a(&stack_a, argv);
	while (stack_a)
	{
		printf("%s\n", (char *)stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-' && argv[i][j+1] != '\0')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("ERROR - there are NON-INTs\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dupes(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while ((argv[j]) != NULL)
		{
			if (ft_strncmp(argv[i], argv[j], 10) == 0)
			{
				printf("ERROR - there are duplicates.\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_stack_a(t_stack **stack_a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_backdouble(stack_a, ft_lstnew_double(argv[i]));
		i++;
	}
	argv[i] = NULL;
}
