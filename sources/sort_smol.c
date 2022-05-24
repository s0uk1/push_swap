/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:59:26 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 15:48:09 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_nnode(int index, t_stack **head)
{
	t_stack	*curr;
	int		c;

	c = 0;
	curr = *head;
	while (curr != NULL)
	{
		if (c == index)
			return (curr->val);
		c++;
		curr = curr->next;
	}
	return (0);
}

void	sort_two(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (tmp->val > tmp->next->val)
		sa(1);
}

void	sort_three(t_stack **head)
{
	int	first;
	int	second;
	int	third;

	first = get_nnode(0, head);
	second = get_nnode(1, head);
	third = get_nnode(2, head);
	if (first > second && second < third && first < third)
		sa(1);
	else if (first > second && second > third && first > third)
	{
		sa(1);
		rra(1);
	}
	else if (first > second && first > third && second < third)
		ra(1);
	else if (first < second && third > first && second > third)
	{
		sa(1);
		ra(1);
	}
	else if (first > third && second > first && second > first)
		rra(1);
}

void	sv_helper(t_stack **head)
{
	int	x;
	int	size;
	int	smallest;

	x = 0;
	smallest = 0;
	size = stack_size(*head);
	if (indexx_of(*head, smallest) < size / 2)
		x = 1;
	smallest = check_smallest(*head);
	size = stack_size(*head);
	while ((*head)->val != smallest)
	{
		if (!x)
			ra(1);
		else
			rra(1);
	}
	pb(1);
}

void	sort_five(t_stack **a)
{
	while (stack_size(*a) != 3)
		sv_helper(a);
	sort_three(a);
	while (*get_address('b'))
		pa(1);
}
