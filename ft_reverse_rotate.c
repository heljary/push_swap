#include "push_swap.h"

void    rra(push_swap  **stack_a,char *s)
{
    push_swap *nxt;
    push_swap *last;

    nxt = *stack_a;
    if(*stack_a == NULL)
        return;

    if (stacka_size(*stack_a) == 1)
        return;
    
    while (nxt -> next -> next != NULL)
        nxt = nxt -> next;

    last = nxt -> next;
    nxt -> next = NULL;
    last -> next = (*stack_a);
    (*stack_a) = last;
    ft_putstr(s);
}

void    rrb(push_swap  **stack_b,char *s)
{
    push_swap *nxt;
    push_swap *last;

    nxt = *stack_b;
    if(*stack_b == NULL)
        return;

    if (stacka_size(*stack_b) == 1)
        return;
    
    while (nxt -> next -> next != NULL)
        nxt = nxt -> next;

    last = nxt -> next;
    nxt -> next = NULL;
    last -> next = (*stack_b);
    (*stack_b) = last;
    ft_putstr(s);
}

void    rrr(push_swap  **stack_a,push_swap  **stack_b)
{
    rra(stack_a,NULL);
    rrb(stack_b,NULL);
    ft_putstr("rrr\n");
}