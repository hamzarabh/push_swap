/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:46:58 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 13:07:08 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct push_swap
{
	int					num;
	int					index;
	struct push_swap	*next;
	struct push_swap	*next_hash;
}t_push_swap;

char	**ft_split(char *str);
long	ft_atol(char *a_num);
int		check_input(char *str);
void	ft_addtostack(t_push_swap **lst, int nb);
void	ft_creat_stack(int argc, char **argv, t_push_swap **stack_a);
int		ft_is_unique(t_push_swap *stack_a);
void	ft_push_swap(t_push_swap **stack_a, t_push_swap **stack_b);
int		ft_lstsize(t_push_swap *lst);
void	ft_rev_rotate(t_push_swap **stack, char stack_name);
void	ft_rotate(t_push_swap **stack, char stack_name);
void	ft_swap(t_push_swap **stack, char stack_name);
void	ft_push_to(t_push_swap **stack_1, t_push_swap **stack_2, char s_name);
void	ft_push_to_a(t_push_swap **stack_a, t_push_swap **stack_b);
void	ft_push_to_b(t_push_swap **stack_a, t_push_swap **stack_b);

#endif