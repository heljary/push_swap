/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:58:17 by heljary           #+#    #+#             */
/*   Updated: 2025/02/15 17:06:06 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap **stack_a, char *s)
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
	ft_putstr(s);
}

void	rrb(t_push_swap **stack_b, char *s)
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
	ft_putstr(s);
}

void	rrr(t_push_swap **stack_a, t_push_swap **stack_b)
{
	rra(stack_a, NULL);
	rrb(stack_b, NULL);
	ft_putstr("rrr\n");
}
