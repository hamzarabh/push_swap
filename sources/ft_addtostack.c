/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtostack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:42:42 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 10:49:55 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_push_swap	*ft_addnew(int nb)
{
	t_push_swap	*new;

	new = malloc(sizeof(t_push_swap));
	if (!new)
		return (NULL);
	new->num = nb;
	new->index = 0;
	new->next = NULL;
	new->next_hash = NULL;
	return (new);
}

void	ft_addtostack(t_push_swap **lst, int nb)
{
	t_push_swap	*new;
	t_push_swap	*copy;

	if (!lst)
		return ;
	new = ft_addnew(nb);
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	while (copy->next)
		copy = copy->next;
	copy->next = new;
}
