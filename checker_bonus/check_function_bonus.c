/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:05 by heljary           #+#    #+#             */
/*   Updated: 2025/02/23 16:50:08 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_isalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
