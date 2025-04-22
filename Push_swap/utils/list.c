#include "push_swap.h"

t_list    *ft_newlst(int value)
{
    t_list *new;

    new = (t_list*)malloc(sizeof(*new));
    if(!new)
        return;
    new->value = value;
    new->index = -1;
    new->next = NULL;
    return(new);
}

t_list  *find_last(t_list *stack)
{
    t_list *temp;
    
    temp = stack;
    while(temp->next)
    {
        temp = temp->next;
        if(temp->next == NULL)
            return(temp);
    }
    return(temp);
}

void  put_lstback(t_list *new, t_list **stack)
{
    t_list  *last;

    if(*stack)
    {
        last = find_last(*stack);
        last->next = new;
        new->next = NULL;
    }
    else
    {
        *stack = new;
        (*stack)->next = NULL;
    }
}