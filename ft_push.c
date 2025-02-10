#include "push_swap.h"

void    pb(push_swap **stack_a, push_swap **stack_b)
{
    push_swap   *temp;

    if(*stack_a == NULL)
        return;

    temp = *stack_a;
    *stack_a = (*stack_a)->next;

    insert_first(stack_b, temp->number);
    free(temp);
    ft_putstr("pb\n");
}


void    pa(push_swap **stack_a, push_swap **stack_b)
{
    push_swap *temp;

    if(*stack_b == NULL)
        return;

    temp = *stack_b;
    *stack_b = (*stack_b) -> next;
    insert_first(stack_a,temp -> number );
    
    free(temp);
    ft_putstr("pa\n");
}