#include "../../include/push_swap.h"

void check_data(t_stack_node *stack_a)
{
    t_stack_node *tmp;
    t_stack_node *tmp1;
    int count;

    tmp = stack_a;
    while (tmp)
    {
        count = 0;
        tmp1 = tmp;
        while (tmp1)
        {
            if (tmp1->value == tmp->value)
            {
                count++;
                if (count >= 2)
                    exit_error(&stack_a, NULL);  // Pass NULL for split_args
            }
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
}

void free_split(char **split)
{
    int i = 0;

    if (!split)
        return;

    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void add_to_stack(t_stack_node **stack, int value)
{
    t_stack_node *new_node;

    new_node = new_element(value);
    new_node->next = *stack;
    *stack = new_node;
}

void create_new_element(char *str, t_stack_node **stack_a)
{
    long tmp;
    int i = 0;

    if (!str || !str[0])
        exit_error(stack_a, NULL);

    while (str[i])
    {
        if ((str[i] == '+' || str[i] == '-') && i == 0)
            i++;
        if (!ft_isdigit(str[i]))
            exit_error(stack_a, NULL);
        i++;
    }

    tmp = ft_atol(str);
    if (tmp > INT_MAX || tmp < INT_MIN)
        exit_error(stack_a, NULL);

    add_to_stack(stack_a, tmp);
}



int has_space(const char *argv)
{
    int i = 0;

    while (argv[i])
    {
        if (argv[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}
void handle_input(t_stack_node **stack_a, char **argv, int argc)
{
    int index;
    char **split_args;
    int len_strs;

    index = argc - 1;
    while (index > 0)
    {
        if (has_space(argv[index]))
        {
            split_args = ft_split(argv[index], ' ');
            len_strs = my_strlen(split_args) - 1;
            if (len_strs == -1)
                exit_error(stack_a, split_args);  // Free split_args on error
            while (len_strs >= 0)
            {
                create_new_element(split_args[len_strs], stack_a);
                len_strs--;
            }
            free_split(split_args);  // Free split_args after use
        }
        else
        {
            create_new_element(argv[index], stack_a);
        }
        index--;
    }
    check_data(*stack_a);
    create_index(*stack_a);
}
