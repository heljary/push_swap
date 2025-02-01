#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct pushswap
{
    int number;
    struct pushswap *next;
} push_swap;

void	ft_putchar(char c);
void	ft_putstr(char *str);
long	    ft_atoi(const char *str);
void	ft_putnbr(int n);
void function_exit();
char	**ft_split(char const *s, char c);
char *is_validnumber(char *str);
int  is_dupliacte(push_swap *root ,int value);

#endif