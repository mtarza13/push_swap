#include "push_swap.h"

void	choose_sorting(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_size;

	stack_size = lst_size(*stack_a);
	if (stack_size == 2)
		swap_a(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size == 4)
		sort_forth(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_big_algo(stack_a, stack_b);
}
