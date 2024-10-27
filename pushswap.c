#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		ft_error();
	if (argc == 2)
		init_parse_stack(&a, *argv);
	if (argc > 2)
		init_stack(a, argv);
	is_sorted(a);
	return (0);	
}

// It returns array with numbers(or other stuff) -> I will check args after.
// argv[i] will be the same as array with args.
void	init_parse_stack(t_stack **a, char **argv)
{
	char	**temp;
	int		i;
	int		*arg;

	temp = ft_split(temp, ' ');
	i = 0;
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
		*arg = atoi(temp[i])
		
	}


	return(*temp);
}

// I will send args from argv[] parsed or not and check if their ok.
// Checks if number, dupes, int MIN/MAX.
int	is_arg_valid(char *arg)
{

}

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