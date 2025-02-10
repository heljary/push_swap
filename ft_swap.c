#include "push_swap.h"

void    sa(push_swap  **stack_a)
{
    push_swap *head;
    push_swap *ptr1;

    if (stacka_size(*stack_a) < 2)
    {
        ft_putstr("non sa");
        return;
    }
    head = *stack_a;
    ptr1 = head -> next;

    head -> next = ptr1 -> next;
    ptr1 -> next = head;
    *stack_a = ptr1;
    ft_putstr("sa\n");
}

void    sb(push_swap  **stack_b)
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
    ft_putstr("sb\n");
}

void    ss(push_swap  **stack_a,push_swap  **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    ft_putstr("ss\n");
}