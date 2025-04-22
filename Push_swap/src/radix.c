#include "push_swap.h"

void    radix(t_list **stack_a, t_list **stack_b)
{
    if(count_lst(stack_a) <= 5)
        brute_force(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

int     get_bit(t_list **stack)
{
    t_list *head;
    int     max;
    int     max_bits;

    head = *stack;
    max = head->index;
    max_bits = 0;
    while(head)
    {
        if(max < head->index)
            max = head->index;
        head = head->next;
    }
    while((max >> max_bits) != 0)
        max_bits++;
    return(max_bits);
}

void    radix_sort(t_list **stack_a, t_list **stack_b)
{
    t_list *head;
    int     i;
    int     j;
    int     size;
    int     max_bit;

    head = *stack_a;
    i = 0;
    max_bit = get_bit(stack_a);
    size = list_size(head);
    while(i++ < max_bit)
    {
        j = 0;
        while(j++ < size)
        {
            head = *stack_a;
            if(((head->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while(list_size(*stack_b) != 0)
            pa(stack_a, stack_b);
    }
}