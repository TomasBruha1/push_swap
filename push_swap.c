#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b; // Maybe needed later. Let's leave it here for now.
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2 || argv[1][0] == '\0')
		ft_error();
	printf("start\n");
	if (argc == 2)
		init_parse_stack(&a, argv);
	if (argc > 2)
		init_stack(&a, argv);
	printf("after init\n");
	while (a != NULL)
	{
		printf("node %d: %d\n", i, a->number);
		a = a->next;
		i++;
	}
	printf("end\n");
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
	char	*arg;

	printf("init parse stack\n");
	temp = ft_split(*argv, ' ');
	i = 1;
	while (temp[i])
	{
		arg = malloc(sizeof(int));
		if (!arg)
		{
			free(arg);
			ft_error();
		}
		if (is_arg_valid(arg))
			ft_error();
		*arg = ft_atoi(temp[i]);
		ft_dlstadd_back(a, ft_dlstnew(arg));
		i++;
	}
	free(temp);
}

// Here I initialize stack a with arguments from argv. They are checked
// by is_arg_valid before that.
void	init_stack(t_stack **a, char **argv)
{	
	int		i;
	char	*arg; // I need to change it back to int so I can have 256+.

	printf("init multiple arguments stack\n");
	i = 1;
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	while (argv[i] != NULL)
	{
		arg = malloc(sizeof(int));
		if (!arg)
		{
			free(arg);
			ft_error();
		}
		*arg = *argv[i];
		printf("pred arg checkem: %s\n", arg);
		if (is_arg_valid(arg))
			ft_error();
		*arg = atoi(argv[i]);
		ft_dlstadd_back(a, ft_dlstnew(arg));
		i++;
	}
}

// I will send args from argv[] parsed or not and check if their ok.
// Checks if number, dupes, int MIN/MAX.
int	is_arg_valid(char *arg)
{
	int i;
	
	printf("inside is_arg_valid\n");
	printf("pasnuto do argu arg: %i\n", *arg);
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		printf("value of arg: %i\n", *arg);
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	i = 0;
//	if ()
	printf("VALID and leaving\n\n");
	return (0);
}

// void	check_duplicates(t_stack **a);



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