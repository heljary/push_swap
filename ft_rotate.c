/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:57:50 by heljary           #+#    #+#             */
/*   Updated: 2025/02/15 17:06:23 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap **stack_a, char *s)
{
	t_push_swap	*nxt;
	t_push_swap	*first;

	if (*stack_a == NULL)
		return ;
	if (stack_size(*stack_a) == 1)
		return ;
	nxt = *stack_a;
	while (nxt->next != NULL)
		nxt = nxt->next;
	first = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	nxt->next = first;
	first->next = NULL;
	ft_putstr(s);
}

void	rb(t_push_swap **stack_b, char *s)
{
	t_push_swap	*head;
	t_push_swap	*first;

	if (*stack_b == NULL)
		return ;
	if (stack_size(*stack_b) == 1)
		return ;
	head = (*stack_b);
	while (head->next != NULL)
		head = head->next;
	first = (*stack_b);
	*stack_b = (*stack_b)->next;
	head->next = first;
	first->next = NULL;
	ft_putstr(s);
}

void	rr(t_push_swap **stack_a, t_push_swap **stack_b)
{
	ra(stack_a, NULL);
	rb(stack_b, NULL);
	ft_putstr("rr\n");
}
