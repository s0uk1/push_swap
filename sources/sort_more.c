/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:08:01 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 13:46:03 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sm_helper(t_stack **head)
{
	int	size;
	int	biggest;
	int	x;

	x = 0;
	biggest = check_biggest(*head);
	size = stack_size(*head);
	if (indexx_of(*head, biggest) <= size / 2)
		x = 1;
	while ((*head)->val != biggest)
	{
		if (x)
			rb(1);
		else
			rrb(1);
	}
	pa(1);
}

void	sort_more(t_stack **b)
{
	while (*get_address('b'))
		sm_helper(b);
}

int	hold_vals(t_stack *iter, int *hold_first, int *hold_second, int div)
{
	static int	var;
	static int	div_val;

	*hold_first = -1;
	if (div)
		div_val = 20;
	else
		div_val = 45;
	if (check_smallest(*get_address('a')) >= var)
		var += div_val;
	while (iter)
	{
		if (iter->val < var)
			if (*hold_first == -1)
				*hold_first = iter->val;
		if (iter->val < var)
			*hold_second = iter->val;
		iter = iter->next;
	}
	return (var);
}

void	push_smol(t_stack **head, int hold, int div)
{
	int	x;
	int	div_val;

	x = 0;
	if (indexx_of(*head, hold) <= stack_size(*head) / 2)
		x = 1;
	while ((*head)->val != hold)
	{
		if (x)
			ra(1);
		else
			rra(1);
	}
	pb(1);
	if (div)
		div_val = 10;
	else
		div_val = 23;
}

void	push_chunk(t_stack **head, int div)
{
	int	hold_first;
	int	hold_second;
	int	size;

	while (*head)
	{
		hold_vals(*head, &hold_first, &hold_second, div);
		size = stack_size(*head);
		if (size - indexx_of(*head, hold_second) < indexx_of(*head, hold_first))
			push_smol(head, hold_second, div);
		else
			push_smol(head, hold_first, div);
	}
}
