/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:29:57 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 10:58:50 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_digit(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	check_input(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while ((str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i])
			return (0);
	}
	if (count_digit(str) > 10)
		return (0);
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}
