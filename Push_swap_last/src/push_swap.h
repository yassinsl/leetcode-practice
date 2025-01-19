#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../Libft/libft.h"
typedef struct s_prev
{
    int major;
    int minor;
    int first;
    int last;
    int midd;
    int max;
    int min;
} t_prev;
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
#endif
