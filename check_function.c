/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:22:45 by heljary           #+#    #+#             */
/*   Updated: 2025/02/23 17:04:04 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*is_validnumber(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (NULL);
	}
	if ((str[0] == '-' || str[0] == '+') && str[1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
		}
		else
			return (NULL);
		i++;
	}
	return (str);
}

int	is_dupliacte(t_push_swap *root, int value)
{
	while (root != NULL)
	{
		if (root->number == value)
			return (1);
		root = root->next;
	}
	return (0);
}

void	function_exit(char **adress, t_push_swap *stack)
{
	ft_putstr("Error\n");
	if (stack)
		free_stack(stack);
	if (adress)
		ft_free_split(adress);
	exit(1);
}

int	is_sorted(t_push_swap *head)
{
	int	num;

	if (head == NULL)
	{
		return (1);
	}
	num = head->number;
	head = head->next;
	while (head != NULL)
	{
		if (num > head->number)
		{
			return (0);
		}
		num = head->number;
		head = head->next;
	}
	return (1);
}
