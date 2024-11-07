#include "push_swap.h"

// STATUS UPDATE: 
// Check new functions: find_min, find_max & assign_index.
// Do sort 3 and more than 3.

// I check number of arguments, if there is at least one we move on to init.
// During init there are checks for valid arguments. Once we have stack a
// I check for duplicates and then if it is sorted. If not let's sort.
// Lastly I free stack a and b if needed.
int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	if (argc < 2 || argv[1][0] == '\0')
		ft_error();
	printf("start\n");
	if (argc == 2)
		init_parse_stack(&a, argv);
	if (argc > 2)
		init_stack(&a, argv);
	check_duplicates(a);
	if (check_if_sorted(a)) // right now just printing SORTED/NOT SORTED.
		printf("a is SORTED\n");
	else
	{
		printf("inicialy \"a\" was NOT SORTED\n\n");
		what2sort(&a);
		write(1, "\n", 1);
	}
	if (check_if_sorted(a)) // right now just printing SORTED/NOT SORTED.
		printf("a is SORTED now\n\n");
	while (a != NULL)
	{
		printf("Node %d value: %d     with index: %d\n", i, a->number, a->index);
		a = a->next;
		i++;
	}
	write(1, "\n", 1);
	printf("end\n");
	// free stack a
	return (0);	
}

// It returns array with numbers(or other stuff) -> I will check args after.
// argv[i] will be the same as array with args.
void	init_parse_stack(t_stack **a, char **argv)
{
	char	**temp;
	int		i;
	int		*arg;

	printf("init parse stack\n");
	temp = ft_split(argv[1], ' ');
	i = 0;
	while (temp[i])
	{
		if (is_arg_valid(temp[i]))
			ft_error();
		arg = malloc(sizeof(int));
		if (!arg)
		{
			free(arg);
			ft_error();
		}
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
	int		*arg;

	printf("init multiple arguments stack\n");
	i = 1;
	while (argv[i] != NULL)
	{
		if (is_arg_valid(argv[i]))
			ft_error();
		arg = malloc(sizeof(int));
		if (!arg)
		{
			free(arg);
			ft_error();
		}
		*arg = ft_atoi(argv[i]);
		ft_dlstadd_back(a, ft_dlstnew(arg));
		i++;
	}
}

// I will send args from argv[] parsed or not and check if their ok.
// Checks if number, int MIN/MAX.
int	is_arg_valid(char *arg)
{
	int i;

	i = 0;
	// Fix the solo "minus" sign issue here.
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	if (ft_atol(arg) <= INT_MIN || ft_atol(arg) >= INT_MAX)
		return (1);
	return (0);
}

// String valid ft?? Check for errors ft?? // DONE
// Declare structs a and b // DONE
// Argument count check and empty second argument check // DONE
// if string use split. How to differ one # and string >> I dont have to. // DONE
// Check overflow // DONE
// Check duplicates // DONE
// Check syntax errors such as "123", Only + - is allowed. // DONE
// Initialize and check OR check one by one and then pass??? // DONE
// operations 11x // DONE
// Check if sorted // DONE

// NOW
// check for 2 and sort

// check for 3 and sort
// check above 3, implement Turk and sort
// helper functions 1/2 -> stack len, last node
// helper functions 2/2 -> min and max node
// With all errors I have to free stack if error occurs.
// input problem with "-" // What about minus zero??	
