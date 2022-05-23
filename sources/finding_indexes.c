/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_indexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:54:33 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 12:31:30 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexate(t_stack **a)
{
	t_stack	*a_clone;
	t_stack	*head;

	head = *get_address('a');
	while (head)
	{
		head->index = 0;
		a_clone = *a;
		while (a_clone)
		{
			if ((head)->val > a_clone->val)
			{
				head->index++;
			}
			a_clone = a_clone->next;
		}
		head = head->next;
	}
	head = *get_address('a');
	while (head)
	{
		head->val = head->index;
		head = head->next;
	}
}

int	indexx_of(t_stack *head, int val)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		if (head->val == val)
			return (i);
		head = head->next;
		i++;
	}
	return (0);
}
