/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:09:36 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 10:59:20 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char **strs, t_push_swap **stack_a)
{
	t_push_swap	*tmp;
	int			i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	if (strs)
		free(strs);
	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_creat_stack(int argc, char **argv, t_push_swap **stack_a)
{
	int		i;
	int		j;
	char	**strs;

	i = 1;
	while (i < argc)
	{
		j = 0;
		strs = ft_split(argv[i]);
		if (!strs)
			ft_error(strs, stack_a);
		while (strs[j] != NULL)
		{
			if (check_input(strs[j]) == 0)
				ft_error(&strs[j], stack_a);
			ft_addtostack(stack_a, ft_atol(strs[j]));
			free(strs[j++]);
		}
		free(strs);
		i++;
	}
}
