/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:08:01 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 11:00:00 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_prepare_stack_b(t_push_swap **stack, int max, int size)
{
	t_push_swap	*tmp1;
	int			pos;

	pos = 0;
	tmp1 = *stack;
	while (tmp1)
	{
		if (tmp1->index == max)
			break ;
		pos++;
		tmp1 = tmp1->next;
	}
	if (pos < (size / 2))
		while (pos--)
			ft_rotate(stack, 'b');
	else
	{
		pos = (size - pos);
		while (pos--)
			ft_rev_rotate(stack, 'b');
	}
}

void	ft_push_to_a(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int		max_num;
	int		size;

	if (!stack_b || !(*stack_b))
		return ;
	max_num = (ft_lstsize(*stack_b) - 1);
	while (*stack_b)
	{
		if ((*stack_b)->index == max_num)
		{
			ft_push_to(stack_b, stack_a, 'a');
			max_num--;
		}
		else
		{
			size = ft_lstsize(*stack_b);
			ft_prepare_stack_b(stack_b, max_num, size);
		}
	}
}
