#include "push_swap.h"

void sa(t_stack *stack)
{
    t_stack *first;
    t_stack *second;

    if(!stack || !stack->next)
        return;

    first = stack;
    second = stack->next;

    first->next = second->next;
    second->next = first;
    stack = second;
}

void sb(t_stack *stack)
{
    t_stack *first;
    t_stack *second;

    if(!stack || !stack->next)
        return;

    first = stack;
    second = stack->next;

    first->next = second->next;
    second->next = first;
    stack = second;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_b;

    if(!*stack_b)
        return;
    
    first_b = *stack_b;
    *stack_b = first_b->next;
    first_b->next = *stack_a;
    *stack_a = first_b;
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_a;

    if(!stack_a)
        return;

    first_a = *stack_a;
    *stack_a = first_a->next;
    first_a->next = *stack_b;
    *stack_b = first_a;
}

void ra(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if(!stack || !(*stack)->next)
        return;
    
    first = *stack;
    *stack = first->next;
    
    last = *stack;
    while(last->next)
        last = last->next;

    last->next = first;
    first->next = NULL;
}

void rb(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if(!stack || !(*stack)->next)
        return;
    
    first = *stack;
    *stack = first->next;
    
    last = *stack;
    while(last->next)
        last = last->next;

    last->next = first;
    first->next = NULL;
}

void rra(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if(!*stack || !(*stack)->next)
        return;

    second_last = NULL;    
    last = *stack;
    while(last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rrb(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if(!*stack || !(*stack)->next)
        return;

    second_last = NULL;    
    last = *stack;
    while(last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}