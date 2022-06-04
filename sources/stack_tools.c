/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:10:38 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/27 13:55:53 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	freeall(int XD)
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

void	loop_last(t_stack **tmp, t_stack **new)
{
	while ((*tmp)->next)
		*tmp = (*tmp)->next;
	(*tmp)->next = *new;
}

int	check_dup(t_stack *iter, int val, int *fail)
{
	while (iter)
	{
		if (iter->val == val)
			*fail = 1;
		iter = iter->next;
	}
	return (*fail);
}

int	new_node(t_stack **stack, int val)
{
	int		fail;
	t_stack	*new;
	t_stack	*tmp;
	t_stack	*iter;

	fail = 0;
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
	fail = check_dup(iter, val, &fail);
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
