
#include "push_swap.h"

void	exit_error(t_stack_node **stack_a)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack)
	{
		temp = *stack;
    		*stack = (*stack)->next;
		free(temp);
	}
	
}

