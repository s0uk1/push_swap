/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:20:29 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 13:49:10 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	check_smallest(t_stack *head)
{
	int	min;

	min = head->val;
	while (head != NULL)
	{
		if (head->val < min)
			min = head->val;
		head = head->next;
	}
	return (min);
}

int	check_biggest(t_stack *head)
{
	int	max;

	max = head->val;
	while (head != NULL)
	{
		if (head->val > max)
			max = head->val;
		head = head->next;
	}
	return (max);
}
