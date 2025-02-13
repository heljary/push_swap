#include "push_swap.h"

void    ra(push_swap  **stack_a,char *s)
{
    push_swap *nxt;
    push_swap *first;

    if(*stack_a == NULL)
        return;

    if (stacka_size(*stack_a) == 1)
        return;

    nxt = *stack_a;
    while (nxt -> next != NULL)
        nxt = nxt -> next;
    
    first = (*stack_a);
    (*stack_a) = (*stack_a) -> next;
    nxt -> next = first;
    first -> next = NULL;
    ft_putstr(s);
}
void    rb(push_swap  **stack_b,char *s)
{
    push_swap *head;
    push_swap *first;

    if(*stack_b == NULL)
        return;

    if (stacka_size(*stack_b) == 1)
        return;
    
    head = (*stack_b);
    while (head -> next != NULL)
        head = head -> next;

    first = (*stack_b);
    *stack_b = (*stack_b) -> next;
    head -> next =first;
    first -> next = NULL;
    ft_putstr(s);
}
void    rr(push_swap  **stack_a,push_swap  **stack_b)
{
    ra(stack_a,NULL);
    rb(stack_b,NULL);
    ft_putstr("rr\n");

}