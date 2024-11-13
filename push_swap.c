#include "push_swap.h"

// STATUS UPDATE:
// RIGHT NOW I NEED: how to do the right operations to push cheapest to b.
// Do I need "get_cheapest_node"? Yes I will do it.
// DO RESET FOR ALL IN ONE??
// check what needs reset and what can be overwritten. reset values and repeat until 3 elem left in a.
// Find where to push from b to a.

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

void	print_stack_stuff(t_stack *a, t_stack *b)
{
	int	i;
	
	i = 1;
	printf("STACK A\n");
	while (a != NULL)
	{		
		if (a->target_node != NULL)
		{
			printf("Node %d   nbr: %d   val_index: %d   index: %d   median: %d   tar: %d   price: %d\n"
			, i, a->number, a->value_index, a->index, a->above_median, a->target_node->number, a->push_price);
		}
		else
		{
			printf("Node %d   nbr: %d   val_index: %d   index: %d   median: %d   price: %d\n"
			, i, a->number, a->value_index, a->index, a->above_median, a->push_price);
		}
		a = a->next;
		i++;
	}
	write(1, "\n", 1);
	printf("STACK B\n");
	i = 1;
	while (b != NULL)
	{		
		if (b->target_node != NULL)
		{
			printf("Node %d   nbr: %d   val_index: %d   index: %d   median: %d   tar: %d   price: %d\n"
			, i, b->number, b->value_index, b->index, b->above_median, b->target_node->number, b->push_price);
		}
		else
		{
			printf("Node %d   nbr: %d   val_index: %d   index: %d   median: %d   price: %d\n"
			, i, b->number, b->value_index, b->index, b->above_median, b->push_price);
		}
		b = b->next;
		i++;
	}
	write(1, "\n", 1);
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
// check for 2 and sort // DONE
// check for 3 and sort // DONE
// helper functions 1/2 -> stack len, last node // DONE
// helper functions 2/2 -> min and max node // DONE
// rules for target node a to b then b to a. // DONE
// With all errors I have to free stack if error occurs.
// error must be on stderror aka 2 in write. // DONE
// Fix aka add second index function to make it work. // DONE
// Function how to calculate push_price. // DONE
// ft if above median > count / 2 right? // DONE
// ft if cheapest // DONE
// POSSIBLE PROBLEM: target nodes, check the option with find_min as written in the function // DONE
// Don't forget that input can start as low as minut MIN_INT. // DONE

// NOW
// implement Turk and sort

// input problem with "-" // What about minus zero??	
// Optimatization. Check the +1 on above_median
// Optimatization. push_price count all possible ways and choose the lowest.
// On error don't forget to free stacks to avoid leaks.
// make a list of functions that use memmory allock.
// what if I make split on all the arguments starting with 1.
// check functions to include prev or do I really need prev at all?
