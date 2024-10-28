#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b; // Maybe needed later. Let's leave it here for now.

	a = NULL;
	b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		ft_error();
	if (argc == 2)
		init_parse_stack(&a, argv);
	// if (argc > 2)
	// 	init_stack(&a, argv);
	// check_duplicates(a);
	// is_sorted(a);
	return (0);	
}

// It returns array with numbers(or other stuff) -> I will check args after.
// argv[i] will be the same as array with args.
void	init_parse_stack(t_stack **a, char **argv)
{
	char	**temp;
	int		i;
	int		*arg;

	temp = ft_split(*argv, ' ');
	i = 0;
	while (temp[i]) // different for other init
	{
		arg = malloc(sizeof(int));
		if (!arg)
		{
			free(arg);
			ft_error();
		}
		if (is_arg_valid(arg))
			ft_error();
		*arg = ft_atoi(temp[i]); // different for other init
		ft_dlstadd_back(a, ft_dlstnew(arg));
		i++;
	}
	free(temp); // different for other init
}

// I will send args from argv[] parsed or not and check if their ok.
// Checks if number, dupes, int MIN/MAX.
int	is_arg_valid(int *arg)
{
	int i;
	
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i++]))
		return (1);
	i = 0;
//	if ()


	return (0);
}

// void	check_duplicates(t_stack **a);

// void	init_stack_a(t_stack **stack_a, char **argv)
// {	
// 	int	i;
// 	int	*num_ptr;

// 	i = 1;
// 	while (argv[i] != NULL)
// 	{
// 		num_ptr = malloc(sizeof(int));
// 		if (!num_ptr)
// 		{
// 			free(num_ptr);
// 			ft_error();
// 		}
// 		*num_ptr = atoi(argv[i]);
// 		ft_lstadd_backdouble(stack_a, ft_lstnew_double(num_ptr));
// 		i++;
// 	}
// }


// int	check_if_sorted(t_stack *stack_a)
// {
// 	int	*i;
	
// 	i = stack_a->number;
// 	while(stack_a)
// 	{
// 		if (i > stack_a->number)
// 			return (0);
// 		i = stack_a->number;
// 		stack_a = stack_a->next;
// 	}
// 	return (1);
// }



// String valid ft?? Check for errors ft??

// Declare structs a and b // DONE
// Argument count check and empty second argument check // DONE

// if string use split. How to differ one # and string >> I dont have to. //

// With all errors I have to free stack if error occurs.

// Check overflow

// Check duplicates

// Check syntax errors such as "123", Only + - is allowed.

// Check if sorted -> check for 2 -> check for 3 -> above 3, implement Turk.

// Initialize and check OR check one by one and then pass???

// ft to handle errors and freeing, operations (11x), stack len, last node, min and max

// 