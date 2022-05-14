/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:08:05 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/14 14:05:19 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	new_node(t_stack **stack,int val)
{
	t_stack *new;
	t_stack *tmp;
	int c;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = val;
	new->next = NULL;
	if(!(*stack))
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->val == val)
			exit(printf("dup"));
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	ft_fill_list(t_stack **st_a,char **av)
{
	int		i;
	int 	c;
	t_stack	*a;

	i = 0;
	a = NULL;
	while (av[i])
		new_node(&a, atoi(av[i++]));
	c = stack_size(a);
	*st_a = a;
}
