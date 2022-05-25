/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:27:47 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 14:03:09 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rb_done(t_stack **head)
{
	t_stack	*current;
	t_stack	*tmp;
	t_stack	*fml;

	if (!*head || !(*head)->next)
		return ;
	current = *head;
	tmp = current;
	fml = current->next;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
	}
	current->next = (*head);
	(*head)->next = NULL;
	*head = fml;
}

void	rb(int flag)
{
	t_stack	**st;

	st = get_address('b');
	if (flag)
		ft_putstr("rb\n");
	rb_done(st);
}

void	ra_done(t_stack **head)
{
	t_stack	*current;
	t_stack	*tmp;
	t_stack	*fml;

	if (!*head || !(*head)->next)
		return ;
	current = *head;
	tmp = current;
	fml = current->next;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
	}
	current->next = (*head);
	(*head)->next = NULL;
	*head = fml;
}

void	ra(int flag)
{
	t_stack	**st;

	st = get_address('a');
	if (flag)
		ft_putstr("ra\n");
	ra_done(st);
}

void	rr(void)
{
	ft_putstr("rr\n");
	ra(0);
	rb(0);
}
