#include "push_swap.h"

void	push_bonus(t_stack_node **from_stack, t_stack_node **to_stack)
{
	t_stack_node	*temp;

	if (*from_stack)
	{
		temp = *from_stack;
		*from_stack = (*from_stack)->next;
		temp->next = *to_stack;
		*to_stack = temp;
	}
}

void	push_a_bonus(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_bonus(stack_b, stack_a);

}

void	push_b_bonus(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_bonus(stack_a, stack_b);

}
