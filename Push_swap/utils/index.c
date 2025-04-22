#include "push_swap.h"

static t_list   *get_min(t_list **stack)
{
    t_list  *min;
    t_list  *head;

    head = *stack;
    min = NULL;
    while(head)
    {
        if(head->index == -1)
        {
            if(!min || head->value < min->value)
            min = head;
        }
        head = head->next;
    }
    return(min);
}

void    ft_index(t_list **stack)
{
    t_list *head;
    int     index;

    index = 0;
    head = get_min(stack);
    while(head)
    {
        head->index = index++;
        head = get_min(stack);
    }
}