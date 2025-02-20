/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_a_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:54:54 by heljary           #+#    #+#             */
/*   Updated: 2025/02/20 18:35:19 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
		return ;
	write(1, str, len);
}

long	ft_atoi(const char *str, char **adress1, t_push_swap *adress2)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		function_exit(adress1, adress2);
	return (result * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
	{
		return (0);
	}
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
