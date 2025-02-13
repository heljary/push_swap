#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

typedef struct pushswap
{
    int number;
    struct pushswap *next;
} push_swap;

// opration function

//swap
void    sa(push_swap  **stack_a,char *s);
void    sb(push_swap  **stack_b,char *s);
void    ss(push_swap  **stack_a,push_swap  **stack_b);

//push
void    pa(push_swap **stack_a, push_swap **stack_b);
void    pb(push_swap **stack_a, push_swap **stack_b);

//rotate

void    ra(push_swap  **stack_a,char *s);
void    rb(push_swap  **stack_b,char *s);
void    rr(push_swap  **stack_a,push_swap  **stack_b);

//reverse rotate

void    rra(push_swap  **stack_a,char *s);
void    rrb(push_swap  **stack_b,char *s);
void    rrr(push_swap  **stack_a,push_swap  **stack_b);


// free
void	ft_free_split(char **tab);

//utils fynction
void	ft_putchar(char c);
void	ft_putstr(char *str);
long    ft_atoi(const char *str);
void	ft_putnbr(int n);
void    function_exit();
char	**ft_split(char const *s, char c);
char    *is_validnumber(char *str);
int     is_dupliacte(push_swap *root ,int value);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int     ft_strlen(const char *str);
int     stacka_size(push_swap *head);
void    insert_first(push_swap **head,int value);
void    insert_last(push_swap **head,int value);
void    free_stack(push_swap *stack);
void    ft_print(push_swap *StackA);
//fun sorting algo

void    algo_push_a_in_b(push_swap **stack_a,push_swap **stack_b);
void    algorithm_sort(push_swap **stack_a,push_swap **stack_b);

//,push_swap **stack_b
#endif