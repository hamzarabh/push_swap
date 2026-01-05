/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:35:53 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 11:06:35 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_indexing(t_push_swap **stack)
{
	t_push_swap	*tmp1;
	t_push_swap	*tmp2;

	if (!stack || !(*stack))
		return ;
	tmp1 = *stack;
	while (tmp1)
	{
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp2->num < tmp1->num)
				tmp1->index++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	ft_sort_three(t_push_swap **stack)
{
	int	n2;
	int	n3;

	n2 = (*stack)->next->index;
	n3 = (*stack)->next->next->index;
	if ((*stack)->index > n2 && n2 < n3 && (*stack)->index < n3)
		ft_swap(stack, 'a');
	else if ((*stack)->index > n2 && n2 > n3)
	{
		ft_swap(stack, 'a');
		ft_rev_rotate(stack, 'a');
	}
	else if ((*stack)->index > n2 && n2 < n3)
		ft_rotate(stack, 'a');
	else if ((*stack)->index < n2 && n2 > n3 && (*stack)->index < n3)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if ((*stack)->index < n2 && n2 > n3 && (*stack)->index > n3)
		ft_rev_rotate(stack, 'a');
}

void	ft_sort_five(t_push_swap **stack_a, t_push_swap **stack_b, int size)
{
	int	copy_size;

	copy_size = size;
	while (copy_size--)
	{
		if (size == 5 && ((*stack_a)->index == 0 || (*stack_a)->index == 1))
			ft_push_to(stack_a, stack_b, 'b');
		else if (size == 4 && ((*stack_a)->index == 0))
			ft_push_to(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
	}
	ft_sort_three(stack_a);
	if (size == 5)
	{
		if ((*stack_b)->index < (*stack_b)->next->index)
			ft_swap(stack_b, 'b');
		ft_push_to(stack_b, stack_a, 'a');
		ft_push_to(stack_b, stack_a, 'a');
	}
	else if (size == 4)
		ft_push_to(stack_b, stack_a, 'a');
}

void	ft_push_swap(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_swap(stack_a, 'a');
	else if (size == 3)
	{
		ft_indexing(stack_a);
		ft_sort_three(stack_a);
	}
	else if (size <= 5)
	{
		ft_indexing(stack_a);
		ft_sort_five(stack_a, stack_b, size);
	}
	else
	{
		ft_indexing(stack_a);
		ft_push_to_b(stack_a, stack_b);
		ft_push_to_a(stack_a, stack_b);
	}
}

//###### Radix Sort (Binary) #####

// void	ft_t_push_swap(t_push_swap **stack_a, t_push_swap **stack_b)
// {
// 	int	size;
// 	int	bit;
// 	int	index;
// 	int	group1;
// 	int group2;
// 	int	max_bits;

// 	bit = 0;
// 	ft_indexing(stack_a);
// 	size = ft_lstsize(*stack_a);
// 			max_bits = 0;
//      while ((size - 1) >> max_bits)
//          max_bits++;
// 	while (ft_check_sort(*stack_a) == 0 || *stack_b != NULL)
// 	{
// 		size = ft_lstsize(*stack_a);
// 		while (size--)
// 		{
// 			index = (*stack_a)->index;
// 			group1 = (index >> bit) & 1;
// 			group2 = (index >> (bit+1)) & 1;

// 			if (group1 == 0 )
// 				ft_push_to(stack_a, stack_b, 'b');
// 			else
// 				ft_rotate(stack_a, 'a');
// 		}
// 		bit++;
// 		size = ft_lstsize(*stack_b);
// 		if(bit < max_bits )
// 		{
// 		while (size--)
// 		{
// 			index = (*stack_b)->index;
// 			group1 = (index >> bit) & 1;
// 			group2 = (index >> (bit+1)) & 1;

// 			if (group1 == 1 )
// 				ft_push_to(stack_b, stack_a, 'a');
// 			else
// 				ft_rotate(stack_b, 'b');
// 		}
// 		}
// 		else
// 		{
// 		while (*stack_b)
// 		{
// 			ft_push_to(stack_b, stack_a, 'a');
// 		}
// 		}
// 	}
// }
