/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:22:10 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 14:09:02 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb_done(t_stack **head)
{
	int	tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = tmp;
}

void	sb(int flag)
{
	t_stack	**st;

	st = get_address('b');
	if (flag)
		ft_putstr("sb\n");
	sb_done(st);
}

void	sa_done(t_stack **head)
{
	int	tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = tmp;
}

void	sa(int flag)
{
	t_stack	**st;

	st = get_address('a');
	if (flag)
		ft_putstr("sa\n");
	sa_done(st);
}

void	ss(void)
{
	ft_putstr("ss\n");
	sa(0);
	sb(0);
}
