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

// Here I check for argument, initialized t_stack and send arguments for checks.
// After that I add numbers to stack_a.
int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		ft_error();
	stack_a = NULL;
	ft_check_for_errors(argc, argv);
	if (argc == 2)
		init_parse_stack_a(&stack_a, argv);
	else
		init_stack_a(&stack_a, argv);
	while (stack_a)
	{
		printf("%s\n", (char *)stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}

// In this function I'm taking arguments passed and checking for dupes and non didigts.
// BUG: I need to fix quoted multiple numbers >> split.
void	ft_check_for_errors(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc == 2)
	{
		int	i;

		i = 0;
		while (argv[1][i] != '\0')
		{
			if ((argv[1][i] == 32) || (ft_isdigit(argv[1][i])))
				i++;
			else
				ft_error();
		}
	}
	else if (check_digit(argv))
		ft_error();
	else if (check_dupes(argv))
		ft_error();
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
				return (1);
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
				return (1);
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

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

void	init_parse_stack_a(t_stack **stack_a, char **argv)
{
	char	**temp;
	int		i;

	temp = ft_split(*argv, 32);
	i = 0;
	while (temp)
	{
		temp[i] = atoi(temp[i]);
		ft_lstadd_backdouble(stack_a, ft_lstnew_double(atoi(&temp[1][i])));
		i++;
	}
	argv[1] = NULL;
}
