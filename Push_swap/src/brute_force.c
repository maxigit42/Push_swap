#include "push_swap.h"

void    brute_force(t_list **stack_a, t_list **stack_b)
{
    int args;

    args = list_size(*stack_a);
    if(args == 2)
        two_args(stack_a);
    else if(args == 3)
        three_args(stack_a);
    else if(args == 4)
        four_args(stack_a, stack_b);
    else
        five_args(stack_a, stack_b);
}

void    two_args(t_list **stack_a)
{
    sa(stack_a);
}

void    three_args(t_list **stack_a)
{
    t_list *head;
    int     min;
    int     second_min;
    
    head = *stack_a;
    min = get_min_arg(stack_a);
    second_min = min + 1;
    if(head->index == min)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (head->index < head->next->index)
        rra(stack_a);
    else if(head->index == second_min && head->index > head->next->index)
        sa(stack_a);
    else if(head->index > head->next->index && head->next->index == min)
        ra(stack_a);
    else if(head->index > head->next->index && head->next->index == second_min)
    {
        rra(stack_a);
        rra(stack_a);
    }
}

void    four_args(t_list **stack_a, t_list **stack_b)
{
    int     distance;

    distance = get_distance(stack_a);
    if(distance == 1)
        sa(stack_a);
    else if(distance == 2)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if(distance == 3)
        rra(stack_a);
    pb(stack_a, stack_b);
    three_args(stack_a);
    pa(stack_a, stack_b);
}

void    five_args(t_list **stack_a, t_list **stack_b)
{
    int     distance;

    distance = get_distance(stack_a);
    if(distance == 1)
        ra(stack_a);
    else if(distance == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if(distance == 3)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if(distance == 4)
        rra(stack_a);
    pb(stack_a, stack_b);
    four_args(stack_a, stack_b);
    pa(stack_a, stack_b);
}