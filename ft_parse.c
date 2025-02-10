#include "push_swap.h"

void ft_print(push_swap *StackA)
{


    while (StackA != NULL)
    {
        ft_putnbr(StackA -> number);
        ft_putchar('\n');
        StackA = StackA -> next;
    }
}


int is_sorted(push_swap *head)
{
    int num;
    if(head == NULL)
    {
        return 1;
    }
    num = head -> number;
    head = head -> next;
    while (head != NULL)
    {
        if(num > head -> number)
        {
            printf("NON !\n");
            return 0;
        }
        num = head -> number;
        head = head -> next;
    }
    printf("YES 3\n");
    return 1;
}

int main(int ac, char **av)
{
    push_swap *StackA = NULL;
    // push_swap *Stackb = NULL;
    int i = 1;
    int j;
    int num;
    char **args;

    if (ac >= 2)
    {
        while (i < ac)
        {
            args = ft_split(av[i], ' ');
            j = 0;

            while (args[j])
            {
                num = ft_atoi(args[j]);

                if (!is_validnumber(args[j]))
                    function_exit();

                else if (is_dupliacte(StackA, num))
                    function_exit();

                else if (num > INT_MAX || num < INT_MIN)
                    function_exit();

                insert_last(&StackA, num);
                j++;
            }
            i++;
        }
        ft_free_split(args);
    }
    if(is_sorted(StackA))
    {
        // exit(1);
    }
    ft_print(StackA);
    ft_putstr("\n-----------------!!!!1!!!!-----------------\n");
    algo_sort(&StackA);
    // ft_putstr("\n-----------------!!!!2!!!!-----------------\n");
    // ft_print(StackA);
    // // ft_putstr("\n-----------------!!!!3!!!!-----------------\n");
    // // sa(&StackA);
    // // ft_print(StackA);
    free_stack(StackA);
    return 0;
}
