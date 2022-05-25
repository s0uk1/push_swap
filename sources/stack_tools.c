/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:10:38 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/24 17:34:48 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_everything(int XD)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = *get_address('a');
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = *get_address('b');
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (XD);
}


int	new_node(t_stack **stack, int val)
{
	t_stack	*new;
	t_stack	*tmp;
	t_stack	*iter;
	int fail = 0;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->val = val;
	new->next = NULL;
	if (!(*stack))
	{
		*stack = new;
		return (69);
	}
	tmp = *stack;
	iter = tmp;
	while (iter)
	{
		if (iter->val == val)
			fail = 1;
		iter = iter->next;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	if (fail)
		return (0);
	return (69);
}

int	ft_fill_list(char **av, t_stack **a)
{
	int		i;

	i = 0;
	*a = NULL;
	while (av[i])
		if (!new_node(a, atoi(av[i++])))
			return (0);
	return (1);
}
