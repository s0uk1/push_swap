/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:02:32 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 13:59:58 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*rra_done(t_stack **head)
{
	int		val;
	t_stack	*current;
	t_stack	*next;

	current = *head;
	next = current->next;
	while (next != NULL)
	{
		current = next;
		next = current->next;
	}
	val = current->val;
	del_last(head);
	lst_addfr(head, val);
	return (*head);
}

void	rra(int flag)
{
	t_stack	**st;

	st = get_address('a');
	if (flag)
		ft_putstr("rra\n");
	rra_done(st);
}

t_stack	*rrb_done(t_stack **head)
{
	int		val;
	t_stack	*current;
	t_stack	*next;

	current = *head;
	next = current->next;
	while (next != NULL)
	{
		current = next;
		next = current->next;
	}
	val = current->val;
	del_last(head);
	lst_addfr(head, val);
	return (*head);
}

void	rrb(int flag)
{
	t_stack	**st;

	st = get_address('b');
	if (flag)
		ft_putstr("rrb\n");
	rrb_done(st);
}
