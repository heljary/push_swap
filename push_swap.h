/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:34:22 by heljary           #+#    #+#             */
/*   Updated: 2025/02/20 18:41:04 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct pushswap
{
	int				number;
	struct pushswap	*next;
}					t_push_swap;

// opration function

// swap
void				sa(t_push_swap **stack_a, char *s);
void				sb(t_push_swap **stack_b, char *s);
void				ss(t_push_swap **stack_a, t_push_swap **stack_b);

// push
void				pa(t_push_swap **stack_a, t_push_swap **stack_b);
void				pb(t_push_swap **stack_a, t_push_swap **stack_b);

// rotate

void				ra(t_push_swap **stack_a, char *s);
void				rb(t_push_swap **stack_b, char *s);
void				rr(t_push_swap **stack_a, t_push_swap **stack_b);

// reverse rotate

void				rra(t_push_swap **stack_a, char *s);
void				rrb(t_push_swap **stack_b, char *s);
void				rrr(t_push_swap **stack_a, t_push_swap **stack_b);

// free
void				ft_free_split(char **tab);

// utils fynction
void				ft_putstr(char *str);
long				ft_atoi(const char *str, char **adress1,
						t_push_swap *adress2);
void				function_exit(char **adress, t_push_swap *stack);
char				**ft_split(char const *s, char c);
char				*is_validnumber(char *str);
int					is_dupliacte(t_push_swap *root, int value);
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					ft_strlen(const char *str);
int					stack_size(t_push_swap *head);
void				insert_first(t_push_swap **head, int value);
void				insert_last(t_push_swap **head, int value);
void				free_stack(t_push_swap *stack);
int					is_sorted(t_push_swap *head);
// fun sorting algo
int					*sort_array(t_push_swap **stack_a);
void				algorithm_sort(t_push_swap **stack_a,
						t_push_swap **stack_b);
void				algo_sort_small_numbers(t_push_swap **stack_a);
void				algo_sort_fournumbers(t_push_swap **stack_a,
						t_push_swap **stack_b);
void				algo_sort_fivenumbers(t_push_swap **stack_a,
						t_push_swap **stack_b);

void				pb_rb(t_push_swap **stack_a, t_push_swap **stack_b);

#endif