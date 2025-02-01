#include "push_swap.h"

void inserttoend(push_swap **Node,int value)
{
    push_swap *newnode = malloc(sizeof(push_swap));
    if(!newnode)
    {
        return;
    }
    newnode -> next = NULL;
    newnode -> number = value;
    if(*Node == NULL)
    {
        *Node = newnode;
        return;
    }
    push_swap *current = *Node;
    while (current -> next)
    {
        current = current -> next;
    }
    current -> next = newnode;
}


void ft_swap(push_swap *StackA)
{


    while (StackA != NULL)
    {
        ft_putnbr(StackA -> number);
        ft_putchar('\n');
        StackA = StackA -> next;
    }
}

int main(int ac, char **av)
{
    push_swap *StackA = NULL;
    int i = 1;
    if(ac >= 2)
        while (av[i])
        {  
            if(!is_validnumber(av[i]))
                function_exit();

            else if(is_dupliacte(StackA,ft_atoi(av[i])))
                function_exit();

            else if(ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
                function_exit();

            inserttoend(&StackA,ft_atoi(av[i]));
            i++;
        }

    ft_swap(StackA);
    push_swap *temp;
    while (StackA != NULL)
    {
        temp = StackA;
        StackA = StackA -> next;
        free(temp);
    }
    
    return 0;
}