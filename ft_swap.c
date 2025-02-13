#include "push_swap.h"

void    sa(push_swap  **stack_a,char *s)
{
    push_swap *head;
    push_swap *ptr1;

    if (stacka_size(*stack_a) < 2)
    {
        return;
    }
    head = *stack_a;
    ptr1 = head -> next;

    head -> next = ptr1 -> next;
    ptr1 -> next = head;
    *stack_a = ptr1;
    ft_putstr(s);
}

void    sb(push_swap  **stack_b,char *s)
{
    push_swap *head;
    push_swap *ptr1;

    if (stacka_size(*stack_b) < 2)
    {
        return;
    }
    head = *stack_b;
    ptr1 = head -> next;

    head -> next = ptr1 -> next;
    ptr1 -> next = head;
    *stack_b = ptr1;
    ft_putstr(s);
}

void    ss(push_swap  **stack_a,push_swap  **stack_b)
{
    sa(stack_a,NULL);
    sb(stack_b,NULL);
    ft_putstr("ss\n");
}