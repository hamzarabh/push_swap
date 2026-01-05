/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opera_of_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:51:38 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 11:25:03 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to(t_push_swap **stack_1, t_push_swap **stack_2, char s_name)
{
	t_push_swap	*tmp;

	if (!stack_1 || !*stack_1)
		return ;
	tmp = (*stack_1)->next;
	(*stack_1)->next = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = tmp;
	if (s_name == 'a')
		write(1, "pa\n", 3);
	if (s_name == 'b')
		write(1, "pb\n", 3);
}

void	ft_swap(t_push_swap **stack, char stack_name)
{
	t_push_swap	*tmp2;

	if (!stack || !*stack)
		return ;
	tmp2 = (*stack)->next;
	(*stack)->next = tmp2->next;
	tmp2->next = *stack;
	*stack = tmp2;
	if (stack_name == 'a')
		write(1, "sa\n", 3);
	if (stack_name == 'b')
		write(1, "sb\n", 3);
}

void	ft_rotate(t_push_swap **stack, char stack_name)
{
	t_push_swap	*tmp1;
	t_push_swap	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	while (tmp1->next)
		tmp1 = tmp1->next;
	(*stack)->next = NULL;
	tmp1->next = *stack;
	*stack = tmp2;
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	if (stack_name == 'b')
		write(1, "rb\n", 3);
}

void	ft_rev_rotate(t_push_swap **stack, char stack_name)
{
	t_push_swap	*tmp1;
	t_push_swap	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	tmp2 = *stack;
	while (tmp1->next)
		tmp1 = tmp1->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp1->next = *stack;
	*stack = tmp1;
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	if (stack_name == 'b')
		write(1, "rrb\n", 4);
}
