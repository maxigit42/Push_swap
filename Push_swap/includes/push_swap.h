#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

# include "../Libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// utils
void	ft_error(char *msg);

//cheacks
void    ft_cheack_args(int argc, char **argv);

#endif