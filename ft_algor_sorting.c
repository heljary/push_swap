#include "push_swap.h"

int *sort_array(push_swap **stack_a)
{
    int *T = malloc(stacka_size(*stack_a));
    int i = 0;
    push_swap *Table = *stack_a;
    while (Table!= NULL)
    {
        T[i] = Table -> number;
        Table = Table -> next;
        i++;
    }
    int len = i;
    i = 0;
    int j; 
    while ( i < len)
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

void algo_sort(push_swap **stack_a)
{
    int *T = sort_array(stack_a);
    int i = 0;

    



    int j = 0;
    while(j < 5)
    {
        printf("%d\n",T[j]);
        j++;
    }
}