/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:46 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 12:32:04 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_fnode(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->next;
	free (tmp);
}

void	del_last(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	free(node);
}

void	lst_addfr(t_stack **head, int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = val;
	new->next = *head;
	*head = new;
}
