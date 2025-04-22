#include "push_swap.h"

int duplicate(int *arr, int size)
{
    int i;
    int j;
    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while(j < size)
        {
            if(arr[i] == arr[j])
            return 1;
            j++;
        }
        i++;
    }
    return 0;
}

static int is_out_of_range(long num)
{
    return (num < INT_MIN || num > INT_MAX);
}

static int *convert_to_numbers(char **args, int count)
{
    int *numbers;
    long    num;
    int i;

    numbers = malloc(count *sizeof(int));
    if(!numbers)
        return(NULL);
    
    i = 0;
    while(i < count)
    {
        num = ft_atoi(args[i]);
        if (is_out_of_range(num))
        {
            free(numbers);
            return(NULL);
        }
        numbers[i] = (int)num;
        i++;
    }
    return(numbers);
}

static int count_args(char **args)
{
    int count;

    count = 0;
    while(args[count])
        count++;
    return(count);
}

int *validate_input(int argc, char **argv, int *size)
{
    char **args;
    int *numbers;
    int count;

    if(argc < 2)
        return(NULL);
    args = ft_split(argv[1], ' ');
    if(!args)
        return(NULL);
    count = count_args(args);
    numbers = convert_to_numbers(args, count);
    if(!numbers || duplicate(numbers, count))
    {
        ft_free_split(args);
        free(numbers);
        return(NULL);
    }
    ft_free_split(args);
    *size = count;
    return(numbers); 
}