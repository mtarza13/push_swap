#include "../include/push_swap_bonus.h"

int	is_sorted_bonus(t_stack_node **stack_a)
{
	t_stack_node	*head;

	head = *stack_a;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	checking_moves(t_stack_node **stack_a, t_stack_node **stack_b, char *line)
{
	if (ft_strcmp(line, "pb\n"))
		push_b(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n"))
		push_a(stack_a, stack_b);
	else if (ft_strcmp(line, "sa\n"))
		swap_a(stack_a);
	else if (ft_strcmp(line, "sb\n"))
		swap_b(stack_b);
	else if (ft_strcmp(line, "ss\n"))
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(line, "rb\n"))
		rotate_b(stack_b);
	else if (ft_strcmp(line, "ra\n"))
		rotate_a(stack_a);
	else if (ft_strcmp(line, "rr\n"))
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(line, "rrb\n"))
		reverse_rotate_b(stack_b);
	else if (ft_strcmp(line, "rra\n"))
		reverse_rotate_a(stack_a);
	else if (ft_strcmp(line, "rrr\n"))
		reverse_rotate_both(stack_a, stack_b);
	else
		return (1); // Invalid command
	return (0); // Valid command
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0); // No arguments provided
	handle_input(&stack_a, argv, argc); // Parse input and build stack_a
	line = get_next_line(0); // Read first command from stdin
	while (line)
	{
		if (checking_moves(&stack_a, &stack_b, line)) // Check if command is valid
		{
			free(line); // Free the invalid command line
			exit_error(&stack_a, &stack_b); // Exit with error
		}
		free(line); // Free the valid command line
		line = get_next_line(0); // Read next command from stdin
	}
	// Check if stack_a is sorted and stack_b is empty
	if (is_sorted_bonus(&stack_a) && lst_size(stack_b) == 0)
		ft_putstr_fd("OK\n", 1); // Output "OK" if sorted
	else
		ft_putstr_fd("KO\n", 1); // Output "KO" if not sorted
	// Free remaining memory
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
