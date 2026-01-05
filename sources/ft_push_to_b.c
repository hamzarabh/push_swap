/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:22:28 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 11:00:09 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_size(t_push_swap *stack)
{
	int	size;

	if (!stack)
		return (-1);
	size = ft_lstsize(stack);
	if (size <= 100)
		return (15);
	else
		return (35);
}

void	ft_push_to_b(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int	i;
	int	range;

	if (!stack_a || !(*stack_a))
		return ;
	range = ft_chunk_size(*stack_a);
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_push_to(stack_a, stack_b, 'b');
			ft_rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			ft_push_to(stack_a, stack_b, 'b');
			i++;
		}
		else
			ft_rotate(stack_a, 'a');
	}
}
