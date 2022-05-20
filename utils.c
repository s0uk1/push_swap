/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:45:27 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/19 13:10:09 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->val > stack_a->next->val)
				return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

