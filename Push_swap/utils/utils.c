#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

int		is_sort(t_list **stack)
{
	t_list *head;
	
	head = *stack;
	while(head && head->next)
	{
		if(head->value > head->next->value)
			return(0);
		head = head->next;
	}
	return(1);
}

void	free_stack(t_list **stack)
{
	t_list *head;
	t_list *temp;
	
	head = *stack;
	while(head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

int 	list_size(t_list *stack)
{
	int 	i;
	t_list *temp;

	temp = stack;
	i = 0;
	while(temp == NULL)
	{
		temp = temp->next;
		i++;
	}
	return(i);
}

int		get_min_arg(t_list **stack)
{
	t_list *head;
	int		min;

	head = *stack;
	min = head->index;
	while(head)
	{
		if(head->index < min)
			min = head->index;
		head = head->next;
	}
	return(min);
}

int 	get_distance(t_list **stack)
{
	t_list *head;
	int 	distance;
	int 	min;

	head = *stack;
	distance = 0;
	min = get_min_arg(stack);
	while(head->index != min)
	{
		head = head->next;
		distance++;
	}
	return(distance);
}