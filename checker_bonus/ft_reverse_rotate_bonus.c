/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:51 by heljary           #+#    #+#             */
/*   Updated: 2025/02/17 18:27:01 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_push_swap **stack_a)
{
	t_push_swap	*nxt;
	t_push_swap	*last;

	nxt = *stack_a;
	if (*stack_a == NULL)
		return ;
	if (stack_size(*stack_a) == 1)
		return ;
	while (nxt->next->next != NULL)
		nxt = nxt->next;
	last = nxt->next;
	nxt->next = NULL;
	last->next = (*stack_a);
	(*stack_a) = last;
}

void	rrb(t_push_swap **stack_b)
{
	t_push_swap	*nxt;
	t_push_swap	*last;

	nxt = *stack_b;
	if (*stack_b == NULL)
		return ;
	if (stack_size(*stack_b) == 1)
		return ;
	while (nxt->next->next != NULL)
		nxt = nxt->next;
	last = nxt->next;
	nxt->next = NULL;
	last->next = (*stack_b);
	(*stack_b) = last;
}

void	rrr(t_push_swap **stack_a, t_push_swap **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
