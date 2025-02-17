/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:42 by heljary           #+#    #+#             */
/*   Updated: 2025/02/17 18:26:29 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	insert_first(stack_b, temp->number);
	free(temp);
}

void	pa(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	insert_first(stack_a, temp->number);
	free(temp);
}
