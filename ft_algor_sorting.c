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

void algo_push_a_in_b(push_swap **stack_a,push_swap **stack_b)
{
    int *T;
    int size;
    int start;
    int end;
     
    if (!stack_a || !(*stack_a))
        return;
    T = sort_array(stack_a);
    start = 0;
    size = stacka_size(*stack_a); 
    if (!T)
        return;
    if(size <= 100)
        end = size/6; 
    else if (size <= 500)
        end = size/12;
    while (*stack_a != NULL)
    {
        if((*stack_a) -> number <= T[start])
        {
            pb(stack_a,stack_b);
            rb(stack_b,"rb\n");
            // printf("\nstart in if 1 ===>%d\n",start);
            start++;
            // printf("\nend in if   1 ===>%d\n",end);
            end++;
        }
        else if((*stack_a)->number <= T[end])
        {
            pb(stack_a, stack_b);
            if(stacka_size(*stack_b) > 1&& (*stack_b) ->number < (*stack_b) -> next ->number )
            {
                sb(stack_b,"sb\n");
            }
                // printf("\nstart in if 2 ===>%d\n",start);
                start++;
                // printf("\nend in if   2 ===>%d\n",end);
                end++;
        }
        else
            ra(stack_a,"ra\n");
    }
    free(T);
}


void algorithm_sort(push_swap **stack_a,push_swap **stack_b)
{
    push_swap   *head;
    int     max;
    int pos;
    int i;

    i = 0;
    algo_push_a_in_b(stack_a,stack_b);
    while (*stack_b != NULL)
    {
        head = *stack_b;
        max = head -> number;
        while (head != NULL)
        {
            if (head -> number > max)
            {
                max = head -> number;
                pos = i;
            }
            head = head -> next;
            i++;
        }

        if(pos <= i/2)
        {
            while ((*stack_b) -> number != max)
                rb(stack_b,"rb\n");
            
        }else 
            while (stacka_size(*stack_b) && (*stack_b) -> number != max)
                rrb(stack_b,"rrb\n");

        pa(stack_a,stack_b);
        
    }
}