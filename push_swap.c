/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:08:10 by tbruha            #+#    #+#             */
/*   Updated: 2024/11/19 23:04:43 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// STATUS UPDATE, NOW: free array with errors in parsing

// I check number of arguments, if there is at least one we move on to init.
// During init there are checks for valid arguments. Once we have stack a
// I check for duplicates and then if it is sorted. If not let's sort.
// Lastly I free stack a.
int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	if (argc < 2 || argv[1][0] == '\0')
		ft_error();
	if (argc == 2)
		init_parse_stack(&a, argv, 0);
	if (argc > 2)
		init_stack(&a, argv);
	check_duplicates(a);
	if (!check_if_sorted(a))
		what2sort(&a);
	free_stack(&a);
	return (0);
}

// It returns array with numbers(or other stuff) -> I will check args after.
// argv[i] will be the same as array with args.
void	init_parse_stack(t_stack **a, char **argv, int i)
{
	char	**temp;
	int		*arg;

	temp = ft_split(argv[1], ' ');
	while (temp[i])
	{
		if (is_arg_valid(temp[i]))
		{
			free_stack(a);
			free_array(temp);
			ft_error();
		}
		arg = malloc(sizeof(int));
		if (!arg)
		{
			free(arg);
			free_array(temp);
			ft_error();
		}
		*arg = ft_atoi(temp[i]);
		ft_dlstadd_back(a, ft_dlstnew(arg));
		free(arg);
		i++;
	}
	free_array(temp);
}

// Here I initialize stack a with arguments from argv. They are checked
// by is_arg_valid before that.
void	init_stack(t_stack **a, char **argv)
{
	int		i;
	int		*arg;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_arg_valid(argv[i]))
		{
			free_stack(a);
			ft_error();
		}
		arg = malloc(sizeof(int));
		if (!arg)
		{
			free(arg);
			ft_error();
		}
		*arg = ft_atoi(argv[i]);
		ft_dlstadd_back(a, ft_dlstnew(arg));
		free(arg);
		i++;
	}
}

// I'm checking if the stack is sorted and if not it will go to ft sort.
// I also have check for empty stack a to prevent input such as: " ".
int	check_if_sorted(t_stack *a)
{
	int		i;

	if (!a)
		ft_error();
	i = a->number;
	while (a)
	{
		if (i > a->number)
			return (0);
		i = a->number;
		a = a->next;
	}
	return (1);
}

// Here I check the list for duplicates.
void	check_duplicates(t_stack *lst)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp2 = lst;
	while (temp2)
	{
		temp = temp2->next;
		while (temp)
		{
			if (temp2->number == temp->number)
			{
				free_stack(&lst);
				ft_error();
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
	}
}
