#include "push_swap.h"

void	rotate_bonus(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*tail;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		tail = *stack;
		while (tail->next)
			tail = tail->next;
		tail->next = temp;
	}
}

void	rotate_a_bonus(t_stack_node **stack_a)
{
	rotate_bonus(stack_a);

}

void	rotate_b_bonus(t_stack_node **stack_b)
{
	rotate_bonus(stack_b);

}

void	rotate_both_bonus(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_bonus(stack_a);
	rotate_bonus(stack_b);

}
