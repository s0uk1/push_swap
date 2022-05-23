/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:10:38 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 13:53:19 by ssabbaji         ###   ########.fr       */
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

void	new_node(t_stack **stack, int val)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = val;
	new->next = NULL;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->val == val)
			error_msg(2, "Error\n", 1);
		tmp = tmp->next;
	}
	tmp->next = new;
}

t_stack	*ft_fill_list(char **av)
{
	int		i;
	t_stack	*a;

	i = 0;
	a = NULL;
	while (av[i])
		new_node(&a, atoi(av[i++]));
	return (a);
}
