/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 10:40:46 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 11:01:47 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_sort(t_push_swap *stack)
{
	int	tmp;

	if (!stack)
		return (-1);
	tmp = stack->num;
	while (stack)
	{
		stack = stack->next;
		if (!stack)
			break ;
		if (stack->num < tmp)
			return (0);
		tmp = stack->num;
	}
	return (1);
}

static void	free_stack(t_push_swap **stack)
{
	t_push_swap	*tmp;

	tmp = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	*stack_a;
	t_push_swap	*stack_b;

	if (argc < 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_creat_stack(argc, argv, &stack_a);
	if (stack_a && ft_is_unique(stack_a) == 0)
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (stack_a)
	{
		if (ft_check_sort(stack_a) == 1)
			return (0);
		ft_push_swap(&stack_a, &stack_b);
		free_stack(&stack_a);
	}
	return (0);
}
// if(ft_check_sort(stack_a) == 1)
// 		printf("##########okokokokokokok###");
// t_push_swap *t;
//  printf("---------------------------\n");
// if(stack_a)
// {
// t = stack_a;
// while (t)
// {
// 	printf("%d\n",t->num);
// 	t = t->next;
// }
// free_stack(&stack_a);
// }