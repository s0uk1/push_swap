/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:45:27 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/12 18:43:27 by ssabbaji         ###   ########.fr       */
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

t_stack *allocate_node(t_stack **node)
{
	*node = malloc(sizeof(t_stack));
	if (!*node)
		return (NULL);
	return (*node);
}

void	new_node(t_stack **node, int val)
{
	t_stack	*new;
	t_stack *tmp;
	
	if (!*node)
	{
		node = allocate_node(node);
		(*node)->next = NULL;
		(*node)->val = val;
	}
	tmp = *node;
	while (tmp->next != NULL)
	{
		
	}
}

void	new_stack(t_stack **a, int *num_list)
{
	int	i;
	t_stack	*save;
	t_stack *save_clone;

	i = 0;
	while (arguments[i])
	{
		*a = stack_addback(*a, num_list[i]);
		i++;
	}
	save = *a;
	while (save)
	{
		save_clone = *a;
		while (save_clone)
		{
			if (save->data > save_clone->data)
				save_clone->index++;
			save_clone = save_clone->next;
		}
		save = save->next;
	}
}

t_stack *stack_addback(t_stack *stack, int val)
{
	t_stack *node;
	t_stack *stack_save;

	node = new_node(val);
	if (stack == NULL)
		return (node);
	stack_save = stack;
	while (stack_save->next != NULL)
		stack_save = stack_save->next;
	stack_save->next = node;
	node->index = 0;
	return (stack);
}

t_stack	*new_node(int val)
{
	t_stack *node;
	node = allocate_node(&node);
	node->val = val;
	node->index = 0;
}
