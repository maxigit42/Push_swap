#include "push_swap.h"

static int  ft_rep(int nbr, char **args, int i)
{
    while(args[i])
    {
        if(ft_atoi(args[i]) == nbr)
            return(1);
        i++;
    }
    return(0);
}

static int cheak_digit(char *num)
{
    if(*num == '-')
        num++;
    while(*num)
    {
        if(num >= '0' && num <= '9')
            num++;
        else
            return(0);
        num++;
    }
    return(1);
}

void    ft_cheack_args(int argc, char **argv)
{
    int i;
    char **args;
    long    temp; // si funciona long probar con int

    if(argc == 2)
        args = ftsplit(argv[1], " ");
    else
        argc = argv;
        i = 1;
    while(args[i])
    {
        temp = ft_atoi(args[i]);
        if(!cheak_digit(argv[i]))
            ft_error("Error");
        if(ft_rep(temp, args, i))
            ft_error("Error");
        if(temp > INT_MAX || temp < INT_MIN)
            ft_error("Error");
        i++;
    }
    if(argc == 2)
        free(args);
}