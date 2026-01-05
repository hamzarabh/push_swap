/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:25:01 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 10:59:36 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_push_swap *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

static int	ft_check_num_of_lst(t_push_swap **lst, t_push_swap *tmp)
{
	t_push_swap	*copy;

	copy = *lst;
	while (copy)
	{
		if ((copy->num) == (tmp->num))
			return (0);
		copy = copy->next_hash;
	}
	tmp->next_hash = (*lst);
	(*lst) = tmp;
	return (1);
}

int	ft_is_unique(t_push_swap *stack_a)
{
	t_push_swap		**hash_table;
	int				i;
	int				len;
	int				index;

	i = 0;
	len = ft_lstsize(stack_a);
	hash_table = malloc(sizeof(t_push_swap *) * len);
	if (!hash_table)
		return (0);
	while (i < len)
		hash_table[i++] = NULL;
	while (stack_a)
	{
		index = ((stack_a->num) % len + len) % len;
		if (hash_table[index] == NULL)
			hash_table[index] = stack_a;
		else if (ft_check_num_of_lst(&(hash_table[index]), stack_a) == 0)
			return (free(hash_table), 0);
		stack_a = stack_a->next;
	}
	return (free(hash_table), 1);
}
