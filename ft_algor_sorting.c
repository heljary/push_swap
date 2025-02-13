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
            rb(stack_b);
            // printf("\nstart in if 1 ===>%d\n",start);
            start++;
            // printf("\nend in if   1 ===>%d\n",end);
            end++;
        }
        else if((*stack_a)->number <= T[end])
        {
            pb(stack_a, stack_b);
            if((*stack_a) ->number < (*stack_a) -> next ->number )
            {
                sb(stack_b);
            }
                // printf("\nstart in if 2 ===>%d\n",start);
                start++;
                // printf("\nend in if   2 ===>%d\n",end);
                end++;
        }
        else
            ra(stack_a);
    }
    free(T);
}


void algorithm_sort(push_swap **stack_a,push_swap **stack_b)
{
    push_swap   *head;
    int     max;
    algo_push_a_in_b(stack_a,stack_b);
    while (*stack_b != NULL)
    {
        head = *stack_b;
        max = head -> number;
        while (head != NULL)
        {
            if (max < head -> number)
            {
                max = head -> number;
            }
            head = head -> next;
        }

        while (*stack_b != NULL)
        {
            if((*stack_b) -> number == max)
            {
                pa(stack_a,stack_b);
                break;
            }
            if((*stack_b) -> number != max)
            {
                rb(stack_b);
            }
        }
    }
}