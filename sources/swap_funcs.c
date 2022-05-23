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

t_stack	*sb_done(t_stack **head)
{
	int	tmp;

	tmp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = tmp;
	return (*head);
}

void	sb(int flag)
{
	t_stack	**st;

	st = get_address('b');
	if (flag)
		ft_putstr("sb\n");
	*st = sb_done(st);
}

t_stack	*sa_done(t_stack **head)
{
	int	tmp;

	tmp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = tmp;
	return (*head);
}

void	sa(int flag)
{
	t_stack	**st;

	st = get_address('a');
	if (flag)
		ft_putstr("sa\n");
	*st = sa_done(st);
}

void	ss(void)
{
	ft_putstr("ss\n");
	sa(0);
	sb(0);
}
