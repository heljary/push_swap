#include "push_swap.h"

char *is_validnumber(char *str)
{
    int i = 0;
    if(!str)
    {
        return NULL;
    }
    if((str[0] == '-' || str[0] == '+') && str[1] != '\0')
        i++;
    while (str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {}
        else
            return NULL;
        i++;
    }
    return str;
}

int  is_dupliacte(push_swap *root ,int value)
{  
    while (root != NULL)
    {
        if(root -> number == value)
            return 1;

        root = root -> next;
    }
    return 0;
}

void function_exit()
{
	ft_putstr("Error\n");
    exit(1);
}