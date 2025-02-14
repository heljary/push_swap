#include "push_swap.h"

int *sort_array(push_swap **stack_a)
{

    int size = stacka_size(*stack_a);
    int *T = malloc(size * sizeof(int));
    if(!T)
        return NULL;

    int i = 0;
    push_swap *temp = *stack_a;
    while (temp)
    {
        T[i++] = temp -> number;
        temp = temp -> next;
    }
    int len = i;
    i = 0;
    int j; 
    while ( i < len -1)
    {
        j = i + 1;
        while(j < len)
        {
            if (T[i] > T[j])
            {
                int k = T[j];
                T[j] = T[i];
                T[i] = k;
            }
            j++;
        }
        i++;
    }
    return T;
}

void algo_sort_small_numbers(push_swap **stack_a)
{
    int size;
    size = stacka_size(*stack_a);
    if(size == 2)
    {
        sa(stack_a,"sa\n");
        return;
    }
    else if(size == 3)
    {
        if((*stack_a) -> number > (*stack_a) -> next -> number && (*stack_a) -> number > (*stack_a) -> next ->next -> number )
            ra (stack_a,"ra\n");

        if((*stack_a) -> number > (*stack_a) -> next -> number && (*stack_a) -> number < (*stack_a) -> next ->next ->number) 
            sa(stack_a,"sa\n");

        if((*stack_a) -> number < (*stack_a) -> next -> number && (*stack_a) -> number > (*stack_a) -> next ->next ->number) 
            rra(stack_a,"rra\n");

        if((*stack_a) -> number < (*stack_a) -> next -> number && (*stack_a) -> next -> number > (*stack_a) -> next ->next ->number) 
        {
            sa(stack_a,"sa\n");
            ra(stack_a,"ra\n");
        }
    }
}

void algo_sort_small_numbers(push_swap **stack_a,push_swap **stack_b)
{
    push_swap *head;
    int max;

    head  =  *stack_a;
    while (head != NULL)
    {
        head  =  *stack_a;
        if(max > head -> next -> number)
        {
            max = head -> next -> number;
        }

        
    }
    

}

void algo_push_a_in_b(push_swap **stack_a,push_swap **stack_b)
{
    int size;
    int start;
    int end;
     
    if (!stack_a || !(*stack_a))
        return;
    int *T = sort_array(stack_a);
    start = 0;
    end = 0;
    size = stacka_size(*stack_a); 
    if (!T)
        return;
    if(size <= 5)
    {
       algo_sort_small_numbers(stack_a);
       return;
    }
    if(size <= 100)
        end = size/6; 
    else if (size <= 500)
        end = size/12;
        
    while (*stack_a != NULL)
    {
        if ((*stack_a)->number <= T[start])
        {
            pb(stack_a,stack_b);
            rb(stack_b,"rb\n");
            start++;
            end++;
        }
        else if((*stack_a)->number <= T[end])
        {
            pb(stack_a, stack_b);
            if(stacka_size(*stack_b) > 1&& (*stack_b) ->number < (*stack_b) -> next ->number )
            {
                sb(stack_b,"sb\n");
            }
                start++;
                end++;
        }
        else
            ra(stack_a,"ra\n");
    }
    free(T);
}


void    algorithm_sort(push_swap **stack_a,push_swap **stack_b)
{
    push_swap   *head;
    int     max;
    int pos;
    int size;
    int i;

    algo_push_a_in_b(stack_a,stack_b);
    while (*stack_b != NULL)
    {
        i = 0;
        head = *stack_b;
        size = stacka_size(*stack_b);
        pos = size;
        max = head -> number;
        while (head != NULL)
        {
            if (head -> number > max)
            {
                max = head -> number;
                pos -=i;
            }
            head = head -> next;
            i++;
        }
        if(pos >= size/2)
        {
            while ((*stack_b) -> number != max)
                rb(stack_b,"rb\n");
        }else 
            while (stacka_size(*stack_b) && (*stack_b) -> number != max)
                rrb(stack_b,"rrb\n");
        pa(stack_a,stack_b); 
    }
}